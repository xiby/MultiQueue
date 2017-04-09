#include "MultiQueue.h"

_Enter_::_Enter_(QObject *parent)
    : QThread(parent),list_control(3)
{
    speed=1000;
}

void _Enter_::run()
{
	int queue_index = 0;
    int run_status=-1;

    /*测试使用
	//以下均为测试数据
	//先将1个进程加入到缓冲区中
	//我把一下代码从初始化中移出，为了保持类的封闭性。
	for (int i = 0; i < 4; ++i) 
	{
		stringstream sname;
		sname << "process" << i;
		process tmp(sname.str(), list_control.system_time(), 4 * (i + 1));
		list_control.set_process(tmp);
	}
    //*/

    while(!list_control.is_exit())
    {
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
            //用来传递运行状态信息给ui

            run_status=list_control.run(queue_index);
            //返回运行动作参数给ui
            emit signal_runStatus(run_status,queue_index);
		}
		
		//从界面回去时间参数。

        list_control.sleep_(speed);
        emit signal_time(list_control.system_time());
        //向界面传递时间

   }

}

void _Enter_::set_speed(int t)
{
    speed=t;
}

void _Enter_::set_pause()
{
    list_control.set_pause();
}

void _Enter_::step_run()
{
    int queue_index = 0;
    int run_status=-1;
    if(list_control.is_pause())
    {

        if (list_control.which_queue(queue_index))
        {
            //用来传递运行状态信息给ui

            run_status=list_control.run(queue_index);
            //返回运行动作参数给ui
            emit signal_runStatus(run_status,queue_index);
        }

        //从界面回去时间参数。

        emit signal_time(list_control.system_time());
        //向界面传递时间
    }
    else
    {
        list_control.set_pause();
    }
}

void _Enter_::set_exit()
{
    list_control.set_exit();
}

void _Enter_::set_process(process new_process)
{

    //暂时使用此不带参数的方法
    list_control.set_process(new_process);
}

void _Enter_::addQueue(){
    this->list_control.addQueue();
}



