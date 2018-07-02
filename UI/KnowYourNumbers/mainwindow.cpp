#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QDir>
#include "instrucciones.h"
#include "draw.h"
#include "mygraphics.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(QDir::currentPath() + "/../../../KnowYourLogo.png");
   //qDebug() << (QDir::currentPath()) + "/../../../KnowYourLogo.png";


    ui->knowyourlogo->setPixmap(pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_beginbutton_clicked()
{
    close();

    //draw d;
    //d.setModal(true);
    //d.exec();


    //MyGraphics g;
    draw g;
    g.setModal(true);
    g.exec();

}

void MainWindow::on_instructionbutton_clicked()
{
    instrucciones instru;     //creando un objeto clase instrucciones
    instru.setModal(true);
    instru.exec();
}
