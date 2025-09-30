#include "teacher.h"
#include "managerSystem.h"

//Ĭ�Ϲ���
Teacher::Teacher()
{

}

//�вι���
Teacher::Teacher(string id, string name, string code)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Code = code;
}

//���ò˵�  ��д���麯��
void Teacher::OperMenu()
{
	cout << "\t\t ---------------------------" << endl;
	cout << "\t\t|                           |" << endl;
	cout << "\t\t|      1,�鿴����ԤԼ       |" << endl;
	cout << "\t\t|                           |" << endl;
	cout << "\t\t|      2,�� �� Ԥ Լ        |" << endl;
	cout << "\t\t|                           |" << endl;
	cout << "\t\t|      0,��       ��        |" << endl;
	cout << "\t\t|                           |" << endl;
	cout << "\t\t ---------------------------" << endl;
	cout << "����������ѡ��:" << endl;
}

//�鿴����ԤԼ
void Teacher::ShowOrder(vector<Order>& Or)
{
	if (Or.empty())
	{
		cout << "��Ǹ������ԤԼΪ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	int i = 1;
	for (vector<Order>::iterator it = Or.begin(); it != Or.end(); it++)
	{
		cout << "���: " << i
			<< "\t�˺�: " << it->m_Id
			<< "\t����: " << it->m_Day
			<< "\tʱ���: " << it->m_Time
			<< "\t������: " << it->m_Number
			<< "\tԤԼ״̬: " << it->m_Condition << endl;
		i++;
	}
}

//���ԤԼ
void Teacher::CheckOrder(vector<Order> &Or, vector<Computer_Room>& CR)
{
	Teacher::ShowOrder(Or);
	int val_number;
	cout << "����Ҫ��˵ı��" << endl;  cin >> val_number;
	val_number--;


	bool bo = 1;
	cout << "ȷ�����ͨ����\n1,��\n0,��" << endl;
	cin >> bo;
	if (bo == 1)
	{
		for (int i = 0; i <CR.size(); i++)
		{
			if (i == val_number)
			{
				Or[i].m_Condition = "��ͨ��";
				break;
			}
		}

		//������ĵ�
		ManagerSystem MS;
		MS.GiveOrderFile(Or);

		cout << "��˳ɹ�" << endl;
		system("pause");
		system("cls");
	}
}