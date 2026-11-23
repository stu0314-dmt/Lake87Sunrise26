#include "manager.h"
manager::manager(int id, string name, int did)
{
	m_id = id;
	m_name = name;
	m_deptid = did;
}
 void manager::show()
{
	 cout << "员工编号:" << this->m_id << "\t" <<
		 "员工姓名:" << this->m_name << "\t" <<
		 "员工岗位:" << this->get() << "\t" <<
		 "员工的职责:完成老板交给的任务,并下发给员工" << endl;
}
 string manager::get()
{
	 return string("经理");
}