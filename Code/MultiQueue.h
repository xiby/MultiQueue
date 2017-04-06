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
    //���������ٶ�
    int speed;
    QString a;
	process  process_contor;   //���̿���ģ��
	list_controller  list_control;         //���п���ģ��
	//outputer output;                    //��ʾģ��
public:
    _Enter_(QObject *parent = 0 );

    //����ִ��ָ��
    //��������ڷ���ͣ״̬����ͣ����
    void step_run();
protected:
    //thread run������д
	void run();

public slots:
    //���������ٶ�
    void set_speed(int t);
    //������ͣ
    void set_pause();
    //�˳�
    void set_exit();
    //����½���
    void set_process();
    void addQueue();


signals:
    void signal_runStatus(int status,int queue) const;
    void signal_time(int t) const;

};
#endif // _Enter___
