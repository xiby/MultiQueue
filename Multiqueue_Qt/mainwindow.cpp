#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&a,SIGNAL(sendMsg(QString)),this,SLOT(getMsg(QString)));
    connect(&a,SIGNAL(sendTime(int)),this,SLOT(getTime(int)));
    a.start();
    ui->time->display(0);
}

void MainWindow::getMsg(QString msg){
    this->ui->textEdit->append(msg);
}

void MainWindow::getTime(int t){
    this->ui->time->display(t);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pause_clicked()
{
    a.setpause();
}
