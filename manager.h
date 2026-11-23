#pragma once
#include <iostream>
using namespace std;
#include <string>
#include "worker.h"
class  manager  :public worker
{
public:
	manager(int id, string name, int did);
	virtual void show();
	virtual string get();
};