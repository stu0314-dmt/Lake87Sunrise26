
#pragma once
#include <iostream>
using namespace std;
#include <string>
#include "worker.h"
class  boss :public worker
{
public:
	boss(int id, string name, int did);
	virtual void show();
	virtual string get();
};