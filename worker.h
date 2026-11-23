#pragma once
#include <iostream>
using namespace std;
class worker
{
public:
	virtual void show() = 0;
	virtual string get() = 0;
	int m_id;
	string m_name;
	int m_deptid;
};