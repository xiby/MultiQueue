#include "./MultiQueue.h"
#include"pch.h"

#include<ctime>			//为了测试加的
#include<sstream>		//同上


_Enter_::_Enter_():list_control(3)
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
		std::stringstream sname;
		sname << "process" << i;
		process tmp(sname.str(), list_control.system_time(), 4 * (i + 1));
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
			list_control.run(queue_index);
		}
		
		//从界面回去时间参数。
		int get_time=100;
		list_control.sleep_(get_time);
    }      
}


