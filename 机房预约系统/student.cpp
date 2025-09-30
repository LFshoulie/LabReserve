#include "student.h"
#include "managersystem.h"
#include "teacher.h"

//Ĭ�Ϲ���
Student::Student()
{

}

//�вι���
Student::Student(string id, string name, string code)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Code = code;
}

//���ò˵�   ��д���麯��
void Student::OperMenu()
{
	cout << "\t\t ---------------------------" << endl;
	cout << "\t\t|                           |" << endl;
	cout << "\t\t|      1,�� �� Ԥ Լ        |" << endl;
	cout << "\t\t|                           |" << endl;
	cout << "\t\t|      2,�鿴����ԤԼ       |" << endl;
	cout << "\t\t|                           |" << endl;
	cout << "\t\t|      3,�鿴����ԤԼ       |" << endl;
	cout << "\t\t|                           |" << endl;
	cout << "\t\t|      4,ȡ �� Ԥ Լ        |" << endl;
	cout << "\t\t|                           |" << endl;
	cout << "\t\t|      0,��       ��        |" << endl;
	cout << "\t\t|                           |" << endl;
	cout << "\t\t ---------------------------" << endl;
	cout << "����������ѡ��:" << endl;
}

//����ԤԼ
void Student::ApplyOrder(vector<Order>& Or, Student& SS, vector<Computer_Room>& CR)
{
	Order temp_O;
	//�˺�
	temp_O.m_Id = SS.m_Id;
	//����
	cout << "��ѡ��ԤԼ����:" << endl;
	cout << "1,����һ\n2,���ڶ�\n3,������\n4,������\n5,������" << endl;
	int temp_day;
	cin >> temp_day;
	if (temp_day == 1)
	{
		temp_O.m_Day = "����һ";
	}
	else if (temp_day == 2)
	{
		temp_O.m_Day = "���ڶ�";
	}
	else if (temp_day == 3)
	{
		temp_O.m_Day = "������";
	}
	else if (temp_day == 4)
	{
		temp_O.m_Day = "������";
	}
	else if (temp_day == 5)
	{
		temp_O.m_Day = "������";
	}

	//ʱ��
	cout << "��ѡ��ԤԼʱ��" << endl;
	cout << "1,����\n2,����\n3,����" << endl;
	int temp_time = 0;
	cin >> temp_time;
	if (temp_time == 1)
	{
		temp_O.m_Time = "����";
	}
	else if (temp_time == 2)
	{
		temp_O.m_Time = "����";
	}
	else if (temp_time == 3)
	{
		temp_O.m_Time = "����";
	}

	//������
	for (int i = 0; i < CR.size(); i++)
	{
		cout << "��������: " << CR[i].m_Name << "\t�����������: " << CR[i].m_Max << endl;
	}
	cout << "������ԤԼ�Ļ�����" << endl;
	string temp_number;
	cin >> temp_number;
	temp_O.m_Number = temp_number;

	Or.push_back(temp_O);
	//������ĵ�
	ManagerSystem MS;
	MS.GiveOrderFile(Or);

	cout << "ԤԼ�ɹ�" << endl;
	system("pause");
	system("cls");
}

//�鿴����ԤԼ
void Student::ShowMyOrder(vector<Order>& Or, Student& SS)
{
	int j = 1;
	for (int i = 0; i < Or.size(); i++)
	{
		if (Or[i].m_Id == SS.m_Id)
		{
			cout <<"���: "<<j
				<< "\t�����˺�: " << Or[i].m_Id
				<< "\t����: " << Or[i].m_Day
				<< "\tʱ��: " << Or[i].m_Time
				<< "\t������: " << Or[i].m_Number
				<< "\tԤԼ״̬: " << Or[i].m_Condition << endl;
		}
	}
	system("pause");
	system("cls");
}

//�鿴������ԤԼ
void Student::ShowAllOrder(vector<Order>& Or)
{
	if (Or.empty())
	{
		cout << "ԤԼ��Ϊ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < Or.size(); i++)
	{
		cout << "�����˺�: " << Or[i].m_Id
			<< "\t����: " << Or[i].m_Day
			<< "\tʱ��: " << Or[i].m_Time
			<< "\t������: " << Or[i].m_Number
			<< "\tԤԼ״̬: " << Or[i].m_Condition << endl;
	}
	system("pause");
	system("cls");
}

//ȡ��ԤԼ
void Student::CancelOrder(vector<Order>& Or, vector<Computer_Room>& CR)
{
	Teacher TT;
	TT.ShowOrder(Or);
	int val_number;
	cout << "����Ҫȡ���ı��" << endl;  cin >> val_number;
	val_number--;


	bool bo = 1;
	cout << "ȷ��ȡ�����룿\n1,��\n0,��" << endl;
	cin >> bo;
	if (bo == 1)
	{
		for (int i = 0; i < CR.size(); i++)
		{
			if (i == val_number)
			{
				Or[i].m_Condition = "��ȡ��";
				break;
			}
		}

		//������ĵ�
		ManagerSystem MS;
		MS.GiveOrderFile(Or);

		cout << "ȡ���ɹ�" << endl;
		system("pause");
		system("cls");
	}
}