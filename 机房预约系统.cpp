#define _HAS_STD_BYTE 0
#include<iostream>
#include<windows.h>
#include <fstream>
#include "globalfile.h"
#include "Student.h"
#include "Manager.h"
#include "Teacher.h"
#include <string>
using namespace std;
void studentmenu(Identity* &manager)
{
	while (true)
	{
		manager->showmenu();
		student* stu = (student*)manager;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			stu->applyorder();
		}
		else if (select == 2)
		{
			stu->showmyorder();

		}
		else if (select == 3)
		{
			stu->showallorder();

		}
		else if (select == 4)
		{
			stu->cancelorder();
		}
		else if (select == 0)
		{
			delete stu;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "输入错误,请重新输入" << endl;
			system("pause");
			system("cls");
		}
	
	}
}
void teachermenu(Identity*& personn)
{
	while (true)
	{
		personn->showmenu();
		teacher* tea = (teacher*)personn;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			tea->showallorder();
		}
		else if (select == 2)
		{
			tea->validorder();
		}
		else if (select == 0)
		{
			delete tea;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "输入错误,请重新输入" << endl;
			system("pause");
			system("cls");

		}

	}
}
void managermenu(Identity *&manage)
{
	while (true)
	{
		manage->showmenu();
		manager* man = (manager*)manage;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			man->addzhanghao();
		}
		else if (select == 2)
		{
			man->chakanzhanghao();

		}
		else if (select == 3)
		{
			man->chakanjifangxinxi();
		}
		else if (select == 4)
		{
			man->qingkongjilu();
		}
		else if (select == 0)
		{
			delete manage;
			cout << "注销登录成功" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "输入错误,请重新输入" << endl;
			system("pause");
			system("cls");
			
		}
	}

}
void denglurukou(string filename, int type)
{
	Identity* person = NULL;
	ifstream ifs;
	ifs.open(filename, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	int id = 0;
	string name;
	string pwd;

	if (type == 1)
	{
		cout << "请输入你的学号:" << endl;
		cin >> id;

	}
	else if (type == 2)
	{
		cout << "请输入你的职工号:" << endl;
		cin >> id;
	}
	cout << "请输入用户名:" << endl;
	cin >> name;
	cout << "请输入密码:" << endl;
	cin >> pwd;
	if (type == 1)
	{
		int fid;
		string fname;
		string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			if (id == fid && name == fname && pwd == fpwd)
			{
				cout << "学生身份登陆成功" << endl;
				system("pause");
				system("cls");
				person = new student(id, name, pwd);
				studentmenu(person);
				return;
			}
		}
	}
	else if (type==2)
	{
		int fid;
		string fname;
		string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			if (id == fid && name == fname && pwd == fpwd)
			{
				cout << "教师身份认证成功" << endl;
				system("pause");
				system("cls");
				person = new teacher(id, name, pwd);
				teachermenu(person);
				return;
			}
		}
		
	}
	else if (type == 3)
	{
		string fname;
		string fpwd;
		while (ifs >> fname && ifs >> fpwd)
		{
			if (name == fname && pwd == fpwd)
			{
				cout << "管理员身份认证成功" << endl;
				system("pause");
				system("cls");
				person = new manager(name, pwd);
				managermenu(person);
				return;
			}
		}
	}

	cout << "验证登录失败!" << endl;
	system("pause");
	system("cls");
	return;
}
int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	int choice;


	while (true)
	{
		cout << "------------------------------------------------" << endl;
		cout << "----------------------欢迎来到机房预约系统------------" << endl;
		cout << "-----------------------------------------------------------" << endl;
		cout << "-------------------------- 1.学生---------------------------" << endl;
		cout << "----------------------------2.老师----------------------------" << endl;
		cout << "-----------------------------3.管理员----------------------------" << endl;
		cout << "-------------------------------0.退出系统-------------------------" << endl;
		cout << "请输入您的身份:" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			denglurukou(STUDENT_FILE , 1);
			break;
		case 2:
			denglurukou(TEACHER_FILE , 2);
			break;
		case 3:
			denglurukou(ADMIN_FILE , 3);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			system("cls");
				return 0;
		default :
			cout << "输入有误,请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}

	}
	system("pause");
	return 0;
}