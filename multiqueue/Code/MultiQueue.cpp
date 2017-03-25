#include "MultiQueue.h"

_Enter_::_Enter_():list_control(3)
{
}

void _Enter_::run()
{
	int queue_index = 0;
	//测试使用
	process a("a", 1, 5);
	list_control.set_process(a);

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


