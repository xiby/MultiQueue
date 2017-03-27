#include "pch.h"

#include"list_controller.h"
#include<windows.h>



list_controller::list_controller(int Qnum)	//用Qnum初始化队列数
{
	Time = 0;								//系统时间初始化为0
	multi_list_count = Qnum;
	Chips = new int[multi_list_count];					//新建数组
	for (int i = 0; i < multi_list_count; ++i) {
		Chips[i] = 2 * (i + 1);							//初始化每个队列的时间片
	}

	this->multi_list = new queue<process>[Qnum];		//初始化进程队列数组

	//初始化标志位
	exit_flag = false;
	pause_flag = false;
	new_prcess_flag = false;
	//标志位初始化完毕
}


list_controller::~list_controller()
{
	delete[] Chips;
	delete[] multi_list;
}

//获取某个进程队列
queue<process> list_controller::getQueue(int queueIndex)
{
	return multi_list[queueIndex];
}

int list_controller::system_time()
{
	return ++Time;
}

void list_controller::set_process()
{
	//以下为测试数据
	string name = "lalala";
	int servetime = 0 ;
	//测试数据结束
	//Text从窗口获取时间
	process text(name,servetime, Time);
	buffer_list.push(text);
	new_prcess_flag = true;
}

void list_controller::set_process(process text)
{
	buffer_list.push(text);
	new_prcess_flag = true;
}

process list_controller::get()
{
	process swap;
	swap = buffer_list.front();
	buffer_list.pop();

	//增加当缓冲区为空的情况的处理
	//当缓冲区为空时，将new_process_flag置为false;
	if (buffer_list.empty()) {
		new_prcess_flag = false;		
	}
	return swap;
}

void list_controller::push(process new_process)
{
	//将新进程push到最开始的队列中
	multi_list[0].push(new_process);
}

bool list_controller::which_queue(int & QueueIndex)
{
	int i;
	for (i = 0; i < multi_list_count; i++)
	{
		if (!multi_list[i].empty())
		{
			break;
		}
	}
	if (i == multi_list_count) {
		return false;
	} 
	else 
	{
		QueueIndex = i;
		return true;
	}
}

void list_controller::sleep_(int time)
{
	Sleep(1000);
}

bool list_controller::has_new_process()
{
	if (buffer_list.empty())
	{
		return false;
	}
	else
	{
		return true;
	}
}

void list_controller::set_pause()
{
	pause_flag = true;
}

bool list_controller::is_pause()
{
	return pause_flag;
}

void list_controller::set_exit()
{
	exit_flag = true;
}

bool list_controller::is_exit()
{
	return exit_flag;
}

int list_controller::run(int QueueIndex) {
	if (multi_list[QueueIndex].front().run(getChip(QueueIndex))) {				//判断时间片是否用完，如果已将时间片花完，则进行下面的操作
		if (multi_list[QueueIndex].front().finished()) {						//判断进程是否计算完
			multi_list[QueueIndex].pop();
			return 3;															//若进程已经执行完毕，则返回3
		} 
		else																	//若还未执行完毕，则进行接下来的判断
		{									//判断是否在最后一个队列
			if (QueueIndex < multi_list_count - 1)								//如果不在最后一个队列的话，则直接加入到下一个队列的队尾
			{
				multi_list[QueueIndex + 1].push(multi_list[QueueIndex].front());
				multi_list[QueueIndex].pop();
				return 1;														//此时返回1
			} else {															//若在最后一个队列，则返回2
				multi_list[QueueIndex].push(multi_list[QueueIndex].front());
				multi_list[QueueIndex].pop();
				return 2;
			}
		}
	} 
	else 
	{										//时间片没有用完
		if (multi_list[QueueIndex].front().finished()) {	//但进程已经结束，返回3
			multi_list[QueueIndex].pop();
			return 3;
		} 
		else 
		{
			return 0;										//若还要在原队列中继续执行，则返回0
		}
	}
}

int list_controller::getChip(int QueueIndex) {
	return Chips[QueueIndex];
}