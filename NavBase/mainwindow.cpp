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
        navSys->karteSpeichern();
        QMessageBox::information(this, "Speichern", "Karte wurde gespeichert!");
    } else if (choice == "Karte laden") {
        navSys->karteLaden();
        for(auto ort: navSys->getKarte())
        {
            addRadioButton(ort);
        }
        QMessageBox::information(this, "Laden", "Karte wurde geladen!");
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
    radioButton->setText(QString::fromStdString(ort->getName())); // Set the name of the place as text
    radioButton->setStyleSheet("background-color: rgba(255, 255, 255, 180); border-radius: 5px;");
    radioButton->setGeometry(pixel.x, pixel.y, 150, 30); // Position on the map
    radioButton->setProperty("ort_id", ort->getId());

    connect(radioButton, &QRadioButton::clicked, this, &MainWindow::onRadioButtonClicked);
    radioButton->show();
}

void MainWindow::onInfoButtonClicked()
{
    if (selectedRadioButtons.size() != 1) {
        QMessageBox::warning(this, "No Point Selected", "Please select exactly one point to view its information.");
        return;
    }

    // Show information about the selected point
    const Ort* selectedPoint = getOrtfromID(findIdByRadioButton(selectedRadioButtons[0]));
    QString infoText = QString("Selected Point Info:\nLatitude: %1\nLongitude: %2")
                           .arg(selectedPoint->getLatitude())
                           .arg(selectedPoint->getLongitude());

    QMessageBox::information(this, "Selected Point Info", infoText);
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
        button->deleteLater();  // Safely delete all existing radio buttons
    }
    for(auto ort: navSys->getKarte())
    {
        addRadioButton(ort);
    }


    selectedPoints.clear();
    selectedRadioButtons.clear();

    QMessageBox::information(this, "Points Deleted", "Selected points have been deleted.");
}



void MainWindow::on_pushButton_new_clicked() {
    Ort* newOrt = navSys->ortAnlegen();
    if (newOrt == nullptr) {
        QMessageBox::warning(this, "Fehler", "Ort konnte nicht angelegt werden.");
        return;
    }

    addRadioButton(newOrt);

    std::map<int, double> dist;


    // Calculate distances to existing locations
    for (auto& x : navSys->getKarte()) {
        dist[x->getId()] = navSys->entfernungBerechnen(newOrt->getId(), x->getId());
    }


    // Sort distances
    std::vector<std::pair<int, double>> dist_vec(dist.begin(), dist.end());
    std::sort(dist_vec.begin(), dist_vec.end(), [](const std::pair<int, double>& a, const std::pair<int, double>& b) {
        return a.second < b.second;
    });

    // Find and draw lines to the closest points
    QRadioButton* point1 = nullptr;
    QRadioButton* point2 = nullptr;

    if (dist_vec.size() >= 2) {
        point1 = findRadioButtonById(newOrt->getId());
        point2 = findRadioButtonById(dist_vec[1].first);
    } else if (dist_vec.size() == 1) {
        point1 = findRadioButtonById(dist_vec[1].first);
    }

    // Draw the lines
    if (point1 && point2) {
        drawLineBetweenButtons(point1, point2);
    } else if (point1) {
        QMessageBox::information(this, "Hinweis", "Nur ein Ort verfügbar, Linie wird nicht gezeichnet.");
    }
}

void MainWindow::drawLineBetweenButtons(QRadioButton* button1, QRadioButton* button2) {
    if (!button1 || !button2) return;

    QRect rect1 = button1->geometry();
    QRect rect2 = button2->geometry();

    QPoint startPoint = rect1.center();
    QPoint endPoint = rect2.center();

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
    QPen pen(Qt::red, 2);
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
}
