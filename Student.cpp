#pragma once
#include <iostream>
#include "student.h"
using namespace std;
#include <string>
#include "orderfile.h"
void student::showmenu()
{
	cout << "欢迎学生代表:" << this->m_name << "登录" << endl;
	cout << "\t\t-----------------------------------------------\n";
	cout << "\t\t|                                                |\n";
	cout << "\t\t|                   1.申请预约                    |\n";
	cout << "\t\t|                                                |\n";
	cout << "\t\t|                    2.查看我的预约                 |\n";
	cout << "\t\t|                                                |\n";
	cout << "\t\t|                      3.查看所有预约                |\n";
	cout << "\t\t|                                                |\n";
	cout << "\t\t|                       4.取消预约                         |\n";
	cout << "\t\t|                                                |\n";
	cout << "\t\t|                         0.注销登录                 |\n";
	cout << "\t\t|                                                |\n";
	cout << "\t\t-----------------------------------------------------\n";
	cout << "请输入你的操作:" << endl;
 }
student::student()
{
	

 }
student::student(int id, string name, string pwd)
{
	this->m_id = id;
	this->m_name = name;
	this->m_pwd = pwd;
	ifstream ifs;
	ifs.open(COMPUTER, ios::in);
	if (!ifs.is_open())
	{
		cout << "打开失败" << endl;
		system("pause");
		system("cls");
		return;
	}
	computerroom c;
	while (ifs >> c.m_id && ifs >> c.m_num)
	{
		vcom1.push_back(c);
	}
	ifs.close();
	
 }
void student::applyorder()
{
	cout << "机房可预约的时间为周一到周五,请输入你要预约的时间" << endl;
	cout << "1.周一" << endl;
	cout << "2.周二" << endl;
	cout << "3.周三" << endl;
	cout << "4.周四" << endl;
	cout << "5.周五" << endl;
	int xingqi = 0;
	while (true)
	{
		cin >> xingqi;
		if (xingqi >= 1 && xingqi <= 5)
		{
			break;
		}
		cout << "输入错误,请重新输入" << endl;
	}
	cout << "请输入你要预约的时间段" << endl;
	cout << "1.上午" << endl;
	cout << "2.下午" << endl;
	int time = 0;
	while (true)
	{
		cin >> time;
		if (time >= 1 && time<= 2)
		{
			break;
		}
		cout << "输入错误,请重新输入" << endl;
	}
	cout << "请输入你要预约的机房" << endl;
	for (int i = 0;i < 3;i++)
	{
		cout << this->vcom1[i].m_id << "号机房" << "可容纳" << this->vcom1[i].m_num << "人" << endl;
	}
	int comnum;
	while (true)
	{
		cin >> comnum;
		if (comnum >= 1 && comnum <= 3)
		{
			break;
		}
		cout << "输入错误,请重新输入" << endl;
	}
	cout << "预约成功,审核中" << endl;
	ofstream ofs;
	ofs.open(ORDER_FILE,ios::app);
	if (!ofs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	ofs << "date:" << xingqi << " ";
	ofs << "interval:" << time << " ";
	ofs << "stuid:" << this->m_id << " ";
	ofs << "stuname:" << this->m_name << " ";
	ofs << "roomid:" << comnum << " ";
	ofs << "stact:" << 1 << endl;
	ofs.close();
	system("pause");
	system("cls");

}
void student::showmyorder()
{
	Orderfile o1;
	if (o1.m_size == 0)
	{
		cout << "没有预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0;i < o1.m_size;i++)
	{
		cout << i + 1 << " ,";
		if (atoi(o1.m_orderdate[i]["stuid"].c_str()) == this->m_id)
		{
			cout << "预约日期: 周 " << o1.m_orderdate[i]["date"];
			cout << " 时段: " << (o1.m_orderdate[i]["interval"] == "1" ? "上午" : "下午");
			cout << " 机房: " << o1.m_orderdate[i]["roomid"];
			string status = " 状态: ";
			if (o1.m_orderdate[i]["stact"] == "1")
			{
				status += "审核中";
			}
			else if (o1.m_orderdate[i]["stact"] == "2")
			{
				status += "已预约";
			}
			else if (o1.m_orderdate[i]["stact"] == "-1")
			{
				status += "预约失败";
			}
			else if (o1.m_orderdate[i]["stact"] == "0")
			{
				status += "预约已取消";
			}
			cout << status << endl;

		}
	}
	system("pause");
	system("cls");

}
void student::showallorder()
{
	Orderfile of;
	if (of.m_size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0;i < of.m_size;i++)
	{
		cout << i + 1 << ", ";
		cout << "预约日期: 周 " << of.m_orderdate[i]["date"];
		cout << " 时段: " << (of.m_orderdate[i]["interval"] == "1" ? "上午" : "下午");
		cout << " 学生学号: " << of.m_orderdate[i]["stuid"];
		cout << " 学生姓名: " << of.m_orderdate[i]["stuname"];
		cout << " 机房编号: " << of.m_orderdate[i]["roomid"];
		string status = " 状态: ";
		if (of.m_orderdate[i]["stact"] == "1")
		{
			status += "审核中";
		}
		else if (of.m_orderdate[i]["stact"] == "2")
		{
			status += "预约成功";
		}
		else if (of.m_orderdate[i]["stact"] == "-1")
		{
			status += "预约未通过";
		}
		else if (of.m_orderdate[i]["stact"] == "0")
		{
			status += "预约已取消";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}
void student::cancelorder()
{
	Orderfile of;
	if (of.m_size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "审核中或预约成功的记录可以取消,请输入取消的记录" << endl;
	vector<int>v;
	int index = 1;
	for (int i = 0;i < of.m_size;i++)
	{

		if (atoi(of.m_orderdate[i]["stuid"].c_str()) == this->m_id)
		{
			if (of.m_orderdate[i]["stact"] == "1" || of.m_orderdate[i]["stact"] == "2")
			{
				v.push_back(i);
				cout << index++ << ", ";
				cout << "预约日期: 周 " << of.m_orderdate[i]["date"];
				cout << " 时段: " << (of.m_orderdate[i]["interval"] == "1" ? "上午" : "下午");
				cout << " 机房编号:" << of.m_orderdate[i]["roomid"];
				string status = " 状态:";
				if (of.m_orderdate[i]["stact"] == "1")
				{
					status += "审核中";
				}
				else if (of.m_orderdate[i]["stact"] == "2")
				{
					status += "预约成功";
				}
				cout << status << endl;
				
				
			}
		}
	}
	cout << "请输入你要取消的预约,输入0返回" << endl;
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				of.m_orderdate[v[select - 1]]["stact"] = "0";
				of.updateorder();
				cout << "取消成功" << endl;
				break;
			}
		}
		cout << "输入有误,请重新输入" << endl;
	}
	system("pause");
	system("cls");

}
student::~student()
{

}