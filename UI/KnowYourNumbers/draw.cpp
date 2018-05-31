#include "draw.h"
#include "ui_draw.h"
#include <QSpinBox>

draw::draw(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::draw)
{
    ui->setupUi(this);

}

draw::~draw()
{
    delete ui;
}

void draw::on_spinBox_valueChanged(int arg1)
{
    ui -> label_numero -> setText(QString::number(arg1));
}
