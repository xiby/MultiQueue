#include "list_controller.h"
#include<windows.h>



list_controller::list_controller()
{
}


list_controller::~list_controller()
{
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