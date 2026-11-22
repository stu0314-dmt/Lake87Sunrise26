#pragma once
#include <iostream>
#include "indentity.h"
#include <vector>
using namespace std;
class teacher :public Identity
{
public:
	teacher();
	teacher(int id, string name, string pwd);
	virtual void showmenu();
	void showallorder();
	void validorder();
	int m_id;
	~teacher();
};