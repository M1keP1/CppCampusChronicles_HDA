/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
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
        pushButton_save->setGeometry(QRect(100, 10, 121, 31));
        pushButton_exit = new QPushButton(centralwidget);
        pushButton_exit->setObjectName("pushButton_exit");
        pushButton_exit->setGeometry(QRect(10, 10, 80, 31));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(0, 50, 981, 731));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 965, 1218));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName("label");
        label->setMinimumSize(QSize(800, 1200));
        label->setPixmap(QPixmap(QString::fromUtf8(":/img/img/map.png")));
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout->addWidget(label);

        scrollArea->setWidget(scrollAreaWidgetContents);
        pushButton_new = new QPushButton(centralwidget);
        pushButton_new->setObjectName("pushButton_new");
        pushButton_new->setGeometry(QRect(220, 10, 161, 31));
        pushButton_calc = new QPushButton(centralwidget);
        pushButton_calc->setObjectName("pushButton_calc");
        pushButton_calc->setGeometry(QRect(540, 10, 151, 31));
        pushButton_change = new QPushButton(centralwidget);
        pushButton_change->setObjectName("pushButton_change");
        pushButton_change->setGeometry(QRect(690, 10, 121, 31));
        pushButton_Info = new QPushButton(centralwidget);
        pushButton_Info->setObjectName("pushButton_Info");
        pushButton_Info->setGeometry(QRect(810, 10, 91, 31));
        pushButton_show = new QPushButton(centralwidget);
        pushButton_show->setObjectName("pushButton_show");
        pushButton_show->setGeometry(QRect(380, 10, 161, 31));
        pushButton_Del = new QPushButton(centralwidget);
        pushButton_Del->setObjectName("pushButton_Del");
        pushButton_Del->setGeometry(QRect(900, 10, 91, 31));
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
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
