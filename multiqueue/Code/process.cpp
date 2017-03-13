#include "process.h"



process::process()
{
	pName = "process";
	arriveTime =0;
	serveTime=0;
	runTime = 0;
	rotTime = 0;
	wrotTime = 0;
	serveinQueue = 0;
}


process::~process()
{
}

process::process(string name, int arrivetime, int servetime,int chip=0):pName(name)
{
	arriveTime = arrivetime;
	serveTime = servetime;
	runTime = 0;
	rotTime = 0;
	wrotTime = 0;
	serveinQueue = 0;

}

string process::getName(){
	return pName;
}

void process::setName(string name){
	pName=name;
}

int process::getserveTime()
{
	return serveTime;
}

int process::getrunTime()
{
	return runTime;
}

int process::getserveinQueue()
{
	return serveinQueue;
}

int process::getrotTime()
{
	rotTime = endTime - arriveTime;
	return rotTime;
}

void process::setserveTime(int time)
{
	serveTime = time;
}

void process::setrunTime(int time)
{
	runTime = time;
}

void process::setserveinQueue(int time)
{
	serveinQueue = time;
}

void process::setendTime(int time)
{
	endTime = time;
}

bool process::run(int chip)
{
	serveinQueue++;
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

bool process::finished(){
	if(runTime==serveTime){
		return true;
	}else{
		return false;
	}
}
