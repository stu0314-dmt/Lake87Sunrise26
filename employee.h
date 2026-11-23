#pragma once
#include <iostream>
using namespace std;
#include <string>
#include "worker.h"
class  employee :public worker
{
public:
	employee(int id,string name,int did);
	virtual void show();
	virtual string get();
};