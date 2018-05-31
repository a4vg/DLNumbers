#include <QtGui>
#include <QWidget>
#include <QDialog>

#define N_POINTS 1000

// Clear button
#define CB_X 		0
#define CB_Y 		0
#define CB_WIDTH 	200
#define CB_HEIGHT 	50

// Exit button
#define EB_X	    201
#define EB_Y	    0
#define EB_WIDTH    200
#define EB_HEIGHT   50

// Button text offsets
#define BT_X    30
#define BT_Y    30

// Message location
#define MESS_X  30
#define MESS_Y  380

class MyGraphics : public QDialog{
Q_OBJECT
public:
    MyGraphics (QWidget* obj = 0);
    virtual void paintEvent(QPaintEvent *);
    virtual void mouseMoveEvent(QMouseEvent *);
    virtual void mousePressEvent(QMouseEvent*);

private:
    int gx[N_POINTS], gy[N_POINTS];
    int gi;
};
