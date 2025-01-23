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
    QRadioButton* findRadioButtonById(int id);
    Ort* getOrtfromID(int id);

private slots :

    void drawLineBetweenButtons(QRadioButton *button1, QRadioButton *button2);
    void addRadioButton( Ort* ort);

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
    int findIdByRadioButton(QRadioButton* button);
    GPS topLeftGPS = {55, 6};
    GPS bottomRightGPS = {47, 15};
    GPS bottomLeftGPS = {47, 6};
    int mapWidth = 984;
    int mapHeight = 1360;
    int nearest_point{};
    Ui::MainWindow *ui;
    Navigationssystem *navSys;
    QList<QRadioButton *> selectedRadioButtons;
    QList<QRadioButton *> RadioButtons;
    QList<GPS> selectedPoints;  // Store multiple selected GPS points
};
#endif // MAINWINDOW_H
