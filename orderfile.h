#pragma once
#include <iostream>
using namespace std;
#include <map>
#include "globalfile.h"
#include <fstream>
class Orderfile
{
public:
	Orderfile();
	void updateorder();
	map<int, map<string, string>>m_orderdate;
	int m_size;
};