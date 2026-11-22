#pragma once
#include <iostream>
#include "Teacher.h"
#include "globalfile.h"
#include "orderfile.h"
using namespace std;
#include <string>
teacher::teacher()
{

}
teacher::teacher(int id, string name, string pwd)
{
	this->m_id = id;
	this->m_name = name;
	this->m_pwd = pwd;
}
void teacher::showmenu()
{
	cout << "欢迎教师: " << this->m_name << "登录!" << endl;
	cout << "\t\t---------------------------------------------------\n";
	cout << "\t\t|                                                   |\n";
	cout << "\t\t|                    1.查看所有预约                  |\n";
	cout << "\t\t|                                                   |\n";
	cout << "\t\t|                     2.审核预约                      |\n";
	cout << "\t\t|                                                   |\n";
	cout << "\t\t|                      0.注销登录                       |\n";
	cout << "\t\t|                                                   |\n";
	cout << "\t\t---------------------------------------------------------\n";
	cout << "请输入你的操作:" << endl;
 }
 void teacher::showallorder()
 {
	 Orderfile of;
	 if (of.m_size == 0)
	 {
		 cout << "记录为空,没有预约" << endl;
		 system("pause");
		 system("cls");
		 return;
	 }
	 for (int i = 0;i < of.m_size;i++)
	 {
		 cout << i + 1 << ", ";
		 cout << "预约日期: 周" << of.m_orderdate[i]["date"];
		 cout << " 时段: " << (of.m_orderdate[i]["interval"] == "1" ? "上午" : "下午");
		 cout << " 学生编号: " << of.m_orderdate[i]["stuid"];
		 cout << " 学生姓名: " << of.m_orderdate[i]["stuname"];
		 cout << " 机房编号: " << of.m_orderdate[i]["roomid"];
		 string status = " 状态: ";
		 if (of.m_orderdate[i]["stact"] == "1")
		 {
			 status += "审核中";
		 }
		 else if (of.m_orderdate[i]["stact"] == "2")
		 {
			 status += "预约通过";
		 }
		 else if (of.m_orderdate[i]["stact"] == "-1")
		 {
			 status += "预约失败";

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
void teacher::validorder()
{
	Orderfile of;
	if (of.m_size == 0)
	{
		cout << "预约记录为空" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "待审核的预约记录如下:" << endl;

	vector<int>v;
	int index = 0;
	for (int i = 0;i < of.m_size;i++)
	{
		if (of.m_orderdate[i]["stact"] == "1")
		{
			v.push_back(i);
			cout << ++index << ", ";
			cout << "预约日期: 周" << of.m_orderdate[i]["date"];
			cout << " 时段: " << (of.m_orderdate[i]["interval"] == "1" ? "上午" : "下午");
			cout << " 学生编号: " << of.m_orderdate[i]["stuid"];
			cout << " 学生姓名: " << of.m_orderdate[i]["stuname"];
			cout << " 机房编号: " << of.m_orderdate[i]["roomid"];
			string status = " 状态: 审核中";

			cout << status << endl;

		}
	}
	cout << "请输入审核的预约记录,0代表返回" << endl;
	int select = 0;
	int ret = 0;
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
				cout << "请输入审核结果:" << endl;
				cout << "1.通过" << endl;
				cout << "2.不通过" << endl;
				cin >> ret;
				if (ret == 1)
				{
					of.m_orderdate[v[select - 1]]["stact"] = "2";
				}
				else
				{
					of.m_orderdate[v[select - 1]]["stact"] = "-1";
				}
				of.updateorder();
				cout << "审核完毕";
				break;
			}
		}
		cout << "输入有误,请重新输入" << endl;
	}
	system("pause");
	system("cls");

}
teacher::~teacher()
{

}