#include "boss.h"
boss::boss(int id, string name, int did)
{
	m_id = id;
	m_name = name;
	m_deptid = did;
}
void boss::show()
{
	cout << "员工编号:" << this->m_id << "\t" <<
		"员工姓名:" << this->m_name << "\t" <<
		"员工岗位:" << this->get() << "\t" <<
		"员工的职责:管理公司大小事务,下发任务给经理" << endl;
}
 string boss::get()
{
	 return string("总裁");
}