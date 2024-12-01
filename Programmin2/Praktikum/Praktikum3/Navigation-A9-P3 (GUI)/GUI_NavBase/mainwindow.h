#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "navigationssystem.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_pushButton_new_clicked();

    void on_pushButton_show_clicked();

    void on_pushButton_calc_clicked();

    void on_pushButton_change_clicked();

    void on_pushButton_save_clicked();

    void on_pushButton_exit_clicked();





private:
    Ui::MainWindow *ui;
    Navigationssystem *navSys;
};
#endif // MAINWINDOW_H
