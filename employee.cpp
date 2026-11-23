#include "employee.h"
employee::employee(int id, string name, int did)
{
	m_id = id;
	m_name = name;
	m_deptid = did;
}
 void employee::show()
{
	 cout << "员工编号:" << this->m_id << "\t" <<
		 "员工姓名:" << this->m_name << "\t" <<
		 "员工岗位:" << this->get() << "\t" <<
		 "员工的职责:完成经理交给的任务" << endl;
}
 string employee::get()
{
	 return string("员工");
}
