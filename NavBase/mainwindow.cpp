#include "mainwindow.h"
#include "qbuttongroup.h"
#include "ui_mainwindow.h"
#include "navigationssystem.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QRadioButton>
#include <QPainter>
#include <map>
#include <algorithm>
static bool mapLoaded = false;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , navSys(new Navigationssystem)

{

    ui->setupUi(this);
    QPixmap pixmap(":/img/img/map.png");

    ui->label->setPixmap(pixmap);
    ui->label->lower();

    connect(ui->pushButton_new, SIGNAL(clicked()), this, SLOT(on_pushButton_new_clicked()));
    connect(ui->pushButton_show, SIGNAL(clicked()), this, SLOT(on_pushButton1_show_clicked()));
    connect(ui->pushButton_calc, SIGNAL(clicked()), this, SLOT(on_pushButton1_calc_clicked()));
    connect(ui->pushButton_change, SIGNAL(clicked()), this, SLOT(on_pushButton1_change_clicked()));
    connect(ui->pushButton_save, SIGNAL(clicked()), this, SLOT(on_pushButton_save_clicked()));
    connect(ui->pushButton_exit, SIGNAL(clicked()), this, SLOT(on_pushButton_exit_clicked()));
    connect(ui->pushButton_Info, &QPushButton::clicked, this, &MainWindow::onInfoButtonClicked);
    connect(ui->pushButton_Del, &QPushButton::clicked, this, &::MainWindow::on_pushButton_Del_clicked);
    connect(ui->pushButton_network,SIGNAL(clicked()), this, SLOT(displayGraphOnMap()));
    connect(ui->pushButton_route,SIGNAL(clicked()), this, SLOT(routeBetweenPlaces()));
    connect(ui->pushButton_initials,SIGNAL(clicked()), this, SLOT(on_initials()));

}

MainWindow::~MainWindow()
{
    delete ui;
    delete navSys;
}




void MainWindow::onRadioButtonClicked(bool) {
    QRadioButton *clickedButton = qobject_cast<QRadioButton *>(sender());
    if (!clickedButton) return;

    // Temporarily block signals to prevent infinite loops
    clickedButton->blockSignals(true);

    // If the button is already in the list, deselect it and remove it
    if (selectedRadioButtons.contains(clickedButton)) {
        clickedButton->setChecked(false);  // Deselect the button
        selectedRadioButtons.removeAll(clickedButton);  // Remove from list

        // Forcefully unselect and reset visual state
        clickedButton->setAutoExclusive(false);  // Disable auto-exclusive behavior
        clickedButton->setChecked(false);  // Make sure the button is unselected
        clickedButton->setAutoExclusive(true);  // Re-enable exclusive behavior
    } else {
        // Otherwise, add it to the list and select it
        selectedRadioButtons.append(clickedButton);
        clickedButton->setChecked(true);  // Select the button
    }

    // Allow signals again after making changes
    clickedButton->blockSignals(false);

    // Debugging output for selected buttons
    QString debugMessage = "Currently selected buttons:\n";
    for (const auto &button : selectedRadioButtons) {
        debugMessage += button->text() + "\n";
    }
    qDebug() << debugMessage;
}




void MainWindow::on_pushButton_show_clicked()
{
    // 1. Remove all existing radio buttons from the map
    QList<QRadioButton *> radioButtons = ui->label->findChildren<QRadioButton *>();
    for (QRadioButton *button : radioButtons) {
        button->deleteLater();  // Safely delete all existing radio buttons
    }

    // Clear the selected points list and selected radio buttons
    selectedRadioButtons.clear();
    selectedPoints.clear();

    // 2. Iterate through the 'karte' vector to re-add points as radio buttons
    for (const auto &ort : navSys->getKarte()) {
        addRadioButton(ort);
    }

    // 3. Show updated map data in a message box (textual representation)
    QString mapData = QString::fromStdString(navSys->karteAnzeigen());
    QMessageBox::information(this, "Karte anzeigen", mapData);
}

