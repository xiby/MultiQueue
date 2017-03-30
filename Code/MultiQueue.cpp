#include "MultiQueue.h"
#include<ctime>			//为了测试加的
#include<sstream>		//同上

_Enter_::_Enter_(QObject *parent):QThread(parent),list_control(3)
{
}

void _Enter_::run()
{
	int queue_index = 0;

	//测试使用
	//以下均为测试数据
	//先将1个进程加入到缓冲区中
	//我把一下代码从初始化中移出，为了保持类的封闭性。
	for (int i = 0; i < 4; ++i) 
	{
		stringstream sname;
		sname << "process" << i;
        process tmp(sname.str(), list_control.get_sys_time(), 4 * (i + 1));
		list_control.set_process(tmp);
	}
	//测试代码

    while(!list_control.is_exit())
    {
        list_control.system_time();
        while(list_control.is_pause()|| list_control.has_new_process())
        {
           while(list_control.has_new_process())
            {
				//界面获取数据
               list_control.push(list_control.get());
				//push方法，如果new_process为空，需要修改标记位
            }
        }
		if (list_control.which_queue(queue_index))
		{
            QString msg="";
            msg.append(QString::fromStdString(list_control.getlist()[queue_index].front().getName()));
            msg.append(" is running in ");
            msg.append(QString::number(queue_index));
            msg.append("\n");
            int sgn=list_control.run(queue_index);
            if(sgn==0){

            }else if(sgn==1){

            }else if(sgn==2){

            }else{

            }
            emit sendTime(list_control.get_sys_time());
            emit sendMsg(msg);
		}
		
		//从界面回去时间参数。
		int get_time=100;
		list_control.sleep_(get_time);
    }      
}

void _Enter_::setpause(){
    list_control.set_pause();
}


