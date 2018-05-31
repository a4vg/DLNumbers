#ifndef DRAW_H
#define DRAW_H

#include <QDialog>

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

private:
    Ui::draw *ui;
};

#endif // DRAW_H
