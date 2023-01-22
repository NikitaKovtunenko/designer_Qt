#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QIntValidator *validator = new QIntValidator(0,99,ui->lineEdit);
    ui->lineEdit->setValidator(validator);
    this->connect(ui->action_Exit,SIGNAL(triggered()),this,SLOT(close()));
    ui->spinBox->setValue(50);
//    QVariant height = ui->widget->pixmap->height();
//    QVariant width = ui->widget->pixmap->width();
//    QString pix_h("Height:"+ height.toString());
//    QString pix_w("Width:" + width.toString());
//    ui->statusbar->showMessage(pix_h+pix_w,0);
    QObject::connect(ui->spinBox,SIGNAL(textChanged(QString)),ui->statusbar,SLOT(showMessage(QString)));



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::myslot(QString str)
{
  int a = str.toInt();
  emit mysignal(a);
}


void MainWindow::on_action_About_triggered()
{
    QMessageBox::about(this,QString("Information!"),QString("version 1/1"));
}

