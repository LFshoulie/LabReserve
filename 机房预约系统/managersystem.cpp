#include "managersystem.h"

//菜单功能
void ManagerSystem::ShouMenu()
{
	cout << "=======================欢迎来到机房预约系统=====================" << endl;
	cout << "请输入您的身份:" << endl;
	cout << "\t\t ---------------------------" << endl;
	cout << "\t\t|                           |" << endl;
	cout << "\t\t|        1,学生代表         |" << endl;
	cout << "\t\t|                           |" << endl;
	cout << "\t\t|        2,老    师         |" << endl;
	cout << "\t\t|                           |" << endl;
	cout << "\t\t|        3,管 理 员         |" << endl;
	cout << "\t\t|                           |" << endl;
	cout << "\t\t|        0,退    出         |" << endl;
	cout << "\t\t|                           |" << endl;
	cout << "\t\t ---------------------------" << endl;
	cout << "请输入您的选择:" << endl;
}

//读文件
void ManagerSystem::GetFile(vector<Student>& S, vector<Manager>& M, vector<Teacher>& T, vector<Order>& Or, vector<Computer_Room>& CR)
{
	/*针对三类人员*/
	string id, name, code;

	ifstream ifs;

	//读入学生
	ifs.open("student.txt", ios::in);
	if (!ifs.is_open())
	{
		cout<<"student.txt文件打开失败"<<endl;
		system("pause");
		return;
	}

	while(ifs>>id>>name>>code)
	{
		Student s(id, name, code);
		S.push_back(s);
	}
	ifs.close();

	//读入管理员
	ifs.open("manager.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "manager.txt文件打开失败" << endl;
		system("pause");
		return;
	}

	while (ifs >> name >> code)
	{
		Manager m(name,code);
		M.push_back(m);
	}
	ifs.close();

	//读入老师
	ifs.open("teacher.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "teacher.txt文件打开失败" << endl;
		system("pause");
		return;
	}
	
	while (ifs >> id >> name >> code)
	{
		Teacher t(id,name,code);
		T.push_back(t);
	}
	ifs.close();

	//读入订单
	ifs.open("order.txt", ios::in);
	string day, time, number, condition;
	if (!ifs.is_open())
	{
		cout << "order.txt文件打开失败" << endl;
		system("pause");
		return;
	}

	while (ifs >> id >> day >> time >> number >> condition)
	{
		Order o(id, day, time, number,condition);
		Or.push_back(o);
	}
	ifs.close();

	//读入机房室
	int max;
	ifs.open("computer_room.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "computer_room.txt文件打开失败" << endl;
		system("pause");
		return;
	}

	while (ifs >> name >> max)
	{
		Computer_Room cr(name,max);
		CR.push_back(cr);
	}
	ifs.close();
}

//写文件
void ManagerSystem::GiveStudentFile(vector<Student>& S)
{
	ofstream ofs;
	//写学生
	ofs.open("student.txt", ios::out | ios::trunc);
	for (vector<Student>::iterator it = S.begin(); it != S.end(); it++)
	{
		ofs << it->m_Id << " " << it->m_Name << " " << it->m_Code << endl;
	}
	ofs.close();
}
void ManagerSystem::GiveManagerFile(vector<Manager>& M)
{
	ofstream ofs;
	//写管理员
	ofs.open("manager.txt", ios::out | ios::trunc);
	for (vector<Manager>::iterator it = M.begin(); it != M.end(); it++)
	{
		ofs << it->m_Name << " " << it->m_Code << endl;
	}
	ofs.close();
}

void ManagerSystem::GiveTeacherFile(vector<Teacher>& T)
{
	ofstream ofs;
	//写老师
	ofs.open("teacher.txt", ios::out | ios::trunc);
	for (vector<Teacher>::iterator it = T.begin(); it != T.end(); it++)
	{
		ofs << it->m_Id << " " << it->m_Name << " " << it->m_Code << endl;
	}
	ofs.close();
}

void ManagerSystem::GiveOrderFile(vector<Order>& Or)
{
	//写订单
	ofstream ofs;
	ofs.open("order.txt", ios::out | ios::trunc);
	for (vector<Order>::iterator it = Or.begin(); it != Or.end(); it++)
	{
		ofs << it->m_Id << " " << it->m_Day << " " << it->m_Time << " " << it->m_Number << " " << it->m_Condition << endl;
	}
	ofs.close();
}

void ManagerSystem::GiveComputerFile(vector<Computer_Room>& CR)
{
	ofstream ofs;
	//写电脑室
	ofs.open("computer_room.txt", ios::out | ios::trunc);
	for (vector<Computer_Room>::iterator it = CR.begin(); it != CR.end(); it++)
	{
		ofs << it->m_Name << " " << it->m_Max << endl;
	}
	ofs.close();
}

//查找功能
int ManagerSystem::Find_Teacher(vector<Teacher>& T, string& val_id)
{
	for (int i = 0; i < T.size(); i++)
	{
		if (val_id == T[i].m_Id)
		{
			return i;
		}
	}
	return -1;
}
int ManagerSystem::Find_Teacher(vector<Teacher>& T,Teacher &TT)
{
	for (int i = 0; i < T.size(); i++)
	{
		if (TT.m_Id == T[i].m_Id && TT.m_Name == T[i].m_Name && TT.m_Code == T[i].m_Code)
		{
			return i;
		}
	}
	return -1;
}

int ManagerSystem::Find_Order(vector<Order>& Or, string &val_id)
{
	for (int i = 0; i < Or.size(); i++)
	{
		if (Or[i].m_Id == val_id)
		{
			return i;
		}
	}
	return -1;
}
int ManagerSystem::Find_Student(vector<Student>& S, string& val_id)
{
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i].m_Id == val_id)
		{
			return i;
		}
	}
	return -1;
}
int ManagerSystem::Find_Student(vector<Student>& S, Student& s)
{
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i].m_Id == s.m_Id && S[i].m_Name == s.m_Name && S[i].m_Code == s.m_Code)
		{
			return i;
		}
	}
	return -1;
}

int ManagerSystem::Find_Manager(vector<Manager>& M, string& val_id)
{
	for (int i = 0; i < M.size(); i++)
	{
		if (M[i].m_Name == val_id)
		{
			return i;
		}
	}
	return -1;
}
int ManagerSystem::Find_Manager(vector<Manager>& M, Manager& m)
{
	for (int i = 0; i < M.size(); i++)
	{
		if (M[i].m_Name == m.m_Name && M[i].m_Code == m.m_Code)
		{
			return i;
		}
	}
	return -1;
}

//退出功能
void ManagerSystem::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}