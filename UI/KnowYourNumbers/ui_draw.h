/********************************************************************************
** Form generated from reading UI file 'draw.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAW_H
#define UI_DRAW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_draw
{
public:
    QFrame *line;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_numero;
    QSpinBox *spinBox;
    QPushButton *clearbutton;
    QPushButton *submitbutton;
    QFrame *drawingspace;
    QLabel *knowyourlogo;

    void setupUi(QDialog *draw)
    {
        if (draw->objectName().isEmpty())
            draw->setObjectName(QStringLiteral("draw"));
        draw->resize(612, 459);
        draw->setStyleSheet(QStringLiteral("background: white"));
        line = new QFrame(draw);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(420, -20, 20, 501));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        label = new QLabel(draw);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(440, 20, 161, 41));
        label_2 = new QLabel(draw);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(440, 100, 111, 16));
        label_numero = new QLabel(draw);
        label_numero->setObjectName(QStringLiteral("label_numero"));
        label_numero->setGeometry(QRect(510, 150, 21, 16));
        spinBox = new QSpinBox(draw);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(490, 210, 48, 24));
        clearbutton = new QPushButton(draw);
        clearbutton->setObjectName(QStringLiteral("clearbutton"));
        clearbutton->setGeometry(QRect(40, 20, 113, 32));
        clearbutton->setStyleSheet(QLatin1String("QPushButton{\n"
"        color: black;\n"
"        background-color: rgb(225, 222, 226);\n"
"        border: none;\n"
"        border-radius: 5%;\n"
"}"));
        submitbutton = new QPushButton(draw);
        submitbutton->setObjectName(QStringLiteral("submitbutton"));
        submitbutton->setGeometry(QRect(240, 20, 113, 32));
        submitbutton->setStyleSheet(QLatin1String("QPushButton{\n"
"        color: white;\n"
"        background-color: rgb(196, 4, 30);\n"
"        border: none;\n"
"        border-radius: 5%;\n"
"}"));
        drawingspace = new QFrame(draw);
        drawingspace->setObjectName(QStringLiteral("drawingspace"));
        drawingspace->setGeometry(QRect(60, 80, 280, 280));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 0));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        drawingspace->setPalette(palette);
        drawingspace->setStyleSheet(QLatin1String("QFrame{\n"
"        background-color: rgba(255, 255, 255, 0);\n"
"        border: 3px solid rgb(181, 0, 23);\n"
"        border-radius: 10%;\n"
"}"));
        drawingspace->setFrameShape(QFrame::StyledPanel);
        drawingspace->setFrameShadow(QFrame::Raised);
        knowyourlogo = new QLabel(draw);
        knowyourlogo->setObjectName(QStringLiteral("knowyourlogo"));
        knowyourlogo->setGeometry(QRect(450, 380, 141, 51));
        knowyourlogo->setStyleSheet(QStringLiteral("background:transparent"));
        knowyourlogo->setPixmap(QPixmap(QString::fromUtf8("KnowYourLogo.png")));
        knowyourlogo->setScaledContents(true);

        retranslateUi(draw);

        QMetaObject::connectSlotsByName(draw);
    } // setupUi

    void retranslateUi(QDialog *draw)
    {
        draw->setWindowTitle(QApplication::translate("draw", "Draw Your Number", nullptr));
        label->setText(QApplication::translate("draw", "<html><head/><body><p>Dibuja en el cuadrado <br>izquierdo</p></body></html>", nullptr));
        label_2->setText(QApplication::translate("draw", "Tu n\303\272mero es:", nullptr));
        label_numero->setText(QApplication::translate("draw", "0", nullptr));
        clearbutton->setText(QApplication::translate("draw", "Clear", nullptr));
        submitbutton->setText(QApplication::translate("draw", "Submit", nullptr));
        knowyourlogo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class draw: public Ui_draw {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAW_H
