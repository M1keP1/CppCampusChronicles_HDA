#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "navigationssystem.h"
#include "qradiobutton.h"
#include "ui_mainwindow.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
struct GPS {
    double latitude;
    double longitude;
    GPS(double lat = 0.0, double lon = 0.0) : latitude(lat), longitude(lon) {}

};

struct Pixel {
    int x;
    int y;
};
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Pixel mapGPStoPixel(GPS gps);
    GPS mapPixelToGPS(Pixel pix);
    void resizeWindowToImage();
    double calculateDistance(const GPS &point1, const GPS &point2);
    GPS getSelectedPoint() const;
    GPS selectedPoint ;

private slots :


    void addRadioButton(GPS gps, const QString& label);
    void on_pushButton_new_clicked();

    void on_pushButton_show_clicked();

    void on_pushButton_calc_clicked();

    void on_pushButton_change_clicked();

    void on_pushButton_save_clicked();

    void on_pushButton_exit_clicked();

    void onInfoButtonClicked();
    void onRadioButtonClicked(bool checked);

    void on_pushButton_Del_clicked();
private:
    GPS topLeftGPS = {55, 6};
    GPS bottomRightGPS = {47, 15};
    GPS bottomLeftGPS = {47, 6};
    int mapWidth = 984;
    int mapHeight = 1360;
    Ui::MainWindow *ui;
    Navigationssystem *navSys;
    QList<QRadioButton *> selectedRadioButtons;  // List to store selected radio buttons
    QList<GPS> selectedPoints;  // Store multiple selected GPS points
};
#endif // MAINWINDOW_H
