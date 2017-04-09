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

signals:
    //在界面中添加进程的信号
    void add_process_onui(process newprocess);
    //在后台添加进程的信号
    void add_process_onbs(process newprocess);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    //获取当前信息
    void get_status(int status=3,int queue=0);
    void  add_process(process new_process);
    void addQueue();
    void changeImg();
    void changeImg_step();



private:
    Ui::MainWindow *ui;
    //用于记录ui列表list0中各队列列的记录数
    int row_count[3];
    int *colume_count;
    bool usingpauseimg;              //为了改变pause按钮而加的变量
    void generateName();              //产生进程名
    QString updateString(QString pro,int status);   //更新显示的进程信息
};

#endif // MAINWINDOW_H
