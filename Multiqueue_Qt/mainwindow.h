#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<sstream>

#include "../Code/MultiQueue.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    //获取当前信息
    void get_status(int status=3,int queue=0);
    void  add_process();
    void addQueue();
    void changeImg();

private:
    Ui::MainWindow *ui;
    //用于记录ui列表list0中各队列列的记录数
    int row_count[3];
    int colume_count[3];
    bool usingpauseimg;              //为了改变pause按钮而加的变量
};

#endif // MAINWINDOW_H
