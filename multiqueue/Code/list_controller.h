#define list_controller__
#ifdef list_controller__

class list_controller
{
	//缓冲池
	//队列数组，STL

public:
	list_controller();
	~list_controller();

	//修改系统时间，并返回当前系统时间
	int system_time();
	// 交互界面调用方法，修改pause标记位状态
	void set_pause();
	//判断系统是否需要暂停，true=TRUE
	bool is_pause();
	//交互界面调用方法，修改exit标记位状态
	bool set_exit();
	//判断是否退出程序，true=TRUE
	void is_exit();
	//判断缓冲池中是否有新的数据
	bool has_new_process();
	//用于交互界面调用，响应添加事件，将process放入缓冲池
	void set_process();
	//从缓冲池中获取一个新的process
	process get();
	//判断运行的下一级队列，返回队列的编号
	int which_queue();
	//暂时暂停时间
	void sleep(int time);
};

#endif // list_controller__