void MainWindow::on_pushButton_calc_clicked()
{
    if (selectedRadioButtons.size() != 2) {
        QMessageBox::warning(this, "Invalid Selection", "Please select exactly two points to calculate the distance.");
        return;
    }

    QList<GPS> selectedPoints;
    for (auto button : selectedRadioButtons) {
        QString name = button->text();
        for (auto &x : navSys->getKarte()) {
            if (x->getName() == name.toStdString()) {
                selectedPoints.push_back(GPS(x->getLatitude(), x->getLongitude()));
            }
        }
    }

    // Calculate the distance between the two selected points
    GPS point1 = selectedPoints[0];
    GPS point2 = selectedPoints[1];

    double distance = calculateDistance(point1, point2);

    // Show the distance in a message box
    QMessageBox::information(this, "Distance", QString("The distance between the selected points is: %1 km").arg(distance));
    clearSelectedRadioButtons();
}
double MainWindow::calculateDistance(const GPS &point1, const GPS &point2) {
    const double R = 6371.0; // Earth radius in kilometers
    double lat1 = qDegreesToRadians(point1.latitude);
    double lon1 = qDegreesToRadians(point1.longitude);
    double lat2 = qDegreesToRadians(point2.latitude);
    double lon2 = qDegreesToRadians(point2.longitude);

    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;

    // Haversine formula
    double a = sin(dlat / 2) * sin(dlat / 2) + cos(lat1) * cos(lat2) * sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return R * c; // Distance in kilometers
}

void MainWindow::on_pushButton_change_clicked()
{
    double latitude = QInputDialog::getDouble(this, "MeinOrt verschieben", "Neuer Breitengrad:", 0, -90, 90, 6);
    double longitude = QInputDialog::getDouble(this, "MeinOrt verschieben", "Neue Längengrad:", 0, -180, 180, 6);

                       navSys->meinOrtVerschieben(latitude, longitude);


}


void MainWindow::on_pushButton_save_clicked()
{
    QStringList options = {"Karte speichern", "Karte laden"};
    bool ok;
    QString choice = QInputDialog::getItem(this, "Speichern/Laden", "Wählen Sie eine Option:", options, 0, false, &ok);

    if (!ok) return;

    if (choice == "Karte speichern") {
        // Ask the user for the file name to save the map
        QString filename = QInputDialog::getText(this, "Speichern", "Geben Sie den Dateinamen ein:", QLineEdit::Normal);
        if (!filename.isEmpty()) {
            navSys->karteSpeichern(filename.toStdString());  // Pass the filename to the save function
            QMessageBox::information(this, "Speichern", "Karte wurde gespeichert!");
        }
    } else if (choice == "Karte laden") {
        // Ask if the user wants to save the current map before loading a new one
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Karte speichern", "Möchten Sie die aktuelle Karte speichern?",
                                      QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);

        if (reply == QMessageBox::Yes) {
            // Ask for the file name to save
            QString filename = QInputDialog::getText(this, "Speichern", "Geben Sie den Dateinamen ein:", QLineEdit::Normal);
            if (!filename.isEmpty()) {
                navSys->karteSpeichern(filename.toStdString());  // Save the current map
                QMessageBox::information(this, "Speichern", "Karte wurde gespeichert!");
            }
        } else if (reply == QMessageBox::Cancel) {
            // Cancel loading if the user doesn't want to save
            return;
        }

        // Load the new map
        QString filename = QInputDialog::getText(this, "Laden nach speichern", "Geben Sie den Dateinamen ein:", QLineEdit::Normal);
        if (!filename.isEmpty()) {
            navSys->karteLaden(filename.toStdString());  // Pass the filename to load the map
            // Reload the radio buttons for the new map
            for (auto ort : navSys->getKarte()) {
                addRadioButton(ort);
            }
            QMessageBox::information(this, "Laden", "Karte wurde geladen!");
        }
    }
}

void MainWindow::on_pushButton_exit_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Programm verlassen", "Möchten Sie das Programm beenden?",
                                                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        QApplication::quit();
    }
}

