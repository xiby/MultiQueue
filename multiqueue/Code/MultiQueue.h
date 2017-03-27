#pragma once
#include"list_controller.h"
#include"process.h"
#include "pch.h"

#ifndef _Enter___
#define _Enter___
class _Enter_
{
public:
	process  process_contor;   //���̿���ģ��
	list_controller  list_control;         //���п���ģ��
	//outputer output;                    //��ʾģ��
public:
	_Enter_();
	void run();

};
#endif // _Enter___