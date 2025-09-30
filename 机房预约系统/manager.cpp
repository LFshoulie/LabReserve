#include "manager.h"
#include "managersystem.h"

//Ĭ�Ϲ���
Manager::Manager()
{

}

//�вι���
Manager::Manager(string name, string code)
{
	this->m_Name = name;
	this->m_Code = code;
}

//���ò˵�  ��д���麯��
void Manager::Manager::OperMenu()
{
	cout << "\t\t ----------------------------" << endl;
	cout << "\t\t|                            |" << endl;
	cout << "\t\t|      1,�� �� �� ��         |" << endl;
	cout << "\t\t|                            |" << endl;
	cout << "\t\t|      2,�� �� �� ��         |" << endl;
	cout << "\t\t|                            |" << endl;
	cout << "\t\t|      3,�鿴������Ϣ        |" << endl;
	cout << "\t\t|                            |" << endl;
	cout << "\t\t|      4,���ԤԼ��¼        |" << endl;
	cout << "\t\t|                            |" << endl;
	cout << "\t\t|      0,��        ��        |" << endl;
	cout << "\t\t|                            |" << endl;
	cout << "\t\t ----------------------------" << endl;
	cout << "����������ѡ��:" << endl;
}

//����˺�
void Manager::AddIdentity(vector<Student>& S, vector<Manager>& M, vector<Teacher>& T)
{
	ManagerSystem MS;
	cout << "����˺����Ϊ: " << endl;
	cout << "1,����Ա\n2,��ʦ\n3,ѧ��" << endl;
	int Add_choice = 0;
	cin >> Add_choice;
	if (Add_choice == 1)  //����Ա
	{
		//ʵ��������
		Manager temp_M;
		cout << "ְ������: ";  cin >> temp_M.m_Name;
		//����
		int M_pos = MS.Find_Manager(M, temp_M.m_Name);
		if (M_pos != -1)
		{
			cout << "���˺��Ѵ���" << endl;
			system("pause");
			system("cls");
			return;
		}
		cout << "����: "; cin >> temp_M.m_Code;

		M.push_back(temp_M);
		//������ĵ�
		MS.GiveManagerFile(M);
		cout << "��ӹ���Ա�ɹ�" << endl;
		system("pause");
		system("cls");
	}
	else if (Add_choice == 2)  //��ʦ
	{
		//ʵ��������
		Teacher temp_T;
		cout << "ְ���˺�: ";  cin >> temp_T.m_Id;
		//����
		int T_pos = MS.Find_Teacher(T, temp_T.m_Id);
		if (T_pos != -1)
		{
			cout << "���˺��Ѵ���" << endl;
			system("pause");
			system("cls");
			return;
		}
		cout << "ְ������: ";  cin >> temp_T.m_Name;
		cout << "����: ";  cin >> temp_T.m_Code;

		T.push_back(temp_T);
		//������ĵ�
		MS.GiveTeacherFile(T);
		cout << "�����ʦ�ɹ�" << endl;
		system("pause");
		system("cls");
	}
	else if(Add_choice == 3)  //ѧ��
	{
		//ʵ��������
		Student temp_S;
		cout << "ְ���˺�: ";  cin >> temp_S.m_Id;
		//����
		int S_pos = MS.Find_Student(S, temp_S.m_Id);
		if (S_pos != -1)
		{
			cout << "���˺��Ѵ���" << endl;
			system("pause");
			system("cls");
			return;
		}
		cout << "ְ������: ";  cin >> temp_S.m_Name;
		cout << "����: ";  cin >> temp_S.m_Code;

		S.push_back(temp_S);
		//������ĵ�
		MS.GiveStudentFile(S);
		cout << "���ѧ���ɹ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ϵͳδ���������" << endl;
		system("pause");
		system("cls");
	}
}

//�鿴�˺�
void Manager::ShowIdentity(vector<Student>& S, vector<Teacher>& T)
{
	cout << "�鿴�˺����Ϊ: " << endl;
	cout << "1,��ʦ\n2,ѧ��" << endl;
	int Show_choice = 0;
	cin >> Show_choice;
	
	if (Show_choice == 1)  //��ʦ
	{
		if (T.empty())
		{
			cout << "��ʦ�˺ſ�Ϊ��" << endl;
			system("pasue");
			system("cls");
		}
		for (int i = 0; i < T.size(); i++)
		{
			cout << "ְ�����:  " << T[i].m_Id
				<< "\t\tְ������:  " << T[i].m_Name
				<< "\tְ������:  " << T[i].m_Code << endl;
		}
		system("pause");
		system("cls");
	}
	else if (Show_choice == 2)  //ѧ��
	{
		if (S.empty())
		{
			cout << "ѧ���˺ſ�Ϊ��" << endl;
			system("pasue");
			system("cls");
		}
		for (int i = 0; i < S.size(); i++)
		{
			cout << "ְ�����:  " << S[i].m_Id
				<< "\tְ������:  " << S[i].m_Name
				<< "\tְ������:  " << S[i].m_Code << endl;
		}
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ϵͳδ���������" << endl;
		system("pause");
		system("cls");
	}
}

//�鿴������Ϣ
void Manager::ShowComputer(vector<Computer_Room>& CR)
{
	for (int i = 0; i < CR.size(); i++)
	{
		cout << "��������: " << CR[i].m_Name << "\t�����������: " << CR[i].m_Max << endl;
	}
	system("pause");
	system("cls");
}

//���ԤԼ��¼
void Manager::ClearFile(vector<Order>& Or)
{
	//�������
	Or.clear();
	//����ĵ�
	ofstream ofs;
	ofs.open("order.txt", ios::out | ios::trunc);
	ofs.close();

	cout << "��ճɹ�" << endl;
	system("pause");
	system("cls");
}