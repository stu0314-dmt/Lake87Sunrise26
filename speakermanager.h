#pragma once
#include <iostream>
#include <vector>
#include "speaker.h"
#include <map>;
using namespace std;
class speakermanager
{
public:
	speakermanager();
	~speakermanager();
	void printmenu();
	void tuichu();
	void chushihua();
	//vector<speaker>v1;
	//vector<speaker>v2;
	//vector<speaker>winv;
	vector<int>v1;
	vector<int>v2;
vector<int>winv;
	map<int, speaker>m1;
	int index;
	void creatspeaker();
	void startcontest();
	void chouqian();
	void kaishibisai();
	void showjinjizhe();
	void saverecord();
	void loadrecord();
	bool isempty;
	map<int, vector<string>>m_record;
	void showrecord();
	void qingkong();
};