Pixel MainWindow::mapGPStoPixel(GPS gps) {
    // Calculate xRatio based on longitude range from topLeftGPS to bottomRightGPS
    double xRatio = (gps.longitude - topLeftGPS.longitude) /
                    (bottomRightGPS.longitude - topLeftGPS.longitude);
    xRatio *= 0.95;

    // Calculate yRatio based on latitude range from topLeftGPS to bottomLeftGPS
    double yRatio = (topLeftGPS.latitude - gps.latitude) /
                    (topLeftGPS.latitude - bottomLeftGPS.latitude);
    yRatio*=0.95;
    // Map to pixel space using map dimensions
    int x = static_cast<int>(xRatio * mapWidth);
    int y = static_cast<int>(yRatio * mapHeight);

    return {x, y};
}

GPS MainWindow::mapPixelToGPS(Pixel pixel) {
    // Reverse calculation for longitude (from pixel x to GPS longitude)
    double longitude = topLeftGPS.longitude +
                       (pixel.x / static_cast<double>(mapWidth)) *
                           (bottomRightGPS.longitude - topLeftGPS.longitude);

    // Reverse calculation for latitude (from pixel y to GPS latitude)
    double latitude = topLeftGPS.latitude -
                      (pixel.y / static_cast<double>(mapHeight)) *
                          (topLeftGPS.latitude - bottomLeftGPS.latitude);

    return {latitude, longitude};
}


void MainWindow::addRadioButton(Ort* ort)
{
    // Convert GPS coordinates to pixel position on the map
    Pixel pixel = mapGPStoPixel({ort->getLatitude(), ort->getLongitude()});

    // Create a new radio button
    QRadioButton *radioButton = new QRadioButton(ui->label);

    // Set the text of the radio button
    radioButton->setText(QString::fromStdString(ort->getName()));
    radioButton->setStyleSheet("background-color: transparent; border: none;");

    int buttonRadius = 15;
    int centerX = pixel.x - buttonRadius;
    int centerY = pixel.y - buttonRadius;


    radioButton->setGeometry(centerX, centerY, 70, 30);

    // Assign a property for identification
    radioButton->setProperty("ort_id", ort->getId());

    // Connect the button to the click event
    connect(radioButton, &QRadioButton::clicked, this, &MainWindow::onRadioButtonClicked);

    // Show the button
    radioButton->show();
}

void MainWindow::onInfoButtonClicked()
{
    if (selectedRadioButtons.size() != 1) {
        QMessageBox::warning(this, "No Point Selected", "Please select exactly one point to view its information.");
        return;
    }

    // Retrieve the selected point
    const Ort* selectedPoint = getOrtfromID(findIdByRadioButton(selectedRadioButtons[0]));
    if (!selectedPoint) {
        QMessageBox::warning(this, "Error", "Selected point not found.");
        return;
    }

    // Gather point details
    QString selectedPointInfo = QString(
                                    "Selected Point:\n"
                                    "Name: %1\n"
                                    "ID: %2\n"
                                    "Latitude: %3\n"
                                    "Longitude: %4"
                                    ).arg(QString::fromStdString(selectedPoint->getName()))
                                    .arg(selectedPoint->getId())
                                    .arg(selectedPoint->getLatitude())
                                    .arg(selectedPoint->getLongitude());

    // Gather neighbor details
    QString neighborsInfo;
    if (!selectedPoint->neighbors_id.empty()) {
        neighborsInfo = "Direct Neighbors:\n";
        for (int neighborId : selectedPoint->getNeighbors_id()) {
            const Ort* neighborPoint = getOrtfromID(neighborId);
            if (neighborPoint) {
                double distance = navSys->entfernungBerechnen(selectedPoint->getId(), neighborId);
                neighborsInfo += QString("- Name: %1 (ID: %2) - Distance: %3 km\n")
                                     .arg(QString::fromStdString(neighborPoint->getName()))
                                     .arg(neighborId)
                                     .arg(distance, 0, 'f', 2);
            }
        }
    } else {
        neighborsInfo = "This point has no direct neighbors.";
    }

    // Combine everything in one block
    QString infoText = selectedPointInfo + "\n\n" + neighborsInfo;

    // Display the information
    QMessageBox::information(this, "Point Information", infoText);

    // Clear selected radio buttons
    clearSelectedRadioButtons();
}
GPS MainWindow::getSelectedPoint() const
{
    return selectedPoint;
}
void MainWindow::on_pushButton_Del_clicked()
{
    if (selectedRadioButtons.isEmpty()) {
        QMessageBox::information(this, "No Points Selected", "No points selected to delete.");
        return;
    }

    // Iterate over selected points to delete
    for (const auto &point : selectedRadioButtons) {

        navSys->ortDel(getOrtfromID(findIdByRadioButton(point)));
    }
    QList<QRadioButton *> radioButtons = ui->label->findChildren<QRadioButton *>();
    for (QRadioButton *button : radioButtons) {
        button->deleteLater();
    }
    for(auto ort: navSys->getKarte())
    {
        addRadioButton(ort);
    }


    selectedPoints.clear();
    selectedRadioButtons.clear();
    clearSelectedRadioButtons();
    displayGraphOnMap();
    displayGraphOnMap();
}

