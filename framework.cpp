

class _Enter_
{
private:
    process_contorer  process_contor;   //进程控制模块
    list_contorer  list_contor;         //队列控制模块
    outputer output;                    //显示模块

public:
    _Enter_();
    void run();

}

void _Enter_::run()
{
    while(!output.exit())
    {
        list_contor.system_time();


        while(list_contor.pause())
        {
            if(list_contor.has_new_process);
            {
                list_contor.push(list_count);
            }
        }
        if(list_contor.has_new_process);
        {
            list_contor.push(list_count);
        }
        else
        {
            int i=0;
            while(list_contor.queue[i++]!=null)     //使用方法来调用queue.
            {
                process_contor.run();
                break;
            }
            list_contor.sleep()
        }
    }
        
}


/*
if(list_contor.has_process(1))
            {
                process_contor.run();
            }
            else
            {
                if(list_contor.has_process(2))
                {
                    process_contor.run();
                }
                else
                {
                    if(list_contor.has_process(3))
                    {
                        process_contor.run();
                    }
                }
            }
*/