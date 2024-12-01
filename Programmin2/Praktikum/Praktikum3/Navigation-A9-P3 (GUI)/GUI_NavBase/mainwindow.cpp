#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "navigationssystem.h"
#include <QMessageBox>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , navSys(new Navigationssystem)
{
    ui->setupUi(this);


    connect(ui->pushButton_new, SIGNAL(clicked()), this, SLOT(on_pushButton_new_clicked()));
    connect(ui->pushButton_show, SIGNAL(clicked()), this, SLOT(on_pushButton1_show_clicked()));
    connect(ui->pushButton_calc, SIGNAL(clicked()), this, SLOT(on_pushButton1_calc_clicked()));
    connect(ui->pushButton_change, SIGNAL(clicked()), this, SLOT(on_pushButton1_change_clicked()));
    connect(ui->pushButton_save, SIGNAL(clicked()), this, SLOT(on_pushButton_save_clicked()));
    connect(ui->pushButton_exit, SIGNAL(clicked()), this, SLOT(on_pushButton_exit_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete navSys;
}


void MainWindow::on_pushButton_new_clicked()
{
    navSys->ortAnlegen();


}



void MainWindow::on_pushButton_show_clicked()
{
    QString mapData = QString::fromStdString(navSys->karteAnzeigen());
    QMessageBox::information(this, "Karte anzeigen", mapData);
}


void MainWindow::on_pushButton_calc_clicked()
{
    int id1 = QInputDialog::getInt(this, "Entfernung berechnen", "ID des ersten Ortes:");
    int id2 = QInputDialog::getInt(this, "Entfernung berechnen", "ID des zweiten Ortes:");

    double distance = navSys->entfernungBerechnen(id1, id2);

    QMessageBox::information(this, "Entfernung", QString("Die Entfernung beträgt: %1 km").arg(distance));
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


