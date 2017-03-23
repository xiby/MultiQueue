#include "list_controller.h"



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
	string name;
	int servetime;
	//Text存储从前段获取的数据
	process text(name,servetime, Time);
	buffer_list.push(text);
}

process list_controller::get()
{
	if (buffer_list.empty())
	{
		return;
	}
	process swap;
	swap = buffer_list.front();
	buffer_list.pop();
	return swap;
}

void list_controller::push(process new_process)
{
	//未进行异常判断
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
	} else {
		QueueIndex = i;
		return true;
	}
}

void list_controller::sleep_(int time)
{
	_sleep(1000);
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
	if (tmp.run(getChip(QueueIndex))) {				//时间片已经花完
		if (tmp.finished()) {						//进程已经完成
			multi_list[QueueIndex].pop();
			return 2;
		} else {									//进程未执行完毕
			if (QueueIndex < multi_list_count - 1) {
				multi_list[QueueIndex + 1].push(multi_list[QueueIndex].front());
				multi_list[QueueIndex].pop();
				return 1;
			}
		}
	} else {										//时间片未花完
		if (tmp.finished()) {
			multi_list[QueueIndex].pop();
			return 2;
		} else {
			return 0;
		}
	}
}

int list_controller::getChip(int QueueIndex) {
	return Chips[QueueIndex];
}