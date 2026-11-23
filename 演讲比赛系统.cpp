#define _HAS_STD_BYTE 0
#include "speakermanager.h"
#include <iostream>
#include<windows.h>
#include <ctime>
using namespace std;
int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	srand((unsigned int)time(NULL));
	int choice = 0;
	speakermanager s1;
	while (true)
	{
		s1.printmenu();
		cin >> choice;
		switch (choice)
		{
		case 1:
			s1.startcontest();
			break;
		case 2:
			s1.showrecord();
			break;
		case 3:
			s1.qingkong();
			break;
		case 0:
			s1.tuichu();
			break;
		default:
			cout << "输入错误请重新输入" << endl;
			system("pause");
			system("cls");
			
		}
	}

	 system("pause");
	 return 0;
}
