#ifndef MYPICTURE_H
#define MYPICTURE_H

#include <QWidget>
class MyPicture : public QWidget
{
    Q_OBJECT



    QPixmap *pixmap;
    double scale = 50;


public:
    explicit MyPicture(QWidget *parent = nullptr);

signals:


    // QWidget interface
protected:
    virtual void paintEvent(QPaintEvent *event);

signals:
    void wheelsignal(int);

protected slots:
    void scaleChanged(int a)
    {
        scale = a;
        this->repaint();
    }

    friend class MainWindow;

    // QWidget interface
protected:
    virtual void wheelEvent(QWheelEvent *event);

};



#endif // MYPICTURE_H
