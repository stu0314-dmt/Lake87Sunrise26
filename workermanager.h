#pragma once
#include <iostream>
#include "worker.h"
#include <fstream>
#define FILENAME "empfile.txt"

using namespace std;
class workermanager
{
public:
	workermanager();

	void show_menu();
	void addyuangong();
	void exitsystem();
	~workermanager();
	void save();
	void initialnum();
	void showyuangong();
	void shanchuyuangong();
	int yuangongcunzai(int id);
	void xiugaizhigong();
	void chazhaoyuangong();
	void yuangongpaixu();
	void qingkongwenjian();
	int get_num();
	bool m_fileisempty;
	int m_empnum;
	worker** m_emparray;
};