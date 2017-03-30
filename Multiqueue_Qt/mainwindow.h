#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QString>

#include"../Code/MultiQueue.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    _Enter_ a;

private slots:
    void getMsg(QString msg);
    void getTime(int t);
    void on_pause_clicked();
};

#endif // MAINWINDOW_H
