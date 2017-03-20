

class _Enter_
{
private:
    process_contorer  process_contor;   //进程控制模块
    list_contorer  list_contor;         //队列控制模块
    //outputer output;                    //显示模块

public:
    _Enter_();
    void run();

}

void _Enter_::run()
{
    while(!list_contor.exit())
    {
        list_contor.system_time();
        while(list_contor.is_pause()|| list_contor.has_new_process())
        {
           while(list_contor.has_new_process)
            {
				//界面获取数据
                list_contor.push(list_contor.get());
				//push方法，如果new_process为空，需要修改标记位
            }
        }
		list_contor.run(list_contor.which_queue());
		//从界面回去时间参数。
		list_contor.sleep();
    }      
}


