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

//创建不同类的容器
vector<Student> S;
vector<Manager> M;
vector<Teacher> T;
vector<Order> Or;
vector<Computer_Room> CR;

int main()
{
	//实例化管理系统对象
	ManagerSystem MS;

	//读入各自文档
	MS.GetFile(S, M, T, Or, CR);
	
	//提供用户选择接口
	int choice = 0;

	while (1)
	{
		//调用菜单
		MS.ShouMenu();

		cin >> choice;  //接收用户选择

		switch (choice)
		{
		case 1:  //学生代表
		{
			//实例化对象
			Student SS;
			cout << "学生编号: "; cin >> SS.m_Id;
			cout << "学生姓名: "; cin >> SS.m_Name;
			cout << "密码: "; cin >> SS.m_Code;

			int S_pos = MS.Find_Student(S, SS);
			if (S_pos == -1)
			{
				cout << "抱歉！！该账号不存在" << endl;
				system("pause");
				system("cls");
				break;
			}

			//提供学生选择接口
			int S_choice = 0;

			while (1)
			{
				system("cls");
				cout << "欢迎学生:  " << SS.m_Name << endl;
				//调用菜单
				SS.OperMenu();

				cin >> S_choice;
				if (S_choice == 1)  //申请预约
				{
					SS.ApplyOrder(Or, SS,CR);
				}
				else if (S_choice == 2)  //查看自身预约
				{
					SS.ShowMyOrder(Or, SS);
				}
				else if (S_choice == 3)  //查看所有预约
				{
					SS.ShowAllOrder(Or);
				}
				else if (S_choice == 4)  //取消预约
				{
					SS.CancelOrder(Or, CR);
				}
				else if (S_choice == 0)  //退出账号
				{
					cout << "账号已退出" << endl;
					system("pause");
					system("cls");
					break;
				}
				else
				{
					cout << "输入有误" << endl;
					system("pause");
					system("cls");
				}
			}
		}
			break;
		case 2:  //老师
		{
			//实例化对象
			Teacher TT;
			cout << "职工编号: "; cin >> TT.m_Id ;
			cout << "职工姓名: "; cin >> TT.m_Name;
			cout << "密码: "; cin >> TT.m_Code;

			int T_pos = MS.Find_Teacher(T, TT);
			if (T_pos == -1)
			{
				cout << "抱歉！！该账号不存在" << endl;
				system("pause");
				system("cls");
				break;
			}

			//提供老师选择接口
			int T_choice = 0;
			while (1)
			{
				system("cls");
				cout << "欢迎老师: " << TT.m_Name << endl;
				//调用菜单
				TT.OperMenu();

				cin >> T_choice;
				if (T_choice == 1)  //查看所有预约
				{
					TT.ShowOrder(Or);
					system("pause");
				}
				else if (T_choice == 2)  //审核预约
				{
					TT.CheckOrder(Or,CR);
				}
				else if (T_choice == 0)  //退出账号
				{
					cout << "账号已退出" << endl;
					system("pause");
					system("cls");
					break;
				}
				else
				{
					cout << "输入有误" << endl;
					system("pause");
					system("cls");
				}
			}
		}
			break;
		case 3:  //管理员
		{
			//实例化对象
			Manager MM;
			cout << "职工姓名: "; cin >> MM.m_Name;
			cout << "密码: "; cin >> MM.m_Code;

			int M_pos = MS.Find_Manager(M, MM);
			if (M_pos == -1)
			{
				cout << "抱歉！！该账号不存在" << endl;
				system("pause");
				system("cls");
				break;
			}

			//提供管理员选择接口
			int M_choice = 0;
			while (1)
			{
				system("cls");
				cout << "欢迎管理员: " << MM.m_Name << endl;
				//调用菜单
				MM.OperMenu();

				cin >> M_choice;
				
				if (M_choice == 1)  //添加账号
				{
					MM.AddIdentity(S, M, T);
				}
				else if (M_choice == 2)  //查看账号
				{
					MM.ShowIdentity(S, T);
				}
				else if (M_choice == 3)  //查看机房信息
				{
					MM.ShowComputer(CR);
				}
				else if (M_choice == 4)  //清空预约记录
				{
					MM.ClearFile(Or);
				}
				else if (M_choice == 0)  //退出账号
				{
					cout << "账号" << MM.m_Name << "已退出" << endl;
					system("puase");
					system("cls");
					break;
				}
				else
				{
					cout << "输入有误！！请重新输入" << endl;
					system("pause");
					system("cls");
				}
			}
		}
			break;
		case 0:  //退出
			MS.ExitSystem();
			break;
		default:
			cout << "输入有误，请重新选择" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}