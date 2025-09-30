#include "managersystem.h"

//�˵�����
void ManagerSystem::ShouMenu()
{
	cout << "=======================��ӭ��������ԤԼϵͳ=====================" << endl;
	cout << "�������������:" << endl;
	cout << "\t\t ---------------------------" << endl;
	cout << "\t\t|                           |" << endl;
	cout << "\t\t|        1,ѧ������         |" << endl;
	cout << "\t\t|                           |" << endl;
	cout << "\t\t|        2,��    ʦ         |" << endl;
	cout << "\t\t|                           |" << endl;
	cout << "\t\t|        3,�� �� Ա         |" << endl;
	cout << "\t\t|                           |" << endl;
	cout << "\t\t|        0,��    ��         |" << endl;
	cout << "\t\t|                           |" << endl;
	cout << "\t\t ---------------------------" << endl;
	cout << "����������ѡ��:" << endl;
}

//���ļ�
void ManagerSystem::GetFile(vector<Student>& S, vector<Manager>& M, vector<Teacher>& T, vector<Order>& Or, vector<Computer_Room>& CR)
{
	/*���������Ա*/
	string id, name, code;

	ifstream ifs;

	//����ѧ��
	ifs.open("student.txt", ios::in);
	if (!ifs.is_open())
	{
		cout<<"student.txt�ļ���ʧ��"<<endl;
		system("pause");
		return;
	}

	while(ifs>>id>>name>>code)
	{
		Student s(id, name, code);
		S.push_back(s);
	}
	ifs.close();

	//�������Ա
	ifs.open("manager.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "manager.txt�ļ���ʧ��" << endl;
		system("pause");
		return;
	}

	while (ifs >> name >> code)
	{
		Manager m(name,code);
		M.push_back(m);
	}
	ifs.close();

	//������ʦ
	ifs.open("teacher.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "teacher.txt�ļ���ʧ��" << endl;
		system("pause");
		return;
	}
	
	while (ifs >> id >> name >> code)
	{
		Teacher t(id,name,code);
		T.push_back(t);
	}
	ifs.close();

	//���붩��
	ifs.open("order.txt", ios::in);
	string day, time, number, condition;
	if (!ifs.is_open())
	{
		cout << "order.txt�ļ���ʧ��" << endl;
		system("pause");
		return;
	}

	while (ifs >> id >> day >> time >> number >> condition)
	{
		Order o(id, day, time, number,condition);
		Or.push_back(o);
	}
	ifs.close();

	//���������
	int max;
	ifs.open("computer_room.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "computer_room.txt�ļ���ʧ��" << endl;
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

//д�ļ�
void ManagerSystem::GiveStudentFile(vector<Student>& S)
{
	ofstream ofs;
	//дѧ��
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
	//д����Ա
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
	//д��ʦ
	ofs.open("teacher.txt", ios::out | ios::trunc);
	for (vector<Teacher>::iterator it = T.begin(); it != T.end(); it++)
	{
		ofs << it->m_Id << " " << it->m_Name << " " << it->m_Code << endl;
	}
	ofs.close();
}

void ManagerSystem::GiveOrderFile(vector<Order>& Or)
{
	//д����
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
	//д������
	ofs.open("computer_room.txt", ios::out | ios::trunc);
	for (vector<Computer_Room>::iterator it = CR.begin(); it != CR.end(); it++)
	{
		ofs << it->m_Name << " " << it->m_Max << endl;
	}
	ofs.close();
}

//���ҹ���
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

//�˳�����
void ManagerSystem::ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}