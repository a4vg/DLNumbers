/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
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
    QPushButton *beginbutton;
    QLabel *knowyourlogo;
    QPushButton *instructionbutton;
    QMenuBar *menuBar;
    QMenu *menuKnowYour_s;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(612, 459);
        MainWindow->setStyleSheet(QStringLiteral("background: white;"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        beginbutton = new QPushButton(centralWidget);
        beginbutton->setObjectName(QStringLiteral("beginbutton"));
        beginbutton->setGeometry(QRect(240, 270, 141, 51));
        QFont font;
        font.setFamily(QStringLiteral("Arial Rounded MT Bold"));
        font.setPointSize(18);
        font.setBold(false);
        font.setWeight(50);
        beginbutton->setFont(font);
        beginbutton->setAutoFillBackground(false);
        beginbutton->setStyleSheet(QLatin1String("QPushButton{\n"
"        color: white;\n"
"        background-color: rgb(196, 4, 30);\n"
"        border: none;\n"
"        border-radius: 5%;\n"
"}"));
        beginbutton->setFlat(false);
        knowyourlogo = new QLabel(centralWidget);
        knowyourlogo->setObjectName(QStringLiteral("knowyourlogo"));
        knowyourlogo->setGeometry(QRect(40, 40, 531, 201));
        knowyourlogo->setStyleSheet(QStringLiteral("background:transparent"));
        knowyourlogo->setPixmap(QPixmap(QString::fromUtf8("KnowYourLogo.png")));
        knowyourlogo->setScaledContents(true);
        instructionbutton = new QPushButton(centralWidget);
        instructionbutton->setObjectName(QStringLiteral("instructionbutton"));
        instructionbutton->setGeometry(QRect(260, 330, 101, 32));
        instructionbutton->setStyleSheet(QLatin1String("QPushButton {\n"
"	border: none;\n"
"	background: rgb(209, 209, 209);\n"
"	border-radius: 5%;\n"
"}"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 612, 22));
        menuKnowYour_s = new QMenu(menuBar);
        menuKnowYour_s->setObjectName(QStringLiteral("menuKnowYour_s"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuKnowYour_s->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "KnowYourNumbers", nullptr));
        beginbutton->setText(QApplication::translate("MainWindow", "Begin", nullptr));
        knowyourlogo->setText(QString());
        instructionbutton->setText(QApplication::translate("MainWindow", "Instrucciones", nullptr));
        menuKnowYour_s->setTitle(QApplication::translate("MainWindow", "#s", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
