#include "process.h"



process::process()
{
	pName = "process123";
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

process::process(string name, int arrivetime, int servetime):pName(name)
{
	arriveTime = arrivetime;
	serveTime = servetime;
	runTime = 0;
	rotTime = 0;
	wrotTime = 0;
	serveinQueue = 0;
	//for push

}

string process::getName(){
	return pName;
}

void process::setwrotTime(int time)
{
	wrotTime = time;
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

int process::getwrotTime()
{
	return wrotTime;
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

void process::setrotTime(int time)
{
	rotTime = time;
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
