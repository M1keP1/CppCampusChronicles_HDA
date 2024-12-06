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
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *pushButton_new;
    QPushButton *pushButton_show;
    QPushButton *pushButton_calc;
    QPushButton *pushButton_change;
    QPushButton *pushButton_save;
    QPushButton *pushButton_exit;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(447, 335);
        QFont font;
        font.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font.setPointSize(12);
        font.setBold(true);
        MainWindow->setFont(font);
        MainWindow->setCursor(QCursor(Qt::CrossCursor));
        MainWindow->setWindowOpacity(100000.000000000000000);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setAutoFillBackground(false);

        verticalLayout->addWidget(label);

        pushButton_new = new QPushButton(centralwidget);
        pushButton_new->setObjectName("pushButton_new");

        verticalLayout->addWidget(pushButton_new);

        pushButton_show = new QPushButton(centralwidget);
        pushButton_show->setObjectName("pushButton_show");

        verticalLayout->addWidget(pushButton_show);

        pushButton_calc = new QPushButton(centralwidget);
        pushButton_calc->setObjectName("pushButton_calc");

        verticalLayout->addWidget(pushButton_calc);

        pushButton_change = new QPushButton(centralwidget);
        pushButton_change->setObjectName("pushButton_change");

        verticalLayout->addWidget(pushButton_change);

        pushButton_save = new QPushButton(centralwidget);
        pushButton_save->setObjectName("pushButton_save");

        verticalLayout->addWidget(pushButton_save);

        pushButton_exit = new QPushButton(centralwidget);
        pushButton_exit->setObjectName("pushButton_exit");

        verticalLayout->addWidget(pushButton_exit);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setCursor(QCursor(Qt::CrossCursor));

        verticalLayout->addWidget(label_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 447, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "::::::::::::::::::::::::::::::NavBase Propreitary Systems :::::::::::::::::::::::::::::::::::", nullptr));
        pushButton_new->setText(QCoreApplication::translate("MainWindow", "Add New Location", nullptr));
        pushButton_show->setText(QCoreApplication::translate("MainWindow", "Show All Locations", nullptr));
        pushButton_calc->setText(QCoreApplication::translate("MainWindow", "Calculate Distance", nullptr));
        pushButton_change->setText(QCoreApplication::translate("MainWindow", "Change Home", nullptr));
        pushButton_save->setText(QCoreApplication::translate("MainWindow", "Import / Save", nullptr));
        pushButton_exit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Downlink<---------------------------------------- Sentinel-1B", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
