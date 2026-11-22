#pragma once
#include <iostream>
#include <string>
#include "indentity.h"
#include <vector>
#include "Student.h"
#include "Teacher.h"
#include "computer.h"
using namespace std;
class manager :public Identity
{
public:
	manager();
	virtual void showmenu();
	~manager();
	manager(string name, string pwd);
	void addzhanghao();
	void chakanzhanghao();
	void chakanjifangxinxi();
	void qingkongjilu();
	void initvector();
	bool checkrepeat(int id, int type);
	vector<student>vstu;
	vector<teacher>vtea;
	vector<computerroom>vcom;
};