#include "mainwindow.h"
#include "mygraphics.h"
#include <QtGui>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //MyGraphics g; //creando un objeto clase MyGraphics
    //g.resize(500,400);
    //g.show();

    return a.exec();
}