void MainWindow::on_initials()
{
    static bool mapLoaded = false; // Static variable to track if the map has been loaded

    if (mapLoaded) {
        // Debug: Map is already loaded, clearing the map
        qDebug() << "Map is already loaded. Clearing the map...";

        // Clear the map if it's already loaded
        clearMap();  // Call the clear function to remove buttons and lines

        mapLoaded = false;  // Reset the mapLoaded flag

        // Debug: Map has been cleared
        qDebug() << "Map cleared.";
    } else {
        // Debug: Loading the map for the first time
        qDebug() << "Loading the map...";

        // Load the map if it hasn't been loaded yet
        navSys->karteLaden("karte.txt");  // Pass the filename to load the map

        // Debug: After loading the map
        qDebug() << "Map loaded. Adding radio buttons for the new map.";

        // Reload the radio buttons for the new map
        for (auto ort : navSys->getKarte()) {
            addRadioButton(ort);  // Add radio buttons to the map
            qDebug() << "Added radio button for Ort: " << ort->getName();
        }

        mapLoaded = true;  // Set the flag to indicate the map is loaded

        // Debug: Radio buttons added
        qDebug() << "All radio buttons added.";
    }
}


void MainWindow::on_pushButton_new_clicked() {
    Ort* newOrt = navSys->ortAnlegen();
    if (newOrt == nullptr) {
        QMessageBox::warning(this, "Fehler", "Ort konnte nicht angelegt werden.");
        return;
    }

    addRadioButton(newOrt);

}

void MainWindow::drawLineBetweenButtons(QRadioButton* button1, QRadioButton* button2, const QColor& lineColor = Qt::red) {
    if (!button1 || !button2) return;

    QRect rect1 = button1->geometry();
    QRect rect2 = button2->geometry();

    // Calculate the left-center points of the buttons
    QPoint startPoint = rect1.topLeft() + QPoint(rect1.width() / 2, rect1.height() / 2);  // Left-center of button 1
    QPoint endPoint = rect2.topLeft() + QPoint(rect2.width() / 2, rect2.height() / 2);    // Left-center of button 2

    // Debugging geometry values
    qDebug() << "Point 1 :" << findIdByRadioButton(button1);
    qDebug() << "Point 2 :" << findIdByRadioButton(button2);
    qDebug() << "Button 1 Rect:" << rect1;
    qDebug() << "Button 2 Rect:" << rect2;
    qDebug() << "Start Point:" << startPoint << "End Point:" << endPoint;

    QPixmap pixmap = ui->label->pixmap(Qt::ReturnByValue);
    if (pixmap.isNull()) {
        // Initialize pixmap if it's null
        pixmap = QPixmap(ui->label->size());
        pixmap.fill(Qt::white); // Background color
        ui->label->setPixmap(pixmap);
    }

    QPainter painter(&pixmap);
    QPen pen(lineColor, 2);  // Use the color passed as an argument
    painter.setPen(pen);
    painter.drawLine(startPoint, endPoint);
    painter.end();

    // Update the label
    ui->label->setPixmap(pixmap);
}


int MainWindow::findIdByRadioButton(QRadioButton* button) {
    if (!button) {
        return -1; // Return -1 if the button is null
    }
    return button->property("ort_id").toInt();
}
QRadioButton* MainWindow::findRadioButtonById(int id) {
    QList<QRadioButton*> radioButtons = ui->label->findChildren<QRadioButton*>();
    for (QRadioButton* button : radioButtons) {
        if (button->property("ort_id").toInt() == id) {
            return button;
        }
    }
    return nullptr;
}

