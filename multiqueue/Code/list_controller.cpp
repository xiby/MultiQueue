#include "list_controller.h"
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
}

int list_controller::system_time()
{
	return ++Time;
}

void list_controller::set_process()
{
	string name = "lalala";
	int servetime = 0 ;
	//Text从窗口获取时间
	process text(name,servetime, Time);
	buffer_list.push(text);
}

process list_controller::get()
{
	process swap;
	swap = buffer_list.front();
	buffer_list.pop();
	return swap;
}

void list_controller::push(process new_process)
{
	//δ�����쳣�ж�
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
	process tmp = multi_list[QueueIndex].front();
	if (tmp.run(getChip(QueueIndex))) {				//ʱ��Ƭ�Ѿ�����
		if (tmp.finished()) {						//�����Ѿ�����
			multi_list[QueueIndex].pop();
			return 2;
		} 
		else 
		{									//����δִ������
			if (QueueIndex < multi_list_count - 1) 
			{
				multi_list[QueueIndex + 1].push(multi_list[QueueIndex].front());
				multi_list[QueueIndex].pop();
				return 1;
			} else {
				multi_list[QueueIndex].push(multi_list[QueueIndex].front());
				multi_list[QueueIndex].pop();
				return 1;
			}
			//当为最后一个队列时未处理
		}
	} 
	else 
	{										//ʱ��Ƭδ����
		if (tmp.finished()) {
			multi_list[QueueIndex].pop();
			return 2;
		} 
		else 
		{
			return 0;
		}
	}
}

int list_controller::getChip(int QueueIndex) {
	return Chips[QueueIndex];
}