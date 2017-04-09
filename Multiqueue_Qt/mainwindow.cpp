#include "mainwindow.h"
#include "ui_mainwindow.h"


#include<iostream>
#include<string>
#include<ctime>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    srand(time(NULL));
    usingpauseimg=true;        //一开始使用暂停图片
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
    ui->list0->setItem(0,0,new QTableWidgetItem(""));
    ui->list0->setRowCount(16);
    ui->list0->verticalHeader()->setVisible(false);
    ui->list0->horizontalHeader()->setStyleSheet("QHeaderView::section{background:rgb(226,198,148);}");

    //ui->Multiqueue->setPalette(QWidget::palette().color(this->backgroundRole()));
    //ui->Multiqueue->setAutoFillBackground(true);

    QStringList header ;
    header<<"队列1"<<"队列2"<<"队列3";
    ui->list0->setHorizontalHeaderLabels(header);
    ui->list0->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->list0->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    ui->add_queue_Button->setStyleSheet("QPushButton{border-image:url(:/img/addM.png)}"
                                        "QPushButton:pressed{border-image:url(:/img/addM_clicked.png)}");
    ui->add_Button->setStyleSheet("QPushButton{border-image:url(:/img/addP.png)}"
                                        "QPushButton:pressed{border-image:url(:/img/addP_clicked.png)}");
    ui->next->setStyleSheet("QPushButton{border-image:url(:/img/step.png)}"
                                        "QPushButton:pressed{border-image:url(:/img/step_clicked.png)}");

     _Enter_ *process_enter= new _Enter_();
     //传递系统时间饼显示
    connect(process_enter,SIGNAL(signal_time(int)),(ui->time),SLOT(display(int)));
    //传递时间参数
    connect(ui->speed,SIGNAL(valueChanged(int)),process_enter,SLOT(set_speed(int)));
    //修改暂停标记位
    connect(ui->pause,ui->pause->clicked,process_enter,process_enter->set_pause);
    connect(ui->pause,ui->pause->clicked,this,this->changeImg);
    //调用单步执行函数
    connect(ui->next,ui->next->clicked,process_enter,process_enter->step_run);
    connect(ui->next,ui->next->clicked,this,this->changeImg_step);
    //添加新的进程，（正在使用测试模块）
    connect(ui->add_Button,ui->add_Button->clicked,this,this->generateName);
    //connect(ui->add_Button,ui->add_Button->clicked,this,this->add_process);
    //接收显示参数，调用显示函数（MainWindow中的方法 get_status()）
    connect(process_enter,SIGNAL(signal_runStatus(int,int)),this,SLOT(get_status(int,int)));
    connect(ui->add_queue_Button,ui->add_queue_Button->clicked,process_enter,process_enter->addQueue);
    connect(ui->add_queue_Button,ui->add_queue_Button->clicked,this,this->addQueue);

    //将界面中添加进程信号和ui、后台相应的槽函数联系起来
    connect(this,SIGNAL(add_process_onbs(process)),process_enter,SLOT(set_process(process)));
    connect(this,SIGNAL(add_process_onui(process)),this,SLOT(add_process(process)));
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

void MainWindow::add_process(process new_process)
{
    ui->list0->setItem(row_count[0],0,new QTableWidgetItem(QString::fromStdString(new_process.getName())));
    row_count[0]++;
}

void MainWindow::addQueue(){        //在界面中增加列
    ui->list0->insertColumn(ui->list0->columnCount());
    QStringList head;
    for(int i=0;i<ui->list0->columnCount();++i){
        stringstream s;
        s<<"队列"<<i+1;
        QString qs=QString::fromStdString(s.str());
        head<<qs;
    }
    ui->list0->setHorizontalHeaderLabels(head);
}

void MainWindow::changeImg(){
    usingpauseimg=!usingpauseimg;
    if(usingpauseimg){
        ui->pause->setStyleSheet("border-image: url(:/img/run.png)");
    }else{
        ui->pause->setStyleSheet("border-image: url(:/img/stop.png)");
    }

}

