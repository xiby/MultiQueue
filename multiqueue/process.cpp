#include "process.h"



process::process()					//默认构造函数，无参数
{
	pName = "process123";
	arriveTime =0;
	serveTime=0;
	runTime = 0;
	rotTime = 0;
	wrotTime = 0;
	serveinQueue = 0;
}


process::~process()					//析构函数
{
}

process::process(string name, int arrivetime, int servetime):pName(name)		//通过string对象name，到达时间，以及所需的服务时间来构造一个process对象
{
	arriveTime = arrivetime;
	serveTime = servetime;
	runTime = 0;
	rotTime = 0;
	wrotTime = 0;
	serveinQueue = 0;
	//for push

}

string process::getName(){						//获取当前进程名
	return pName;
}

void process::setwrotTime(int time)				//设置进程的加权周转时间
{
	wrotTime = time;
}

void process::setName(string name){				//设置进程名
	pName=name;
}

int process::getserveTime()						//获取进程的服务时间
{
	return serveTime;
}

int process::getrunTime()						//获取进程已经运行的时间
{
	return runTime;
}

int process::getserveinQueue()					//获取进程在某个队列中运行的时间
{
	return serveinQueue;
}

int process::getrotTime()						//获取周转时间
{
	rotTime = endTime - arriveTime;
	return rotTime;
}

double process::getwrotTime()						//获取带权周转时间
{
	return wrotTime;
}

void process::setserveTime(int time)				//设置所需的服务时间
{
	serveTime = time;
}

void process::setrunTime(int time)					//设置已经运行的时间
{
	runTime = time;
}

void process::setserveinQueue(int time)				//设置在某个队列中运行的时间
{
	serveinQueue = time;
}

void process::setendTime(int time)					//设置进程结束时间
{
	endTime = time;
}

void process::setrotTime(int time)					//设置进程周转时间
{
	rotTime = time;
}

bool process::run(int chip)							//
{													//进程在队列中的一次运行，每次运行1s，然后根据所在队列的时间片chip 来判断进程是否应该添加到下一个队列中//
	serveinQueue++;									//如果返回true，则应该将其加入到下一个队列中，否则则应该继续在原队列中执行//
	runTime++;
	if(serveinQueue==chip)
	{
		serveinQueue=0;
		return true;
	}
	else
	{
		return false;
	}
}
												//////////////////////////
bool process::finished(){						//判断进程是否已经执行完毕//		
	if(runTime==serveTime){						//若已经结束，则返回true//
		return true;							//////否则返回false//////
	}else{										///////////////////////
		return false;
	}
}
