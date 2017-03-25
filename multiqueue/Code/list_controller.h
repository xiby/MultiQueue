
#ifndef list_controller__
#define list_controller__
#include"process.h"
#include<queue>
using namespace std;

class list_controller
{
private:
	//存储系统时间
	int Time;
	//缓冲池
	queue<process> buffer_list;
	//队列数组，STL
	int multi_list_count;
	queue<process> *multi_list;

	int * Chips;				//每个队列时间片构成的数组

	//flags
	bool exit_flag;
	bool pause_flag;
	bool new_prcess_flag;

public:
	list_controller(int Qnum);
	~list_controller();

	//修改系统时间，并返回当前系统时间
	int system_time();
	// 交互界面调用方法，修改pause标记位状态
	void set_pause();
	//判断系统是否需要暂停，true=TRUE
	bool is_pause();
	//交互界面调用方法，修改exit标记位状态
	void set_exit();
	//判断是否退出程序，true=TRUE
	bool is_exit();
	//判断缓冲池中是否有新的数据
	bool has_new_process();
	//用于交互界面调用，响应添加事件，将process放入缓冲池
	void set_process();
	//set_process重载，带process参数
	void set_process(process text);
	//从缓冲池中获取一个新的process
	process get();
	//将new_process放入第一级队列
	void push(process new_process);
	//判断运行的下一级队列，QueueIndex返回队列的编号 所有队列为空返回false.
	bool which_queue(int & QueueIndex);
	//暂时暂停时间
	void sleep_(int time);

	int getChip(int QueueIndex);				//根据队列编号确定时间片

	//执行一次（一秒）进程。
	int run(int QueueIndex);
	/*
		根据run的返回值来与前端进行通信
		当返回0时，应该继续在原队列中运行
		当返回1时，应该移到下一个队列运行
		当返回2时，进程已经运行结束，应该直接删除
	*/
};

#endif // list_controller__