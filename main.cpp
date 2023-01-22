#include "mainwindow.h"

#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    QTranslator translator1;
    translator1.load(QLocale::system(),"trans","_");
    a.installTranslator(&translator1);
    MainWindow w;
    w.show();
    return a.exec();
}
