#pragma once
#include"list_controller.h"
#include"process.h"

#include<QThread>
#include<QString>

#ifndef _Enter___
#define _Enter___
class _Enter_:public QThread
{
    Q_OBJECT
private:
	process  process_contor;   //进程控制模块
	list_controller  list_control;         //队列控制模块
	//outputer output;                    //显示模块
public:
    _Enter_(QObject *parent=0);
	void run();
    void setpause();

signals:
    void sendMsg(QString msg);
    void sendTime(int t);

};
#endif // _Enter___
