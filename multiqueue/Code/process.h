#include<string>
#include<iostream>
using namespace std;
#define process__
#ifdef process__
class process
{
public:
	process();
	~process();
	process(string name,int arrivetime,int servetime);
	string getName();
	int getserveTime();
	int getrunTime();
	int gettimeChip();
	int getserveinQueue();
	int getrotTime();
	void setserveTime(int time);
	void setrunTime(int time);
	void settimeChip(int time);
	void setserveinQueue(int time);
	void setendTime(int time);
	void setName(string name);
	bool is_goToNext(int chip);
	bool finished();
	bool run(int chip);     //进程的一次运行，每次运行1秒，若已将时间片花完，则返回TRUE，否则返回FALSE
private:
	string pName;		//进程名
	int arriveTime;		//进程到达时间
	int serveTime;		//进程所需的服务时间
	int runTime;		//进程已经运行的时间
	int serveinQueue;	//进程在某个队列中的时间
	int endTime;		//进程结束时间
	int rotTime;		//进程周转时间
	int wrotTime;		//进程带权周转时间
};
#endif // process_
