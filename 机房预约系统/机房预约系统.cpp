#include <iostream>
using namespace std;
#include "managersystem.h"
#include <string>
#include "student.h"
#include "teacher.h"
#include "manager.h"
#include "order.h"
#include "computer_room.h"
#include <vector>

//������ͬ�������
vector<Student> S;
vector<Manager> M;
vector<Teacher> T;
vector<Order> Or;
vector<Computer_Room> CR;

int main()
{
	//ʵ��������ϵͳ����
	ManagerSystem MS;

	//��������ĵ�
	MS.GetFile(S, M, T, Or, CR);
	
	//�ṩ�û�ѡ��ӿ�
	int choice = 0;

	while (1)
	{
		//���ò˵�
		MS.ShouMenu();

		cin >> choice;  //�����û�ѡ��

		switch (choice)
		{
		case 1:  //ѧ������
		{
			//ʵ��������
			Student SS;
			cout << "ѧ�����: "; cin >> SS.m_Id;
			cout << "ѧ������: "; cin >> SS.m_Name;
			cout << "����: "; cin >> SS.m_Code;

			int S_pos = MS.Find_Student(S, SS);
			if (S_pos == -1)
			{
				cout << "��Ǹ�������˺Ų�����" << endl;
				system("pause");
				system("cls");
				break;
			}

			//�ṩѧ��ѡ��ӿ�
			int S_choice = 0;

			while (1)
			{
				system("cls");
				cout << "��ӭѧ��:  " << SS.m_Name << endl;
				//���ò˵�
				SS.OperMenu();

				cin >> S_choice;
				if (S_choice == 1)  //����ԤԼ
				{
					SS.ApplyOrder(Or, SS,CR);
				}
				else if (S_choice == 2)  //�鿴����ԤԼ
				{
					SS.ShowMyOrder(Or, SS);
				}
				else if (S_choice == 3)  //�鿴����ԤԼ
				{
					SS.ShowAllOrder(Or);
				}
				else if (S_choice == 4)  //ȡ��ԤԼ
				{
					SS.CancelOrder(Or, CR);
				}
				else if (S_choice == 0)  //�˳��˺�
				{
					cout << "�˺����˳�" << endl;
					system("pause");
					system("cls");
					break;
				}
				else
				{
					cout << "��������" << endl;
					system("pause");
					system("cls");
				}
			}
		}
			break;
		case 2:  //��ʦ
		{
			//ʵ��������
			Teacher TT;
			cout << "ְ�����: "; cin >> TT.m_Id ;
			cout << "ְ������: "; cin >> TT.m_Name;
			cout << "����: "; cin >> TT.m_Code;

			int T_pos = MS.Find_Teacher(T, TT);
			if (T_pos == -1)
			{
				cout << "��Ǹ�������˺Ų�����" << endl;
				system("pause");
				system("cls");
				break;
			}

			//�ṩ��ʦѡ��ӿ�
			int T_choice = 0;
			while (1)
			{
				system("cls");
				cout << "��ӭ��ʦ: " << TT.m_Name << endl;
				//���ò˵�
				TT.OperMenu();

				cin >> T_choice;
				if (T_choice == 1)  //�鿴����ԤԼ
				{
					TT.ShowOrder(Or);
					system("pause");
				}
				else if (T_choice == 2)  //���ԤԼ
				{
					TT.CheckOrder(Or,CR);
				}
				else if (T_choice == 0)  //�˳��˺�
				{
					cout << "�˺����˳�" << endl;
					system("pause");
					system("cls");
					break;
				}
				else
				{
					cout << "��������" << endl;
					system("pause");
					system("cls");
				}
			}
		}
			break;
		case 3:  //����Ա
		{
			//ʵ��������
			Manager MM;
			cout << "ְ������: "; cin >> MM.m_Name;
			cout << "����: "; cin >> MM.m_Code;

			int M_pos = MS.Find_Manager(M, MM);
			if (M_pos == -1)
			{
				cout << "��Ǹ�������˺Ų�����" << endl;
				system("pause");
				system("cls");
				break;
			}

			//�ṩ����Աѡ��ӿ�
			int M_choice = 0;
			while (1)
			{
				system("cls");
				cout << "��ӭ����Ա: " << MM.m_Name << endl;
				//���ò˵�
				MM.OperMenu();

				cin >> M_choice;
				
				if (M_choice == 1)  //����˺�
				{
					MM.AddIdentity(S, M, T);
				}
				else if (M_choice == 2)  //�鿴�˺�
				{
					MM.ShowIdentity(S, T);
				}
				else if (M_choice == 3)  //�鿴������Ϣ
				{
					MM.ShowComputer(CR);
				}
				else if (M_choice == 4)  //���ԤԼ��¼
				{
					MM.ClearFile(Or);
				}
				else if (M_choice == 0)  //�˳��˺�
				{
					cout << "�˺�" << MM.m_Name << "���˳�" << endl;
					system("puase");
					system("cls");
					break;
				}
				else
				{
					cout << "�������󣡣�����������" << endl;
					system("pause");
					system("cls");
				}
			}
		}
			break;
		case 0:  //�˳�
			MS.ExitSystem();
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}