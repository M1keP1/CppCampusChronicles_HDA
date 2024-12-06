#include "mainwindow.h"
#include "qbuttongroup.h"
#include "ui_mainwindow.h"
#include "navigationssystem.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QRadioButton>

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


void MainWindow::on_pushButton_new_clicked()
{
    // Call ortAnlegen to get the name and coordinates from the user
    auto place = navSys->ortAnlegen();
    QString name = place.first;
    Coordinates coords = place.second;

    // Validate input (abort if the name is empty or coordinates are invalid)
    if (name.isEmpty() || coords.latitude == 0 || coords.longitude == 0) {
        QMessageBox::warning(this, "Invalid Input", "Please provide valid place details.");
        return;
    }

    // Convert GPS coordinates to pixel position on the map
    Pixel pixel = mapGPStoPixel({coords.latitude, coords.longitude});

    // Check if pixel coordinates are out of bounds
    if (pixel.x < 0 || pixel.y < 0 || pixel.x >= mapWidth || pixel.y >= mapHeight) {
        QString message = QString("The calculated position is out of the map bounds. "
                                  "Please adjust the coordinates.\n"
                                  "Pixel coordinates: (%1, %2)\n"
                                  "Image dimensions: %3 x %4")
                              .arg(pixel.x)
                              .arg(pixel.y)
                              .arg(mapWidth)
                              .arg(mapHeight);

        // Show warning dialog
        QMessageBox::warning(this, "Out of Bounds", message);
        return;
    }

    QRadioButton *radioButton = new QRadioButton(ui->label); // Parent is the QLabel (map)
    radioButton->setText(name); // Set the radio button's text to the place's name
    radioButton->setStyleSheet("background-color: rgba(255, 255, 255, 180); border-radius: 5px;");

    // Position the radio button on the QLabel at the calculated pixel position
    radioButton->setGeometry(pixel.x, pixel.y, 150, 30);

    // Create a new button group for each new radio button
    QButtonGroup *group = new QButtonGroup(this);
    group->addButton(radioButton);

    // Connect the radio button click event to handle multiple selections
    connect(radioButton, &QRadioButton::clicked, this, &MainWindow::onRadioButtonClicked);

    radioButton->show();
}
void MainWindow::onRadioButtonClicked(bool)
{
    QRadioButton *clickedButton = qobject_cast<QRadioButton *>(sender());

    if (!clickedButton) return;

    QString name = clickedButton->text();

    if (selectedRadioButtons.contains(clickedButton)) {
        // Button is already selected, so deselect it
        selectedRadioButtons.removeAll(clickedButton);

        // Remove corresponding GPS point
        auto it = std::find_if(selectedPoints.begin(), selectedPoints.end(),
                               [&name, this](const GPS &point) {
                                   for (auto &x : navSys->getKarte()) {
                                       if (x->getName() == name.toStdString() &&
                                           x->getLatitude() == point.latitude &&
                                           x->getLongitude() == point.longitude) {
                                           return true;
                                       }
                                   }
                                   return false;
                               });

        if (it != selectedPoints.end()) {
            selectedPoints.erase(it);
        }

        // Force visual deselection
        clickedButton->blockSignals(true);
        clickedButton->setChecked(false);
        clickedButton->blockSignals(false);
    } else {
        // Button is not selected, so select it
        selectedRadioButtons.append(clickedButton);

        // Add corresponding GPS point
        for (auto &x : navSys->getKarte()) {
            if (x->getName() == name.toStdString()) {
                selectedPoints.append(GPS(x->getLatitude(), x->getLongitude()));
            }
        }

        // Force visual selection
        clickedButton->blockSignals(true);
        clickedButton->setChecked(true);
        clickedButton->blockSignals(false);
    }

    // Debugging output for selected points
    QString debugMessage = "Currently selected points:\n";
    for (const auto &point : selectedPoints) {
        debugMessage += QString("Latitude: %1, Longitude: %2\n")
                            .arg(point.latitude)
                            .arg(point.longitude);
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
        QString name = QString::fromStdString(ort->getName());
        GPS gps(ort->getLatitude(), ort->getLongitude());
        Pixel pixel = mapGPStoPixel(gps);

        // Create a new radio button
        QRadioButton *radioButton = new QRadioButton(ui->label);
        radioButton->setText(name);
        radioButton->setStyleSheet("background-color: rgba(255, 255, 255, 180); border-radius: 5px;");
        radioButton->setGeometry(pixel.x, pixel.y, 150, 30);

        // Connect the radio button to the toggle functionality
        connect(radioButton, &QRadioButton::toggled, this, [=](bool checked) {
            onRadioButtonClicked(checked); // Handle toggle state
        });

        // Display the radio button on the map
        radioButton->show();
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


void MainWindow::addRadioButton(GPS gps, const QString &label)
{
    Pixel pixel = mapGPStoPixel(gps);
    QRadioButton *newRadioButton = new QRadioButton(label, this);

    newRadioButton->move(pixel.x, pixel.y);
    newRadioButton->setVisible(true);

    newRadioButton->show();
}
void MainWindow::onInfoButtonClicked()
{
    if (selectedPoints.size() != 1) {
        QMessageBox::warning(this, "No Point Selected", "Please select exactly one point to view its information.");
        return;
    }

    // Show information about the selected point
    const GPS &selectedPoint = selectedPoints.first();
    QString infoText = QString("Selected Point Info:\nLatitude: %1\nLongitude: %2")
                           .arg(selectedPoint.latitude)
                           .arg(selectedPoint.longitude);

    QMessageBox::information(this, "Selected Point Info", infoText);
}



GPS MainWindow::getSelectedPoint() const
{
    return selectedPoint;
}
void MainWindow::on_pushButton_Del_clicked()
{
    if (selectedPoints.isEmpty()) {
        QMessageBox::information(this, "No Points Selected", "No points selected to delete.");
        return;
    }

    // Iterate over selected points
    for (const auto &point : selectedPoints) {
        // Remove the corresponding entry from the karte vector in Navigationssystem
        auto karte = navSys->getKarte();
        auto it = std::remove_if(karte.begin(), karte.end(), [&point](auto &ort) {
            return ort->getLatitude() == point.latitude && ort->getLongitude() == point.longitude;
        });

        if (it != karte.end()) {
            karte.erase(it, karte.end());
        }

        // Find and remove corresponding radio buttons
        for (auto *button : selectedRadioButtons) {
            QString buttonText = button->text();

            // Match button text to the point being deleted
            for (auto &x : navSys->getKarte()) {
                if (x->getName() == buttonText.toStdString() &&
                    x->getLatitude() == point.latitude &&
                    x->getLongitude() == point.longitude) {
                    button->deleteLater();  // Remove the button from the map
                }
            }
        }
    }

    // Clear the selected points and radio buttons lists
    selectedPoints.clear();
    selectedRadioButtons.clear();

    QMessageBox::information(this, "Points Deleted", "Selected points have been deleted.");
}
