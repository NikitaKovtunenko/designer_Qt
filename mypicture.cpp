#include "mypicture.h"
#include <QPainter>
#include <QDebug>
#include <QWheelEvent>

MyPicture::MyPicture(QWidget *parent)
    : QWidget{parent}
{
  pixmap = new QPixmap;
  pixmap->load(":/Pictures/Images_lab4/WomenAndDog.jpg");
  qDebug() << pixmap;

}

void MyPicture::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap tmp = pixmap->scaled(this->width()*scale/100,this->height()*scale/100,Qt::KeepAspectRatio);
    painter.drawPixmap(0,0,tmp);
}

void MyPicture::wheelEvent(QWheelEvent *event)
{

    int res = event->angleDelta().y()/8/15;

    if(res > 0)
    {
        if(scale < 99)
        {
             ++scale;
            event->accept();

        } else event->ignore();

    } else
    {
        if (scale > 1)
        {
            --scale;
            event->accept();
        }
        else event->ignore();
    }

   emit wheelsignal(scale);
}
