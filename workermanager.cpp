#include "workermanager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include <cassert>
#include <iostream>

using namespace std;

workermanager::workermanager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		/*cout << "文件不存在" << endl;*/
		this->m_empnum = 0;
		this->m_emparray = NULL;
		this->m_fileisempty = true;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		/*cout << "文件不存在" << endl;*/
		this->m_empnum = 0;
		this->m_emparray = NULL;
		this->m_fileisempty = true;
		ifs.close();
		return;
	}
	int num = this->get_num();
	//cout << "职工人数为" << num << "人" << endl;
	this->m_empnum = num;
	this->m_emparray = new worker * [this->m_empnum];
	this->initialnum();
	//for (int i = 0;i < this->m_empnum;i++)
	//{
	//	cout << "职工编号:" << this->m_emparray[i]->m_id <<
	//		"  " << "职工姓名:" << this->m_emparray[i]->m_name <<
	//		" " << "职工岗位:" << this->m_emparray[i]->m_deptid << endl;
	//}

}
void workermanager::initialnum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		worker* worker = NULL;
		if (did == 1)
		{
			worker = new employee(id, name, did);
		}
		else if(did==2)
		{
			worker = new manager(id, name, did);
		}
		else
		{
			worker = new boss(id, name, did);
		}
		this->m_emparray[index] = worker;
		index++;
	}
	ifs.close();
}
void workermanager::showyuangong()
{
	if (this->m_fileisempty)
	{
		cout << "文件为空或者不存在" << endl;
	}
	else
	{
		for (int i = 0;i < this->m_empnum;i++)
		{
			this->m_emparray[i]->show();
		}
	}
	system("pause");
	system("cls");

}
int  workermanager::yuangongcunzai(int id)
{
	int index = -1;
	for (int i = 0;i < this->m_empnum;i++)
	{
		if (this->m_emparray[i]->m_id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}
void workermanager::shanchuyuangong()
{
	if (this->m_fileisempty)
	{
		cout << "文件不存在或为空" << endl;
	}
	else
	{
		int id;
		cout << "请输入你要删除员工的编号" << endl;
		cin >> id;
		int ret = this->yuangongcunzai(id);
		if (ret != -1)
		{
			for (int i = ret;i < this->m_empnum-1;i++)
			{
				this->m_emparray[i] = this->m_emparray[i + 1];
			}
			cout << "删除成功" << endl;
			this->m_empnum--;
			this->save();
		}
		else
		{
			cout << "查无此人" << endl;
		}
	
	}
	
	system("pause");
	system("cls");
	
}
void workermanager::xiugaizhigong()
{
	if (this->m_fileisempty)
	{
		cout << "文件不存在或为空" << endl;
	}
	else
	{
		int id;
		cout << "请输入你要修改的职工的编号" << endl;
		cin >> id;
		int ret = this->yuangongcunzai(id);
		if (ret != -1)
		{
			int ID;
			string name;
			int did;
			cout << "请输入新的编号:" << endl;
			cin >> ID;
			this->m_emparray[ret]->m_id = ID;
			cout << "请输入新的姓名:" << endl;
			cin >> name;
			this->m_emparray[ret]->m_name = name;
			cout << "请输入新的岗位:" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.总裁" << endl;
			cin >> did;
			worker* worker = NULL;
			switch (did)
			{
			case 1:
				worker = new employee(ID, name, did);
				break;
			case 2:
				worker = new manager(ID, name, did);
				break;
			case 3:
				worker = new boss(ID, name, did);
				break;
			default:
				cout << "输入错误,请重新输入" << endl;
				break;
			}
			this->m_emparray[ret] = worker;
			this->save();
			cout << "修改成功" << endl;

		}
		else
		{
			cout << "查无此人" << endl;
		}
	}
	system("pause");
	system("cls");
}
void workermanager::chazhaoyuangong()
{
	if (this->m_fileisempty)
	{
		cout << "文件不存在或为空" << endl;
	}
	else
	{
		int choice;
		cout << "请选择查找方式:" << endl;
		cout << "1.按编号查找" << endl;
		cout << "2.按姓名查找" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			int ID;
			cout << "请输入你要查找的员工的编号:" << endl;
			cin >> ID;
			int ret = this->yuangongcunzai(ID);
			if (ret != -1)
			{
				this->m_emparray[ret]->show();
			}
			else
			{
				cout << "查无此人" << endl;
			}
		}
			break;
		case 2:
		{
			string name;
			cout << "请输入你要查找的员工的姓名:" << endl;
			cin >> name;
			bool flag = false;
			for (int i = 0;i < this->m_empnum ;i++)
			{
				if (this->m_emparray[i]->m_name == name)
				{
					this->m_emparray[i]->show();
					flag = true;
					cout << endl;
				}
		
			}
			if (flag == false)
			{
				cout << "查无此人" << endl;
			}
			
		}
			break;
		default :
			cout << "输入错误,请重新输入" << endl;
			break;
		}
	}
	system("pause");
	system("cls");
}
void workermanager::yuangongpaixu()
{
	for (int i = 0;i < this->m_empnum - 1;i++)
	{
		for (int j = 0;j < this->m_empnum - i - 1;j++)
		{
			if (this->m_emparray[j]->m_id > this->m_emparray[j + 1]->m_id)
			{
				worker* temp = this->m_emparray[j];
				this->m_emparray[j] = this->m_emparray[j + 1];
				this->m_emparray[j + 1] = temp;
			}
		}
	}
	cout << "排序成功" << endl;
	this->save();
	system("pause");
	system("cls");
}
void workermanager::qingkongwenjian()
{
	cout << "确定清空吗" << endl;
	cout << "1.确定" << endl;
	cout << "2.返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);
			ofs.close();
		if (this->m_emparray != NULL)
		{
			for (int i = 0;i < this->m_empnum;i++)
			{
				delete this->m_emparray[i];
				this->m_emparray[i] = NULL;

			}
			delete[]this->m_emparray;
			this->m_emparray = NULL;
			this->m_empnum = 0;
			this->m_fileisempty = true;

		}
		cout << "清空成功" << endl;
	}
	system("pause");
	system("cls");

}
workermanager::~workermanager()
{
	if (this->m_emparray != NULL)
	{
		for (int i = 0;i < this->m_empnum;i++)
		{
			if (this->m_emparray[i] != NULL)
			{
				delete this->m_emparray[i];
			}
		}
		delete[] this->m_emparray;
		this->m_emparray = NULL;
	}
}
void workermanager::addyuangong()
{
	int addnum = 0;
	cout << "请输入你要加入的员工的数量" << endl;
	cin >> addnum;
	if (addnum > 0)
	{
		int newsize = this->m_empnum + addnum;
		worker** newspace = new worker * [newsize];
		if (this->m_emparray != NULL)
		{
			for (int i = 0;i < this->m_empnum;i++)
			{
				newspace[i] = this->m_emparray[i];
			}

		}
		for (int i = 0;i < addnum;i++)
		{
			int id;
			string name;
			int deptid;
			cout << "请输入第" << i+1 << "位新员工的编号:" << endl;
			cin >> id;
			cout << "请输入第" << i+1 << "位新员工的姓名:" << endl;
			cin >> name;
			cout << "请输入第" << i+1 << "位新员工的岗位:" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.总裁" << endl;
			cin >> deptid;
			worker* worker = NULL;
			bool ok = true;
			switch (deptid)
			{
			case 1:
				worker = new employee(id, name, deptid);
				break;
			case 2:
				worker = new manager(id, name, deptid);
				break;
			case 3:
				worker = new boss(id, name, deptid);
				break;
			default:
				cout << "输入错误,请重新输入" << endl;
				ok = false;
				break;

			}
			if (ok)
			{
				int idx = this->m_empnum + i;
				assert(idx < newsize);
				newspace[this->m_empnum + i] = worker;
			}
			
		}
		
		delete[]this->m_emparray;
		this->m_emparray = newspace;
		this->m_empnum = newsize;
		this->m_fileisempty = false;
		cout << "添加成功" << addnum << "位新员工" << endl;
		this->save();
	}
		else
		{
			cout << "输入错误请重新输入" << endl;
		}
		system("pause");
		system("cls");

}
void workermanager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0;i < this->m_empnum;i++)
	{
		ofs << this->m_emparray[i]->m_id << "  "<<
			this->m_emparray[i]->m_name << "  "<<
			this->m_emparray[i]->m_deptid << endl;

	}
	ofs.close();

}
int workermanager::get_num()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		num++;
	}
	return num;
	ifs.close();

}
void workermanager::show_menu()
{
	cout << "***********************************************" << endl;
	cout << "****************欢迎使用职工管理系统 ***************"<< endl;
	cout << "*****************  0.退出管理程序  *****************" << endl;
	cout << "***************** 1.增加职工信息  *****************" << endl;
	cout << "****************** 2.显示职工信息  *****************" << endl;
	cout << "******************* 3.删除离职职工 ******************" << endl;
	cout << "******************* 4.修改职工信息 *******************" << endl;
	cout << "******************* 5.查找职工信息 ********************" << endl;
	cout << "********************* 6.按照编号排序 *******************" << endl;
	cout << "********************** 7.清空所有文档 ********************" << endl;
	cout << "***************************************************************" << endl;
	cout << endl;
}
void workermanager::exitsystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}