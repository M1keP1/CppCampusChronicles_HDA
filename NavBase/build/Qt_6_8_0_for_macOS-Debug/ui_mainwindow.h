/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_save;
    QPushButton *pushButton_exit;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *pushButton_new;
    QPushButton *pushButton_calc;
    QPushButton *pushButton_change;
    QPushButton *pushButton_Info;
    QPushButton *pushButton_show;
    QPushButton *pushButton_Del;
    QPushButton *pushButton_network;
    QPushButton *pushButton_route;
    QPushButton *pushButton_initials;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(997, 813);
        QFont font;
        font.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font.setPointSize(12);
        font.setBold(true);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton_save = new QPushButton(centralwidget);
        pushButton_save->setObjectName("pushButton_save");
        pushButton_save->setGeometry(QRect(100, 10, 101, 31));
        pushButton_exit = new QPushButton(centralwidget);
        pushButton_exit->setObjectName("pushButton_exit");
        pushButton_exit->setGeometry(QRect(10, 10, 80, 31));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(0, 50, 981, 731));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 979, 1224));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName("label");
        label->setMinimumSize(QSize(800, 1200));
        label->setPixmap(QPixmap(QString::fromUtf8(":/img/img/map.png")));
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);

        verticalLayout->addWidget(label);

        scrollArea->setWidget(scrollAreaWidgetContents);
        pushButton_new = new QPushButton(centralwidget);
        pushButton_new->setObjectName("pushButton_new");
        pushButton_new->setGeometry(QRect(200, 10, 121, 31));
        pushButton_calc = new QPushButton(centralwidget);
        pushButton_calc->setObjectName("pushButton_calc");
        pushButton_calc->setGeometry(QRect(630, 10, 131, 31));
        pushButton_change = new QPushButton(centralwidget);
        pushButton_change->setObjectName("pushButton_change");
        pushButton_change->setGeometry(QRect(760, 10, 101, 31));
        pushButton_Info = new QPushButton(centralwidget);
        pushButton_Info->setObjectName("pushButton_Info");
        pushButton_Info->setGeometry(QRect(860, 10, 61, 31));
        pushButton_show = new QPushButton(centralwidget);
        pushButton_show->setObjectName("pushButton_show");
        pushButton_show->setGeometry(QRect(320, 10, 121, 31));
        pushButton_Del = new QPushButton(centralwidget);
        pushButton_Del->setObjectName("pushButton_Del");
        pushButton_Del->setGeometry(QRect(920, 10, 71, 31));
        pushButton_network = new QPushButton(centralwidget);
        pushButton_network->setObjectName("pushButton_network");
        pushButton_network->setGeometry(QRect(460, 10, 81, 31));
        pushButton_route = new QPushButton(centralwidget);
        pushButton_route->setObjectName("pushButton_route");
        pushButton_route->setGeometry(QRect(540, 10, 91, 31));
        pushButton_initials = new QPushButton(centralwidget);
        pushButton_initials->setObjectName("pushButton_initials");
        pushButton_initials->setGeometry(QRect(440, 10, 21, 31));
        MainWindow->setCentralWidget(centralwidget);
        scrollArea->raise();
        pushButton_save->raise();
        pushButton_exit->raise();
        pushButton_new->raise();
        pushButton_calc->raise();
        pushButton_change->raise();
        pushButton_Info->raise();
        pushButton_show->raise();
        pushButton_Del->raise();
        pushButton_network->raise();
        pushButton_route->raise();
        pushButton_initials->raise();
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_save->setText(QCoreApplication::translate("MainWindow", "Import / Save", nullptr));
        pushButton_exit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        pushButton_new->setText(QCoreApplication::translate("MainWindow", "Add New Location", nullptr));
        pushButton_calc->setText(QCoreApplication::translate("MainWindow", "Calculate Distance", nullptr));
        pushButton_change->setText(QCoreApplication::translate("MainWindow", "Change Home", nullptr));
        pushButton_Info->setText(QCoreApplication::translate("MainWindow", "Info", nullptr));
        pushButton_show->setText(QCoreApplication::translate("MainWindow", "Show All Locations", nullptr));
        pushButton_Del->setText(QCoreApplication::translate("MainWindow", "Del", nullptr));
        pushButton_network->setText(QCoreApplication::translate("MainWindow", "Network", nullptr));
        pushButton_route->setText(QCoreApplication::translate("MainWindow", "Route", nullptr));
        pushButton_initials->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
