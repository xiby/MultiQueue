#pragma once
#include"list_controller.h"
#include"process.h"
#include <QThread>
#include <QString>

#ifndef _Enter___
#define _Enter___
class _Enter_ : public QThread
{
    Q_OBJECT
private:
    //设置运行速度
    int speed;
    QString a;
	process  process_contor;   //进程控制模块
	list_controller  list_control;         //队列控制模块
	//outputer output;                    //显示模块
public:
    _Enter_(QObject *parent = 0 );

    //单步执行指令
    //如果程序处在非暂停状态则暂停程序
    void step_run();
protected:
    //thread run方法重写
	void run();

public slots:
    //设置运行速度
    void set_speed(int t);
    //设置暂停
    void set_pause();
    //退出
    void set_exit();
    //添加新进程
    void set_process();
    void addQueue();


signals:
    void signal_runStatus(int status,int queue) const;
    void signal_time(int t) const;

};
#endif // _Enter___
