#include "speakermanager.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <deque>
#include <numeric>
#include "speaker.h"
#include <functional>
#include <fstream>
using namespace std;
speakermanager::speakermanager()
{
	this->chushihua();
	this->creatspeaker();
	//for (map<int,speaker>::iterator it = this->m1.begin();it != m1.end();it++)
	//{
	//	cout << it->first << "  " << it->second.name << "   " << it->second.score[0] << "  " << it->second.score[1] << endl;
	//}
	//this->loadrecord();
	this->loadrecord();
}
speakermanager::~speakermanager()
{

}
void speakermanager::printmenu()
{
	cout << "*******************************************************" << endl;
	cout << "************************* 欢迎来到演讲比赛系统*************" << endl;
	cout << "****************** 1.开始演讲比赛 ****************" << endl;
	cout << "******************* 2.查看往届比赛 *******************" << endl;
	cout << "******************** 3.清空比赛记录 *******************" << endl;
	cout << "******************* 0.退出比赛程序 **********************" << endl;
	cout << "**************************************************************" << endl;
}
void speakermanager::tuichu()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}
void speakermanager::chushihua()
{
	this->index = 1;
	this->v1.clear();
	this->v2.clear();
	this->winv.clear();
	this->m1.clear();
	this->m_record.clear();

}
void speakermanager::creatspeaker()
{
	string nameseed = "ABCDEFGHIJKL";
	for (int i = 0;i < nameseed.size();i++)
	{
		string name = "选手";
		name += nameseed[i];
		speaker sp;
		sp.name = name;
		for (int j = 0;j < 2;j++)
		{
			sp.score[j] = 0;
		}
		//this->v1.push_back(sp);
		int id = i + 10001;
		this->v1.push_back(i+10001);
		this->m1.insert(make_pair(i + 10001, sp));
	}
}
void speakermanager::startcontest()
{
	this->chouqian();
	this->kaishibisai();
	this->showjinjizhe();
	this->chouqian();
	this->kaishibisai();
	this->showjinjizhe();
	this->saverecord();
	this->chushihua();
	this->creatspeaker();
	this->loadrecord();
	cout << "----------------------------------------- 本届比赛完毕----------------------------------" << endl;
	system("pause");
	system("cls");

}
void speakermanager::chouqian()
{
	cout << "第" << this->index << "轮的选手正在抽签" << endl;

	cout << "抽签的结果如下:" << endl;
	cout << "--------------------------------------------------" << endl;
	if (this->index == 1)
	{
		random_device rd;
		mt19937 gen(rd());
		shuffle(this->v1.begin(), this->v1.end(), gen);
		for (vector<int>::iterator it = this->v1.begin();it != this->v1.end();it++)
		{
			cout << *it << "  ";
		}

		cout << endl;
	}
	else
	{
		random_device rd;
		mt19937 gen(rd());
		shuffle(this->v2.begin(), this->v2.end(), gen);
		for (vector<int>::iterator it = this->v2.begin();it != this->v2.end();it++)
		{
			cout << *it << "  ";
		}

		cout << endl;
	}
	cout << "------------------------------------------------------------" << endl;
	system("pause");

}
void speakermanager::kaishibisai()
{
	cout << "-------------------------第" << this->index << "轮正式比赛开始" << endl;
	multimap <double, int, greater<double>>groudmap;
	vector<int>temp;
	int num = 0;
	if (this->index == 1)
	{
		temp = this->v1;
	}
	else
	{
		temp = this->v2;
	}
	for (vector<int>::iterator it=temp.begin ();it!=temp.end();it++)
	{
		num++;
		deque<double>d;
		for (int i = 0;i < 10;i++)
		{
			double score = (rand() % 601 + 400) / 10.f;
			d.push_back(score);
		}
		sort(d.begin(), d.end(), greater<double>());
		d.pop_front();
		d.pop_back();
		double sum = accumulate(d.begin(), d.end(), 0);
		double avg = sum / (double)d.size();
		//cout << *it << this->m1[*it].name << "  " << avg << endl;
		this->m1[*it].score[this->index - 1] = avg;
		groudmap.insert(make_pair(avg, *it));
		if (num % 6 == 0)
		{
			cout << "第" << num / 6 << "小组比赛名次" << endl;
			for (multimap <double, int, greater<double>>::iterator it = groudmap.begin();it != groudmap.end();it++)
			{
				cout << it->second << "  " << this->m1[it->second].name << "  "
					<< this->m1[it->second].score[this->index - 1] << endl;
			}
			int count = 0;
			for (multimap <double, int, greater <double>>::iterator it = groudmap.begin();it != groudmap.end() && count < 3;it++, count++)
			{
				if (this->index == 1)
				{
					v2.push_back((*it).second);
				 }
				else
				{
					winv.push_back((*it).second);
				}
			}
			groudmap.clear();
			cout << endl;
		}

	}
	cout << "-------------------------------第" << this->index << "轮比赛完毕--------------------------------" << endl;
	system("pause");


}
void speakermanager::showjinjizhe()
{
	if (this->index == 1)
	{
		cout << "第一轮晋级的选手" << endl;
		for (vector<int>::iterator it = this->v2.begin();it != this->v2.end();it++)
		{
			cout << "编号:" << *it << " " << "姓名:" << this->m1[*it].name << " " << "得分:" << this->m1[*it].score[0] << endl;
		}
		this->index++;
	}
	else
	{
		cout << "最终获胜的选手" << endl;
		string name[3] = { "冠军","亚军","季军"};
		int num = 0;
		for (vector<int>::iterator it = this->winv.begin();it != this->winv.end()&&num<this->winv .size ();it++,num++)
		{
			cout << name[num] << endl;
			cout << "编号:" << *it << "  " << "姓名:" << this->m1[*it].name << "得分:"<< this->m1[*it].score[1] << endl;
		}
	
	}
	cout << endl;

	system("pause");
	system("cls");
	this->printmenu();
}
void speakermanager::saverecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out|ios::app);
	for (vector<int>::iterator it = this->winv.begin();it != this->winv.end();it++)
	{
		ofs << *it << "," << this->m1[*it].score[1] << ",";
	}
	ofs << endl;
	ofs.close();
	cout << "记录已保存" << endl;
	this->isempty = false;

}
void speakermanager::loadrecord()
{
	ifstream ifs("speech.csv", ios::in);
	if (!ifs.is_open())
	{
		this->isempty = true;
		//cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		this->isempty = true;
		//cout << "文件为空" << endl;
		ifs.close();
		return;
	}
	this->isempty = false;
	ifs.putback(ch);
	string date;
	int index = 0;


	while (ifs >> date)
	{
		//cout << date << endl;
		vector<string>v;
		int pos = -1;
		int start = 0;
		while (true)
		{
			pos = date.find(",", start);
			if (pos == -1)
			{
				break;
			}
			string temp = date.substr(start, pos - start);
			//cout << temp << endl;
			v.push_back(temp);

			start = pos + 1;
		}
		this->m_record.insert(make_pair(index, v));
		index++;

	}

	ifs.close();
	//for (map<int, vector<string>>::iterator it = m_record.begin();it != m_record.end();it++)
	//{
	//	cout << it->first << "冠军编号:" << it->second[0] << "分数:" << it->second[1] << endl;
	//}
}
void speakermanager::showrecord()
{
	if (this->isempty)
	{
		cout << "文件为空或者不存在" << endl;
	}
	else
	{
		for (int i = 0;i < this->m_record.size();i++)
		{
			cout << "第" << i + 1 << "届" <<
				"冠军编号:" << this->m_record[i][0] << "得分:" << this->m_record[i][1] <<
				"亚军编号: " << this->m_record[i][2] << "得分:" << this->m_record[i][3] <<
				"季军编号: " << this->m_record[i][4] << "得分:" << this->m_record[i][5] << endl;
		}
	}

	system("pause");
	system("cls");
}
void speakermanager::qingkong()
{
	cout << "确定清空?" << endl;
	cout << "1.确定" << endl;
	cout << "2.返回" << endl;
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();
		this->chushihua();
		this->creatspeaker();
		this->loadrecord();
		cout << "清空成功" << endl;
	}
	system("pause");
	system("cls");

}