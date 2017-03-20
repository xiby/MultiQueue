#include "MultiQueue.h"

void _Enter_::run()
{
    while(!list_control.is_exit())
    {
        list_control.system_time();
        while(list_control.is_pause()|| list_control.has_new_process())
        {
           while(list_control.has_new_process)
            {
				//界面获取数据
                list_control.push(list_control.get());
				//push方法，如果new_process为空，需要修改标记位
            }
        }
		list_control.run(list_control.which_queue());
		//从界面回去时间参数。
		int get_time;
		list_control.sleep(get_time);
    }      
}