void MainWindow::generateName(){
        int x, y;

        x = rand() % 10;

        y = rand() % 10;//产生随机数

         string xing;
         string ming;
         string jinchengming;
        if (x == 0)
        {
             xing = "zhao";

            if (y == 0)
            {
                ming = "jian";
                jinchengming = xing + ming;

            }
            else if (y == 1)
            {
                ming = "chen";
                jinchengming = xing + ming;

            }
            else if (y == 2)
            {
                ming = "lian";
                jinchengming = xing + ming;

            }
            else if (y == 3)
            {
                ming = "lei";
                jinchengming = xing + ming;

            }
            else if (y == 4)
            {
                ming = "li";
                jinchengming = xing + ming;

            }
            else if (y == 5)
            {
                ming = "qiang";
                jinchengming = xing + ming;

            }
            else if (y == 6)
            {
                ming = "hong";
                jinchengming = xing + ming;

            }
            else if (y == 7)
            {
                ming = "bin";
                jinchengming = xing + ming;

            }
            else if (y == 8)
            {
                ming = "juan";
                jinchengming = xing + ming;

            }
            else if (y == 9)
            {
                ming = "mei";
                jinchengming = xing + ming;

            }

        }
        else if (x == 1)
        {
             xing = "qian";
            if (y == 0)
            {
                ming = "jian";
                jinchengming = xing + ming;

            }
            else if (y == 1)
            {
                ming = "chen";
                jinchengming = xing + ming;

            }
            else if (y == 2)
            {
                ming = "lian";
                jinchengming = xing + ming;

            }
            else if (y == 3)
            {
                ming = "lei";
                jinchengming = xing + ming;

            }
            else if (y == 4)
            {
                ming = "li";
                jinchengming = xing + ming;

            }
            else if (y == 5)
            {
                ming = "qiang";
                jinchengming = xing + ming;

            }
            else if (y == 6)
            {
                ming = "hong";
                jinchengming = xing + ming;

            }
            else if (y == 7)
            {
                ming = "bin";
                jinchengming = xing + ming;

            }
            else if (y == 8)
            {
                ming = "juan";
                jinchengming = xing + ming;

            }
            else if (y == 9)
            {
                ming = "mei";
                jinchengming = xing + ming;

            }

        }
        else if (x == 2)
        {
             xing = "sun";
            if (y == 0)
            {
                ming = "jian";
                jinchengming = xing + ming;

            }
            else if (y == 1)
            {
                ming = "chen";
                jinchengming = xing + ming;

            }
            else if (y == 2)
            {
                ming = "lian";
                jinchengming = xing + ming;

            }
            else if (y == 3)
            {
                ming = "lei";
                jinchengming = xing + ming;

            }
            else if (y == 4)
            {
                ming = "li";
                jinchengming = xing + ming;

            }
            else if (y == 5)
            {
                ming = "qiang";
                jinchengming = xing + ming;

            }
            else if (y == 6)
            {
                ming = "hong";
                jinchengming = xing + ming;

            }
            else if (y == 7)
            {
                 ming = "bin";
                 jinchengming = xing + ming;

            }
            else if (y == 8)
            {
                 ming = "juan";
                 jinchengming = xing + ming;

            }
            else if (y == 9)
            {
                 ming = "mei";
                 jinchengming = xing + ming;

            }

        }
        else if (x == 3)
        {
             xing = "li";
            if (y == 0)
            {
                 ming = "jian";
                 jinchengming = xing + ming;

            }
            else if (y == 1)
            {
                 ming = "chen";
                 jinchengming = xing + ming;

            }
            else if (y == 2)
            {
                 ming = "lian";
                 jinchengming = xing + ming;

            }
            else if (y == 3)
            {
                 ming = "lei";
                 jinchengming = xing + ming;

            }
            else if (y == 4)
            {
                 ming = "li";
                 jinchengming = xing + ming;

            }
            else if (y == 5)
            {
                 ming = "qiang";
                 jinchengming = xing + ming;

            }
            else if (y == 6)
            {
                 ming = "hong";
                 jinchengming = xing + ming;

            }
            else if (y == 7)
            {
                 ming = "bin";
                 jinchengming = xing + ming;

            }
            else if (y == 8)
            {
                 ming = "juan";
                 jinchengming = xing + ming;

            }
            else if (y == 9)
            {
                 ming = "mei";
                 jinchengming = xing + ming;

            }

        }
        else if (x == 4)
        {
             xing = "zhou";
            if (y == 0)
            {
                 ming = "jian";
                 jinchengming = xing + ming;

            }
            else if (y == 1)
            {
                 ming = "chen";
                 jinchengming = xing + ming;

            }
            else if (y == 2)
            {
                 ming = "lian";
                 jinchengming = xing + ming;

            }
            else if (y == 3)
            {
                 ming = "lei";
                 jinchengming = xing + ming;

            }
            else if (y == 4)
            {
                 ming = "li";
                 jinchengming = xing + ming;

            }
            else if (y == 5)
            {
                 ming = "qiang";
                 jinchengming = xing + ming;

            }
            else if (y == 6)
            {
                 ming = "hong";
                 jinchengming = xing + ming;

            }
            else if (y == 7)
            {
                 ming = "bin";
                 jinchengming = xing + ming;

            }
            else if (y == 8)
            {
                 ming = "juan";
                 jinchengming = xing + ming;

            }
            else if (y == 9)
            {
                 ming = "mei";
                 jinchengming = xing + ming;

            }

        }
        else if (x == 5)
        {
             xing = "wu";
            if (y == 0)
            {
                 ming = "jian";
                 jinchengming = xing + ming;

            }
            else if (y == 1)
            {
                 ming = "chen";
                 jinchengming = xing + ming;

            }
            else if (y == 2)
            {
                 ming = "lian";
                 jinchengming = xing + ming;

            }
            else if (y == 3)
            {
                 ming = "lei";
                 jinchengming = xing + ming;

            }
            else if (y == 4)
            {
                 ming = "li";
                 jinchengming = xing + ming;

            }
            else if (y == 5)
            {
                 ming = "qiang";
                 jinchengming = xing + ming;

            }
            else if (y == 6)
            {
                 ming = "hong";
                 jinchengming = xing + ming;

            }
            else if (y == 7)
            {
                 ming = "bin";
                 jinchengming = xing + ming;

            }
            else if (y == 8)
            {
                 ming = "juan";
                 jinchengming = xing + ming;

            }
            else if (y == 9)
            {
                 ming = "mei";
                 jinchengming = xing + ming;

            }

        }
        else if (x == 6)
        {
             xing = "zhen";
            if (y == 0)
            {
                 ming = "jian";
                 jinchengming = xing + ming;

            }
            else if (y == 1)
            {
                 ming = "chen";
                 jinchengming = xing + ming;

            }
            else if (y == 2)
            {
                 ming = "lian";
                 jinchengming = xing + ming;

            }
            else if (y == 3)
            {
                 ming = "lei";
                 jinchengming = xing + ming;

            }
            else if (y == 4)
            {
                 ming = "li";
                 jinchengming = xing + ming;

            }
            else if (y == 5)
            {
                 ming = "qiang";
                 jinchengming = xing + ming;

            }
            else if (y == 6)
            {
                 ming = "hong";
                 jinchengming = xing + ming;

            }
            else if (y == 7)
            {
                 ming = "bin";
                 jinchengming = xing + ming;

            }
            else if (y == 8)
            {
                 ming = "juan";
                 jinchengming = xing + ming;

            }
            else if (y == 9)
            {
                 ming = "mei";
                 jinchengming = xing + ming;

            }

        }
        else if (x == 7)
        {
             ming = "wang";
            if (y == 0)
            {
                 ming = "jian";
                 jinchengming = xing + ming;

            }
            else if (y == 1)
            {
                 ming = "chen";
                 jinchengming = xing + ming;

            }
            else if (y == 2)
            {
                 ming = "lian";
                 jinchengming = xing + ming;

            }
            else if (y == 3)
            {
                 ming = "lei";
                 jinchengming = xing + ming;

            }
            else if (y == 4)
            {
                 ming = "li";
                 jinchengming = xing + ming;

            }
            else if (y == 5)
            {
                 ming = "qiang";
                 jinchengming = xing + ming;

            }
            else if (y == 6)
            {
                 ming = "hong";
                 jinchengming = xing + ming;

            }
            else if (y == 7)
            {
                 ming = "bin";
                 jinchengming = xing + ming;

            }
            else if (y == 8)
            {
                 ming = "juan";
                 jinchengming = xing + ming;

            }
            else if (y == 9)
            {
                 ming = "mei";
                 jinchengming = xing + ming;

            }

        }
        else if (x == 8)
        {
             xing = "feng";
            if (y == 0)
            {
                 ming = "jian";
                 jinchengming = xing + ming;

            }
            else if (y == 1)
            {
                 ming = "chen";
                 jinchengming = xing + ming;

            }
            else if (y == 2)
            {
                 ming = "lian";
                 jinchengming = xing + ming;

            }
            else if (y == 3)
            {
                 ming = "lei";
                 jinchengming = xing + ming;

            }
            else if (y == 4)
            {
                 ming = "li";
                 jinchengming = xing + ming;

            }
            else if (y == 5)
            {
                 ming = "qiang";
                 jinchengming = xing + ming;

            }
            else if (y == 6)
            {
                 ming = "hong";
                 jinchengming = xing + ming;

            }
            else if (y == 7)
            {
                 ming = "bin";
                 jinchengming = xing + ming;

            }
            else if (y == 8)
            {
                 ming = "juan";
                 jinchengming = xing + ming;

            }
            else if (y == 9)
            {
                 ming = "mei";
                 jinchengming = xing + ming;

            }

        }
        else if (x == 9)
        {
             xing = "chen";
            if (y == 0)
            {
                 ming = "jian";
                 jinchengming = xing + ming;

            }
            else if (y == 1)
            {
                 ming = "chen";
                 jinchengming = xing + ming;

            }
            else if (y == 2)
            {
                 ming = "lian";
                 jinchengming = xing + ming;

            }
            else if (y == 3)
            {
                 ming = "lei";
                 jinchengming = xing + ming;

            }
            else if (y == 4)
            {
                 ming = "li";
                 jinchengming = xing + ming;

            }
            else if (y == 5)
            {
                 ming = "qiang";
                 jinchengming = xing + ming;

            }
            else if (y == 6)
            {
                 ming = "hong";
                 jinchengming = xing + ming;

            }
            else if (y == 7)
            {
                 ming = "bin";
                 jinchengming = xing + ming;

            }
            else if (y == 8)
            {
                 ming = "juan";
                 jinchengming = xing + ming;

            }
            else if (y == 9)
            {
                 ming = "mei";
                 jinchengming = xing + ming;

            }

        }
        int arriveTime=int(ui->time->value());
        int serveTime=(rand()%20)+1;
        process new_process(jinchengming,arriveTime,serveTime);
        emit this->add_process_onbs(new_process);
        emit this->add_process_onui(new_process);
}
void MainWindow::changeImg_step(){

}
