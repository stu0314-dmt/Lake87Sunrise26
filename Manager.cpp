#pragma once
#include <string >
#include "Manager.h"
#include <iostream>
#include <fstream>
#include "globalfile.h"
#include <algorithm>
using namespace std;
manager::manager()
{

}
manager::manager(string name, string pwd)
{
	this->m_name = name;
	this->m_pwd = pwd;
	this->initvector();
	ifstream ifs;
	ifs.open(COMPUTER, ios::in);
	if (!ifs.is_open())
	{
		cout << "打开文件失败" << endl;
		return;
	}
	else
	{
		computerroom c;
		while (ifs >> c.m_id && ifs >> c.m_num)
		{
			vcom.push_back(c);
		}
		cout << "现在有" << vcom.size() << "个机房" << endl;
		ifs.close();
	}
}
void manager::showmenu()
{
	cout << "欢迎管理员" << this->m_name << "登录" << endl;
	cout << "\t\t----------------------------------------------------\n";
	cout << "\t\t|                                                   |\n";
	cout << "\t\t|                1.添加账号                          |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                 2.查看账号                           |\n";
	cout << "\t\t|                                                        |\n";
	cout << "\t\t|                   3.查看机房                             |\n";
	cout << "\t\t|                                                             |\n";
	cout << "\t\t|                     4.清空预约                                |\n";
	cout << "\t\t|                                                                 |\n";
	cout << "\t\t|                       0.注销登录                                  |\n";
	cout << "\t\t|                                                                    |\n";
	cout << "\t\t-----------------------------------------------------------------\n";
	cout << "请输入您的操作:" << endl;
 }
manager::~manager()
{

 }
void manager::addzhanghao()
{
	cout << "请输入你要添加的人员身份:" << endl;
	cout << "1.学生" << endl;
	cout << "2.老师" << endl;
	string filename;
	string tips;
	string errortips;
	int choice = 0;
	cin >> choice;
	if (choice == 1)
	{
		filename = STUDENT_FILE;
		errortips = "学号重复,请重新输入";
		tips = "请输入学号:";
	}
	else if (choice == 2)
	{
		filename = TEACHER_FILE;
		tips = "请输入教师编号:";
		errortips = "编号重复,请重新输入";
	}
	else
	{
		cout << "输入选项错误" << endl;
		system("pause");
		system("cls");
		return;
	}
	ofstream ofs;
	ofs.open(filename, ios::out | ios::app);
	cout << "正在打开文件" << filename << endl;
	if (!ofs.is_open())
	{
		cout << "文件打开失败" << endl;
		system("pause");
		system("cls");
		return;
	}
	int id;
	string name;
	string pwd;

		
		cout << tips << endl;
		while (true)
		{
			cin >> id;
			bool ret = this->checkrepeat(id, choice);
			if (ret)
			{
				cout << errortips << endl;
			}
			else
			{
				break;
			}
		}



	cout << "请输入姓名:" << endl;
	cin >> name;
	cout << "请输入密码:" << endl;
	cin >> pwd;
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功" << endl;
	this->initvector();
	system("pause");
	system("cls");
	ofs.close();

}
void printstu(student& s)
{
	cout << "学号:" << s.m_id << " " << "姓名:" << s.m_name << "  " << "密码:" << s.m_pwd << endl;
}
void printtea(teacher& s)
{
	cout << "职工编号:" << s.m_id << " " << "姓名:" << s.m_name << "  " << "密码:" << s.m_pwd << endl;
}
void manager::chakanzhanghao()
{
	cout << "请选择需要查看的信息:" << endl;
	cout << "1.查看所有学生的信息:" << endl;
	cout << "2.查看所有老师的信息:" << endl;
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		cout << "以下是学生的信息:" << endl;
		for_each(this->vstu.begin(), this->vstu.end(), printstu);
	}
	else
	{
		cout << "以下是教师的信息:" << endl;
		for_each(this->vtea.begin(), this->vtea.end(), printtea);
	}
	system("pause");
	system("cls");
}
void printcomputer(computerroom&c)
{
	cout << "机房编号:" << c.m_id << " " << "机房所能容纳的人数:" << c.m_num << " " << endl;
}
void manager::chakanjifangxinxi()
{
	cout << "以下是机房的信息:" << endl;
	for_each(vcom.begin(), vcom.end(), printcomputer);
	system("pause");
	system("cls");
}
void manager::qingkongjilu()
{
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);
	if (!ofs.is_open())
	{
		cout << "打开文件失败" << endl;
		return;
	}
	else
	{
		ofs.close();
		cout << "清空成功" << endl;
		system("pause");
		system("cls");
	}
}
void manager::initvector()
{
	//this->vstu.clear();
	//this->vtea.clear();
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	//int id;
	//string name;
	//string pwd;
	student s;
	teacher t;
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	else
	{
		vstu.clear();
		vtea.clear();
		while (ifs>>s.m_id&&ifs>>s.m_name&&ifs>>s.m_pwd)
		{
			vstu.push_back(s);
		}
		cout << "现在学生人数:" << vstu.size() << endl;
		ifs.close();
	}

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "打开文件失败" << endl;
		return;
	}
	else
	{
		while (ifs >> t.m_id && ifs >> t.m_name && ifs >> t.m_pwd)
		{
			vtea.push_back(t);
		}
		cout << "现在教师人数:" << vtea.size() << endl;
		ifs.close();
	}
}
bool manager::checkrepeat(int id, int type)
{
	if (type == 1)
	{
		for (vector<student>::iterator it = vstu.begin();it != vstu.end();it++)
		{
			if (it->m_id == id)
			{
				return true;
			}
		}
	}
	else
	{
		for (vector<teacher>::iterator it = vtea.begin();it != vtea.end();it++)
		{
			if (it->m_id == id)
			{
				return true;
			}
		}
	}
	return false;
}