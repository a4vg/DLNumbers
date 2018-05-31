#include <QtGui>
#include "mygraphics.h"

MyGraphics::MyGraphics(QWidget *obj) : QDialog(obj){
    gi = 0;
}

void MyGraphics::paintEvent(QPaintEvent *) {
    QPainter p(this);
    int i;
    char tmp[50];
    strcpy(tmp, "");

    p.setPen(QPen(Qt::black, 5));
    for ( i = 0; i <gi-1; ++i) {
        if(gy[i] > CB_Y + CB_HEIGHT) {

            p.drawPoint(gx[i], gy[i]);
        }
    }

    if (gx[i] == -1) strcpy(tmp, "MOUSE PRESSED");
    else sprintf(tmp, "COORDS ARE - %d , %d", gx[i], gy[i]);

    p.setFont(QFont("Courier", 24));
    p.drawText(MESS_X, MESS_Y, tmp);

    p.setPen(QPen(Qt::black, 3));
    p.setFont(QFont("Arial",24));
    p.drawRect(CB_X, CB_Y, CB_WIDTH, CB_HEIGHT);
    p.drawText(CB_X + BT_X, CB_Y + BT_Y, "Clear");
    p.drawRect(EB_X, EB_Y, EB_WIDTH, EB_HEIGHT);
    p.drawText(EB_X + BT_X, EB_Y + BT_Y, "Exit");
}

void MyGraphics::mouseMoveEvent(QMouseEvent *event) {
    gx[gi] = (event -> x());
    gy[gi] = (event -> y());

    if (gi < N_POINTS - 1) ++gi;
    repaint();
}

void MyGraphics::mousePressEvent(QMouseEvent *event) {
    gx[gi] = (event -> x());
    gy[gi] = (event -> y());
    // Clicked within clear button -> Reset
    if (gx[gi] > CB_X && gx[gi] < CB_X + CB_WIDTH && gy[gi] > CB_Y && gy[gi] < CB_Y + CB_HEIGHT) gi = 0;

    // Clicked within exit button -> Exit
    if (gx[gi] > EB_X && gx[gi] < EB_X + EB_WIDTH && gy[gi] > EB_Y && gy[gi] < EB_Y + EB_HEIGHT) exit(0);
    gx[gi] = -1;
    gy[gi] = -1;
    if(gi < N_POINTS -1) ++gi;
    repaint();
}
