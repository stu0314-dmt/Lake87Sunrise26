#include<iostream>
#define MAX 1000
#include<string>

#include<windows.h>
#include<cstdlib>
#include <algorithm>
#include <ctime>
using namespace std;

struct student
{
	string id;

	string name;
	int grade;
};
struct studentgrade
{
	struct student stu[MAX];
	int m_size;
};
void addstudent(studentgrade* all)
{
	if (all->m_size == MAX)
	{
		cout << "空间已满无法添加" << endl;
		return;
	
	}
	else
	{
		cout << "请输入学号:" << endl;
		string id;
		cin >> id;
		all->stu[all->m_size].id = id;
		cout << "请输入姓名:" << endl;
		string name;
		cin >> name;
		all->stu[all->m_size].name = name;
		cout << "请输入分数:" << endl;
		int grade;
		cin >> grade;
		all->stu[all->m_size].grade = grade;
		cout << "添加成功" << endl;
		all->m_size++;
		
	}
	system("pause");
	system("cls");
}
void showstudent(studentgrade* all)
{
	if (all->m_size == 0)
	{
		cout << "当前没有学生成绩,请去输入学生成绩" << endl;
	}
	else
	{
		for (int i = 0;i <all->m_size;i++)
		{
			cout << "学号:" << all->stu[i].id << "\t";
			cout << "姓名:" << all->stu[i].name << "\t";
			cout << "分数:" << all->stu[i].grade << endl;
		}
	}
	system("pause");
	system("cls");
}
int checkstudent(studentgrade* all, string name)
{
	
	for (int i = 0;i < all->m_size;i++)
	{
		if (all->stu[i].name == name)
		{
			return i;
		}

	}
	return -1;
}
void findstudent(studentgrade* all)
{
	cout << "请输入你要查找的学生:" << endl;
	string name;
	cin >> name;
	int ret = checkstudent(all, name);
	if (ret != -1)
	{
		cout << "学号:" << all->stu[ret].id << "\t";
		cout << "姓名:" << all->stu[ret].name << "\t";
		cout << "分数:" << all->stu[ret].grade << endl;
	}
	else
	{
		cout << "查无此人,请重新输入" << endl;
	}
	system("pause");
	system("cls");
}
void deletestudent(studentgrade* all)
{
	cout << "请输入你要删除的学生:" << endl;
	string name;
	cin >> name;
	int ret = checkstudent(all, name);
		if (ret != -1)
		{
			for (int i = ret;i < all->m_size-1;i++)
			{
				all->stu[i] = all->stu[i + 1];
				
				
			}
			cout << "删除成功" << endl;
			all->m_size--;
		}
		else
		{
			cout << "查无此人,请重新输入" << endl;
		}
		system("pause");
		system("cls");
}
void changestudent(studentgrade* all)
{
	cout << "请输入你要修改的学生的名字:" << endl;
	string name;
	cin >> name;
	int ret = checkstudent(all, name);
	if (ret != -1)
	{
		cout << "请重新输入成绩:" << endl;
		int grade;
		cin >> grade;
		all->stu[ret].grade = grade;
	
		cout << "修改成功" << endl;
	}
	else
	{
		cout << "查无此人,请重新输入" << endl;
	}
	system("pause");
	system("cls");
}
void showmenu()
{
	cout << "学生成绩管理系统" << endl;
	cout << "*********  1.添加学生信息  *********" << endl;
	cout << "********  2.显示全部学生  ******" << endl;
	cout << "********  3.按学号查找学生  *******" << endl;
	cout << "********  4.删除学生  *******" << endl;
	cout << "********  5.修改学生成绩  *******" << endl;
	cout << "********  0.退出系统  *******" << endl;


}


int  main() 
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	int select = 0;
	struct studentgrade all;
	all.m_size = 0;

	while (true)
	{
		showmenu();
		cin >> select;
		switch (select)
		{
		case 1:
			addstudent(&all);
			break;
		case 2:
			showstudent(&all);
			break;
		case 3:
			findstudent(&all);
			break;
		case 4:
			deletestudent(&all);
			break;
		case 5:
			changestudent(&all);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入错误,请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}


	system("pause");

	return 0;
}