Ort *MainWindow::getOrtfromID(int id)
{
    for(auto& x: navSys->getKarte())
    {
        if (id==x->getId())
        {
            return x;
        }
    }
    return nullptr;
}

void MainWindow::displayGraphOnMap() {
    static bool isGraphDisplayed = false; // Static variable to track graph visibility

    // If the graph is already displayed, clear the map and set the flag to false
    if (isGraphDisplayed) {
        reload_background();

        isGraphDisplayed = false;
        return;
    }



    std::map<int, QRadioButton*> radioButtons;
    QList<QRadioButton *> radiobuttons = ui->label->findChildren<QRadioButton *>();
    for (QRadioButton *button : radiobuttons) {
        button->deleteLater();  // Safely delete all existing radio buttons
    }
    // Add all Orte as radio buttons to the map
    for (const auto& ort : navSys->getKarte()) {
        addRadioButton(ort);
        QRadioButton* radioButton = findRadioButtonById(ort->getId());
        if (radioButton) {
            radioButtons[ort->getId()] = radioButton;
        }
    }

    navSys->createGraph();
    const auto& graph = navSys->getGraph(); // Access the graph
    for (const auto& node : graph) {
        int fromId = node.first;
        const auto& neighbors = node.second;

        QRadioButton* fromButton = radioButtons[fromId];
        if (!fromButton) continue; // Skip if the button is missing

        for (const auto& edge : neighbors) {
            int toId = edge.first;
            QRadioButton* toButton = radioButtons[toId];
            if (toButton) {
                drawLineBetweenButtons(fromButton, toButton);
            }
        }
    }

    // Set the flag to true indicating the graph is now displayed
    isGraphDisplayed = true;
}
void MainWindow::routeBetweenPlaces() {
    // Get the selected radio buttons
    navSys->createGraph();
    QRadioButton* startButton = selectedRadioButtons[0];
    QRadioButton* endButton = selectedRadioButtons[1];

    if (!startButton || !endButton) {
        QMessageBox::warning(this, "Fehler", "Bitte wählen Sie zwei Orte aus.");
        return;
    }

    int startId = findIdByRadioButton(startButton);
    int endId = findIdByRadioButton(endButton);

    std::vector<int> path = navSys->findShortestPath(startId, endId);

    for (size_t i = 0; i < path.size() - 1; ++i) {
        // Find the corresponding radio buttons for the current and next place in the path
        int fromId = path[i];
        int toId = path[i + 1];

        QRadioButton* fromButton = findRadioButtonById(fromId);
        QRadioButton* toButton = findRadioButtonById(toId);

        if (fromButton && toButton) {

            drawLineBetweenButtons(fromButton, toButton, Qt::blue);
        }
    }

    QString message = "Kürzester Pfad:\n";
    double totalDistance = 0.0;
    for (size_t i = 0; i < path.size() - 1; ++i) {
        int fromId = path[i];
        int toId = path[i + 1];
        double distance = navSys->entfernungBerechnen(fromId, toId);
        totalDistance += distance;

        message += QString::fromStdString(getOrtfromID(fromId)->getName()) + " -> ";
    }
    message += QString::fromStdString(getOrtfromID(path.back())->getName());
    message += QString("\nGesamtdistanz: %1 km").arg(totalDistance);

    QMessageBox::information(this, "Route", message);
    clearSelectedRadioButtons();

}
void MainWindow::clearMap() {
    navSys->clearKarte();
    clearSelectedRadioButtons();

    QList<QRadioButton *> radioButtons = ui->label->findChildren<QRadioButton *>();
    for (QRadioButton *button : radioButtons) {
        button->deleteLater();  // Safely delete all existing radio buttons
    }
    RadioButtons.clear();

    reload_background();

}
void MainWindow::clearSelectedRadioButtons() {
    // Clear the selectedRadioButtons list
    selectedRadioButtons.clear();

    // Unselect all radio buttons on the map
    for (auto* radioButton : ui->label->findChildren<QRadioButton*>()) {
        radioButton->setChecked(false);
    }
}

void MainWindow::reload_background()
{
    QPixmap pixmap(":/img/img/map.png");

    ui->label->setPixmap(pixmap);
}

