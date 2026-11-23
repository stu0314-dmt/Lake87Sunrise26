#include<iostream>
#include<string>

#include<windows.h>
#include<cstdlib>
#include <algorithm>
#include <ctime>
#include <fstream>
#include "workermanager.h"
#include "boss.h"
#include "employee.h"
#include "manager.h"
#include "worker.h"

using namespace std;


int  main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	
	workermanager wm;
	int choice = 0;

	while (true)
	{
		wm.show_menu();
		cout << "请输入你的选择" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			wm.exitsystem();
			break;
		case 1:
			wm.addyuangong();
			break;
		case 2:
			wm.showyuangong();
			break;
		case 3:
			wm.shanchuyuangong();
			break;
		case 4:
			wm.xiugaizhigong();
			break;
		case 5:
			wm.chazhaoyuangong();
			break;
		case 6:
			wm.yuangongpaixu();
			break;
		case 7:
			wm.qingkongwenjian();
			break;
		default:
			
			system("cls");
			break;

		}

		//system("pause");
		//system("cls");
	}





	system("pause");

	return 0;
}