#include "student.h"
#include "managersystem.h"
#include "teacher.h"

//默认构造
Student::Student()
{

}

//有参构造
Student::Student(string id, string name, string code)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Code = code;
}

//调用菜单   重写纯虚函数
void Student::OperMenu()
{
	cout << "\t\t ---------------------------" << endl;
	cout << "\t\t|                           |" << endl;
	cout << "\t\t|      1,申 请 预 约        |" << endl;
	cout << "\t\t|                           |" << endl;
	cout << "\t\t|      2,查看自身预约       |" << endl;
	cout << "\t\t|                           |" << endl;
	cout << "\t\t|      3,查看所有预约       |" << endl;
	cout << "\t\t|                           |" << endl;
	cout << "\t\t|      4,取 消 预 约        |" << endl;
	cout << "\t\t|                           |" << endl;
	cout << "\t\t|      0,退       出        |" << endl;
	cout << "\t\t|                           |" << endl;
	cout << "\t\t ---------------------------" << endl;
	cout << "请输入您的选择:" << endl;
}

//申请预约
void Student::ApplyOrder(vector<Order>& Or, Student& SS, vector<Computer_Room>& CR)
{
	Order temp_O;
	//账号
	temp_O.m_Id = SS.m_Id;
	//周期
	cout << "请选择预约周期:" << endl;
	cout << "1,星期一\n2,星期二\n3,星期三\n4,星期四\n5,星期五" << endl;
	int temp_day;
	cin >> temp_day;
	if (temp_day == 1)
	{
		temp_O.m_Day = "星期一";
	}
	else if (temp_day == 2)
	{
		temp_O.m_Day = "星期二";
	}
	else if (temp_day == 3)
	{
		temp_O.m_Day = "星期三";
	}
	else if (temp_day == 4)
	{
		temp_O.m_Day = "星期四";
	}
	else if (temp_day == 5)
	{
		temp_O.m_Day = "星期五";
	}

	//时段
	cout << "请选择预约时段" << endl;
	cout << "1,早上\n2,中午\n3,晚上" << endl;
	int temp_time = 0;
	cin >> temp_time;
	if (temp_time == 1)
	{
		temp_O.m_Time = "早上";
	}
	else if (temp_time == 2)
	{
		temp_O.m_Time = "中午";
	}
	else if (temp_time == 3)
	{
		temp_O.m_Time = "晚上";
	}

	//机房号
	for (int i = 0; i < CR.size(); i++)
	{
		cout << "机房名称: " << CR[i].m_Name << "\t机房最大容量: " << CR[i].m_Max << endl;
	}
	cout << "请输入预约的机房号" << endl;
	string temp_number;
	cin >> temp_number;
	temp_O.m_Number = temp_number;

	Or.push_back(temp_O);
	//保存回文档
	ManagerSystem MS;
	MS.GiveOrderFile(Or);

	cout << "预约成功" << endl;
	system("pause");
	system("cls");
}

//查看自身预约
void Student::ShowMyOrder(vector<Order>& Or, Student& SS)
{
	int j = 1;
	for (int i = 0; i < Or.size(); i++)
	{
		if (Or[i].m_Id == SS.m_Id)
		{
			cout <<"编号: "<<j
				<< "\t申请账号: " << Or[i].m_Id
				<< "\t周期: " << Or[i].m_Day
				<< "\t时段: " << Or[i].m_Time
				<< "\t机房号: " << Or[i].m_Number
				<< "\t预约状态: " << Or[i].m_Condition << endl;
		}
	}
	system("pause");
	system("cls");
}

//查看所有人预约
void Student::ShowAllOrder(vector<Order>& Or)
{
	if (Or.empty())
	{
		cout << "预约库为空" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < Or.size(); i++)
	{
		cout << "申请账号: " << Or[i].m_Id
			<< "\t周期: " << Or[i].m_Day
			<< "\t时段: " << Or[i].m_Time
			<< "\t机房号: " << Or[i].m_Number
			<< "\t预约状态: " << Or[i].m_Condition << endl;
	}
	system("pause");
	system("cls");
}

//取消预约
void Student::CancelOrder(vector<Order>& Or, vector<Computer_Room>& CR)
{
	Teacher TT;
	TT.ShowOrder(Or);
	int val_number;
	cout << "输入要取消的编号" << endl;  cin >> val_number;
	val_number--;


	bool bo = 1;
	cout << "确认取消申请？\n1,是\n0,否" << endl;
	cin >> bo;
	if (bo == 1)
	{
		for (int i = 0; i < CR.size(); i++)
		{
			if (i == val_number)
			{
				Or[i].m_Condition = "已取消";
				break;
			}
		}

		//保存回文档
		ManagerSystem MS;
		MS.GiveOrderFile(Or);

		cout << "取消成功" << endl;
		system("pause");
		system("cls");
	}
}