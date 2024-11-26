#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "navigationssystem.h" // Include your Navigationssystem class
#include <QMessageBox>   // For QMessageBox
#include <QInputDialog>  // For QInputDialog

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , navSys(new Navigationssystem)
{
    ui->setupUi(this);

    // Connect clear button
    connect(ui->pushButton_new, &QPushButton::clicked, this, &MainWindow::on_pushButton_new_clicked);

    // Connect show map button
    connect(ui->pushButton1_show, &QPushButton::clicked, this, &MainWindow::on_pushButton1_show_clicked);

    // Connect calculate distance button
    connect(ui->pushButton1_calc, &QPushButton::clicked, this, &MainWindow::on_pushButton1_calc_clicked);

    // Connect move location button
    connect(ui->pushButton1_change, &QPushButton::clicked, this, &MainWindow::on_pushButton1_change_clicked);

    // Connect save/load map button
    connect(ui->pushButton_save, &QPushButton::clicked, this, &MainWindow::on_pushButton_save_clicked);

    // Connect exit button
    connect(ui->pushButton_exit, &QPushButton::clicked, this, &MainWindow::on_pushButton_exit_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete navSys; // Clean up the navigation system
}

// Function to create a new location
void MainWindow::on_pushButton_new_clicked()
{
    QString name = QInputDialog::getText(this, "Neuen Ort anlegen", "Name des Ortes:");
    if (name.isEmpty()) return;

    double latitude = QInputDialog::getDouble(this, "Neuen Ort anlegen", "Breitengrad:", 0, -90, 90, 6);
    double longitude = QInputDialog::getDouble(this, "Neuen Ort anlegen", "Längengrad:", 0, -180, 180, 6);

    navSys->ortAnlegen(name.toStdString(), latitude, longitude);

    QMessageBox::information(this, "Ort angelegt", "Der Ort wurde erfolgreich angelegt!");
}

// Function to display the map
void MainWindow::on_pushButton1_show_clicked()
{
    QString mapData = QString::fromStdString(navSys->karteAnzeigen());
    QMessageBox::information(this, "Karte anzeigen", mapData);
}

// Function to calculate the distance
void MainWindow::on_pushButton1_calc_clicked()
{
    int id1 = QInputDialog::getInt(this, "Entfernung berechnen", "ID des ersten Ortes:");
    int id2 = QInputDialog::getInt(this, "Entfernung berechnen", "ID des zweiten Ortes:");

    double distance = navSys->entfernungBerechnen(id1, id2);

    QMessageBox::information(this, "Entfernung", QString("Die Entfernung beträgt: %1 km").arg(distance));
}

// Function to move MeinOrt
void MainWindow::on_pushButton1_change_clicked()
{
    double latitude = QInputDialog::getDouble(this, "MeinOrt verschieben", "Neuer Breitengrad:", 0, -90, 90, 6);
    double longitude = QInputDialog::getDouble(this, "MeinOrt verschieben", "Neue Längengrad:", 0, -180, 180, 6);

    navSys->meinOrtVerschieben(latitude, longitude);

    QMessageBox::information(this, "MeinOrt verschoben", "MeinOrt wurde erfolgreich verschoben!");
}

// Function to save or load the map
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

// Function to exit the program
void MainWindow::on_pushButton_exit_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Programm verlassen", "Möchten Sie das Programm beenden?",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        QApplication::quit();
    }
}
