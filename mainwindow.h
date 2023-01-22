#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

class QString;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
 void mysignal(int);

protected slots:
 void myslot(QString);

private slots:
 void on_action_About_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
