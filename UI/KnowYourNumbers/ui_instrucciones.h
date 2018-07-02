/********************************************************************************
** Form generated from reading UI file 'instrucciones.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSTRUCCIONES_H
#define UI_INSTRUCCIONES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_instrucciones
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *instrucciones)
    {
        if (instrucciones->objectName().isEmpty())
            instrucciones->setObjectName(QStringLiteral("instrucciones"));
        instrucciones->resize(421, 142);
        label = new QLabel(instrucciones);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 20, 121, 31));
        QFont font;
        font.setFamily(QStringLiteral("Arial Rounded MT Bold"));
        font.setPointSize(16);
        label->setFont(font);
        label_2 = new QLabel(instrucciones);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 50, 461, 51));
        label_3 = new QLabel(instrucciones);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 90, 361, 21));

        retranslateUi(instrucciones);

        QMetaObject::connectSlotsByName(instrucciones);
    } // setupUi

    void retranslateUi(QDialog *instrucciones)
    {
        instrucciones->setWindowTitle(QApplication::translate("instrucciones", "Dialog", nullptr));
        label->setText(QApplication::translate("instrucciones", "Instrucciones:", nullptr));
        label_2->setText(QApplication::translate("instrucciones", "Dibuja en el area blanca. Cuando el dibujo este listo apreta", nullptr));
        label_3->setText(QApplication::translate("instrucciones", " okay y el programa te dira que numero has escrito.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class instrucciones: public Ui_instrucciones {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSTRUCCIONES_H
