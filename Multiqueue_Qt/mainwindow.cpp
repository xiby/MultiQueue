#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../Code/MultiQueue.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    for(int i=0;i<3;i++)
    {
        row_count[i]=0;
        colume_count[i]=0;
    }

    ui->setupUi(this);

    //设置计时器显示位数为3
    ui->time->setDigitCount(3);
    //设置速度滑钮最大值和最小值
    ui->speed->setMaximum(2000);
    ui->speed->setMinimum(200);
    //设置速度按钮的初始值
    ui->speed->setValue(1000);
    //设置表格不可更改
    ui->list0->setColumnCount(3);
    ui->list0->setRowCount(1);
    ui->list0->setItem(0,0,new QTableWidgetItem("222"));
    ui->list0->setRowCount(16);
    ui->list0->verticalHeader()->setVisible(false);
    QStringList header ;
    header<<"队列1"<<"队列2"<<"队列3";
    ui->list0->setHorizontalHeaderLabels(header);


     _Enter_ *process_enter= new _Enter_();
     //传递系统时间饼显示
    connect(process_enter,SIGNAL(signal_time(int)),(ui->time),SLOT(display(int)));
    //传递时间参数
    connect(ui->speed,SIGNAL(valueChanged(int)),process_enter,SLOT(set_speed(int)));
    //修改暂停标记位
    connect(ui->pause,ui->pause->clicked,process_enter,process_enter->set_pause);
    //调用单步执行函数
    connect(ui->next,ui->next->clicked,process_enter,process_enter->step_run);
    //添加新的进程，（正在使用测试模块）
    connect(ui->add_Button,ui->add_Button->clicked,process_enter,process_enter->set_process);
    connect(ui->add_Button,ui->add_Button->clicked,this,this->add_process);
    //接收显示参数，调用显示函数（MainWindow中的方法 get_status()）
    connect(process_enter,SIGNAL(signal_runStatus(int,int)),this,SLOT(get_status(int,int)));
    process_enter->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::get_status(int status, int queue)
{
    /*
        根据status的值来与前端进行通信
        当返回0时，时间片没有用完
        当返回1时，应该移到下一个队列运行
        当返回2时，进程已经运行结束，应该直接删除
        当返回3时，进程在最后一个队列循环运行
    */
    QString a;
    QString buffer;
    switch (status) {
    case 0:
        //点用显示函数
        //ui->list0->setItem(1,queue,new QTableWidgetItem("继续在原队列"));
        break;
    case 1:
         a=ui->list0->item(0,queue)->text();
         ui->list0->setItem(row_count[queue+1],queue+1,new QTableWidgetItem(a));
        //移动显示表中的进程
        for(int i=0;i<row_count[queue];i++)
        {
            if(i+1<row_count[queue])
            {
               a=ui->list0->item(i+1,queue)->text();
               ui->list0->setItem(i,queue,new QTableWidgetItem(a));
            }
            else
            {
               a="";
               ui->list0->setItem(i,queue,new QTableWidgetItem(a));
            }
        }
        row_count[queue]--;
        row_count[queue+1]++;
        break;
    case 2:
        for(int i=0;i<row_count[queue];i++)
        {
            if(i+1<row_count[queue])
            {
               a=ui->list0->item(i+1,queue)->text();
               ui->list0->setItem(i,queue,new QTableWidgetItem(a));
            }
            else
            {
               a="";
               ui->list0->setItem(i,queue,new QTableWidgetItem(a));
            }
        }
        row_count[queue]--;
        break;
    case 3:
        buffer=ui->list0->item(0,queue)->text();
       //移动显示表中的进程
       for(int i=0;i<row_count[queue];i++)
       {
           if(i+1<row_count[queue])
           {
              a=ui->list0->item(i+1,queue)->text();
              ui->list0->setItem(i,queue,new QTableWidgetItem(a));
           }
           else
           {
              ui->list0->setItem(i,queue,new QTableWidgetItem(buffer));
           }
       }
        break;
    default:
        break;
    }
}

void MainWindow::add_process()
{
    ui->list0->setItem(row_count[0],0,new QTableWidgetItem("a"));
    row_count[0]++;
}


