/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *name;
    QLineEdit *passwd;
    QLabel *lb_name;
    QLabel *lb_passwd;
    QPushButton *reg;
    QPushButton *login;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(421, 305);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        name = new QLineEdit(centralWidget);
        name->setObjectName("name");
        name->setGeometry(QRect(160, 70, 141, 20));
        passwd = new QLineEdit(centralWidget);
        passwd->setObjectName("passwd");
        passwd->setGeometry(QRect(160, 110, 141, 20));
        lb_name = new QLabel(centralWidget);
        lb_name->setObjectName("lb_name");
        lb_name->setGeometry(QRect(90, 70, 54, 12));
        lb_passwd = new QLabel(centralWidget);
        lb_passwd->setObjectName("lb_passwd");
        lb_passwd->setGeometry(QRect(90, 110, 54, 12));
        reg = new QPushButton(centralWidget);
        reg->setObjectName("reg");
        reg->setGeometry(QRect(80, 160, 75, 23));
        login = new QPushButton(centralWidget);
        login->setObjectName("login");
        login->setGeometry(QRect(230, 160, 75, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 421, 20));
        menu = new QMenu(menuBar);
        menu->setObjectName("menu");
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\346\261\237\345\261\261\346\202\246\346\222\255", nullptr));
        lb_name->setText(QCoreApplication::translate("MainWindow", "\347\224\250\346\210\267\345\220\215", nullptr));
        lb_passwd->setText(QCoreApplication::translate("MainWindow", "\345\257\206   \347\240\201", nullptr));
        reg->setText(QCoreApplication::translate("MainWindow", "\346\263\250\345\206\214", nullptr));
        login->setText(QCoreApplication::translate("MainWindow", "\347\231\273\345\275\225", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\347\233\264\346\222\255\347\263\273\347\273\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
