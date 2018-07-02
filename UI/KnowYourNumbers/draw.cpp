#include "draw.h"
#include "ui_draw.h"
#include <QSpinBox>
#include <QFrame>
#include <QtGui>
#include <QPixmap>

draw::draw(QWidget *parent) : QDialog(parent), ui(new Ui::draw)
{
    ui->setupUi(this);
    connect(ui->clearbutton, SIGNAL(clicked()), this, SLOT(on_clearbutton_clicked()));
    connect(ui->submitbutton, SIGNAL(clicked()), this, SLOT(on_submitbutton_clicked()));

    QPixmap pix(QDir::currentPath() + "/../../../KnowYourLogo.png");
    ui->knowyourlogo->setPixmap(pix);

    //Set drawingspace corners
    dspace_coord[0].setX( ui->drawingspace->geometry().x());
    dspace_coord[0].setY( ui->drawingspace->geometry().y());

    dspace_coord[1].setX( ui->drawingspace->geometry().x() + ui->drawingspace->width());
    dspace_coord[1].setY( ui->drawingspace->geometry().y() + ui->drawingspace->height());

    gi = 0;

}

draw::~draw()
{
    delete ui;
}

void draw::on_spinBox_valueChanged(int arg1)
{
    ui -> label_numero -> setText(QString::number(arg1));
}


void draw::on_clearbutton_clicked()
{
    qDebug() << "Clear button clicked";

    gi = 0;

    gx[gi] = -1;
    gy[gi] = -1;
    if(gi < N_POINTS -1) ++gi;
    repaint();
}

void draw::on_submitbutton_clicked()
{
    //qDebug() << "Submit button clicked";
}

void draw::paintEvent(QPaintEvent *) {
    QPainter p(this);
    int i;
    char tmp[50];
    strcpy(tmp, "");

    p.setPen(QPen(Qt::black, 5));
    for ( i = 0; i <gi-1; ++i) {
        //if (gy[i] > CB_Y + CB_HEIGHT) {  //Just in case
        p.drawPoint(gx[i], gy[i]);
        //}
    }

}

//--------------------

void draw::mouseMoveEvent(QMouseEvent *event) {
    //if (dspace_coord[0].x() < gx[gi] < dspace_coord[1].x()){

        gx[gi] = (event -> x());
        gy[gi] = (event -> y());

    //Avoid drawing outside of drawing_space
    if (dspace_coord[0].x() < gx[gi] && gx[gi] < dspace_coord[1].x()  && dspace_coord[0].y() < gy[gi] && gy[gi] < dspace_coord[1].y()){
        if (gi < N_POINTS - 1) ++gi;
    }
    qDebug() << gi;
    repaint();
}

/*
void draw::mousePressEvent(QMouseEvent *event) {
    gx[gi] = (event -> x());
    gy[gi] = (event -> y());

    // Clicked within clear button -> Reset
    //if (gx[gi] > CB_X && gx[gi] < CB_X + CB_WIDTH && gy[gi] > CB_Y && gy[gi] < CB_Y + CB_HEIGHT) gi = 0;

    // Clicked within exit button -> Exit
    //if (gx[gi] > EB_X && gx[gi] < EB_X + EB_WIDTH && gy[gi] > EB_Y && gy[gi] < EB_Y + EB_HEIGHT) exit(0);

    qDebug() << "press: " << gx[gi];

    gx[gi] = -1;
    gy[gi] = -1;
    if(gi < N_POINTS -1) ++gi;
    repaint();
}
*/

