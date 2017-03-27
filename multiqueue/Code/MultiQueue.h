#pragma once
#include"list_controller.h"
#include"process.h"
#include "pch.h"

#ifndef _Enter___
#define _Enter___
class _Enter_
{
private:
	process  process_contor;   //进程控制模块
	list_controller  list_control;         //队列控制模块
	//outputer output;                    //显示模块
public:
	_Enter_();
	void run();

};
#endif // _Enter___