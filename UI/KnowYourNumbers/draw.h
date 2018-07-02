#ifndef DRAW_H
#define DRAW_H

#include <QDialog>

#define N_POINTS 1000

namespace Ui {
class draw;
}

class draw : public QDialog
{
    Q_OBJECT

public:
    explicit draw(QWidget *parent = 0);
    ~draw();

private slots:
    void on_spinBox_valueChanged(int arg1);
    void on_clearbutton_clicked();
    void on_submitbutton_clicked();
    virtual void mouseMoveEvent(QMouseEvent *);
    virtual void paintEvent(QPaintEvent *);

    //virtual void mousePressEvent(QMouseEvent *);

private:
    Ui::draw *ui;
    int gx[N_POINTS], gy[N_POINTS];
    int gi;
    QPoint dspace_coord[2]; //For upper left corner and lower right corner
};

#endif // DRAW_H
