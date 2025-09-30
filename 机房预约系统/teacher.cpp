#include "teacher.h"
#include "managerSystem.h"

//默认构造
Teacher::Teacher()
{

}

//有参构造
Teacher::Teacher(string id, string name, string code)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Code = code;
}

//调用菜单  重写重虚函数
void Teacher::OperMenu()
{
	cout << "\t\t ---------------------------" << endl;
	cout << "\t\t|                           |" << endl;
	cout << "\t\t|      1,查看所有预约       |" << endl;
	cout << "\t\t|                           |" << endl;
	cout << "\t\t|      2,审 核 预 约        |" << endl;
	cout << "\t\t|                           |" << endl;
	cout << "\t\t|      0,退       出        |" << endl;
	cout << "\t\t|                           |" << endl;
	cout << "\t\t ---------------------------" << endl;
	cout << "请输入您的选择:" << endl;
}

//查看所有预约
void Teacher::ShowOrder(vector<Order>& Or)
{
	if (Or.empty())
	{
		cout << "抱歉！！！预约为空" << endl;
		system("pause");
		system("cls");
		return;
	}
	int i = 1;
	for (vector<Order>::iterator it = Or.begin(); it != Or.end(); it++)
	{
		cout << "编号: " << i
			<< "\t账号: " << it->m_Id
			<< "\t周期: " << it->m_Day
			<< "\t时间段: " << it->m_Time
			<< "\t机房号: " << it->m_Number
			<< "\t预约状态: " << it->m_Condition << endl;
		i++;
	}
}

//审核预约
void Teacher::CheckOrder(vector<Order> &Or, vector<Computer_Room>& CR)
{
	Teacher::ShowOrder(Or);
	int val_number;
	cout << "输入要审核的编号" << endl;  cin >> val_number;
	val_number--;


	bool bo = 1;
	cout << "确认审核通过？\n1,是\n0,否" << endl;
	cin >> bo;
	if (bo == 1)
	{
		for (int i = 0; i <CR.size(); i++)
		{
			if (i == val_number)
			{
				Or[i].m_Condition = "已通过";
				break;
			}
		}

		//保存回文档
		ManagerSystem MS;
		MS.GiveOrderFile(Or);

		cout << "审核成功" << endl;
		system("pause");
		system("cls");
	}
}