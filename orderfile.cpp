#include <iostream>

#include "orderfile.h"
using namespace std;
Orderfile::Orderfile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	string date;
	string interval;
	string stuid;
	string stuname;
	string roomid;
	string stact;

	this->m_size = 0;

	while (ifs >> date && ifs >> interval && ifs >> stuid && ifs >> stuname && ifs >> roomid && ifs >> stact)
	{
		//cout << date << " " << interval << " " << stuid << " " << stuname << " " << roomid << " " << stact << " " << endl;
		string key;
		string value;
		map<string, string>m;
		int pos;
		pos = date.find(":");
		if (pos != -1)
		{
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		pos = interval.find(":");
		if (pos != -1)
		{
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		pos = stuid.find(":");
		if (pos != -1)
		{
			key = stuid.substr(0, pos);
			value = stuid.substr(pos + 1, stuid.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		pos = stuname.find(":");
		if (pos != -1)
		{
			key = stuname.substr(0, pos);
			value = stuname.substr(pos + 1, stuname.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		pos = roomid.find(":");
		if (pos != -1)
		{
			key = roomid.substr(0, pos);
			value = roomid.substr(pos + 1, roomid.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		pos = stact.find(":");
		if (pos != -1)
		{
			key = stact.substr(0, pos);
			value = stact.substr(pos + 1, stact.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		this->m_orderdate.insert(make_pair(this->m_size, m));
		this->m_size++;
		}

		

	
	ifs.close();
	//for (map<int, map<string, string>>::iterator it = this->m_orderdate.begin();it != this->m_orderdate.end();it++)
	//{
	//	cout << "第" << it->first << "条预约 " << endl;
	//	for (map<string, string>::iterator mit = (*it).second.begin();mit != (*it).second.end();mit++)
	//	{
	//		cout << " key= " << mit->first << " value= " << mit->second << " ";
	//	}
	//	cout << endl;
	//}

	
}
void Orderfile::updateorder()
{
	if (this->m_size == 0)
	{
		cout << "当前没有预约记录" << endl;
		return;
	}
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0;i < this->m_size;i++)
	{
		ofs << "date:" << this->m_orderdate[i]["date"] << " ";
		ofs << "interval:" << this->m_orderdate[i]["interval"] << " ";
		ofs << "stuid:" << this->m_orderdate[i]["stuid"] << " ";
		ofs << "stuname:" << this->m_orderdate[i]["stuname"] << " ";
		ofs << "roomid:" << this->m_orderdate[i]["roomid"] << " ";
		ofs << "stact:" << this->m_orderdate[i]["stact"] << endl;
	}
	ofs.close();

}
