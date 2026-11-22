#pragma once
#include <iostream>
#include "indentity.h"
#include <fstream>
#include "globalfile.h"
#include "computer.h"
#include <vector>
using namespace std;
class student :public Identity
{
public:
	virtual void showmenu();
	student();
	student(int id, string name, string pwd);
	void applyorder();
	void showmyorder();
	void showallorder();
	void cancelorder();
	int m_id;
	~student();
	vector<computerroom>vcom1;
};
