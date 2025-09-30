#include "manager.h"
#include "managersystem.h"

//默认构造
Manager::Manager()
{

}

//有参构造
Manager::Manager(string name, string code)
{
	this->m_Name = name;
	this->m_Code = code;
}

//调用菜单  重写重虚函数
void Manager::Manager::OperMenu()
{
	cout << "\t\t ----------------------------" << endl;
	cout << "\t\t|                            |" << endl;
	cout << "\t\t|      1,添 加 账 号         |" << endl;
	cout << "\t\t|                            |" << endl;
	cout << "\t\t|      2,查 看 账 号         |" << endl;
	cout << "\t\t|                            |" << endl;
	cout << "\t\t|      3,查看机房信息        |" << endl;
	cout << "\t\t|                            |" << endl;
	cout << "\t\t|      4,清空预约记录        |" << endl;
	cout << "\t\t|                            |" << endl;
	cout << "\t\t|      0,退        出        |" << endl;
	cout << "\t\t|                            |" << endl;
	cout << "\t\t ----------------------------" << endl;
	cout << "请输入您的选择:" << endl;
}

//添加账号
void Manager::AddIdentity(vector<Student>& S, vector<Manager>& M, vector<Teacher>& T)
{
	ManagerSystem MS;
	cout << "添加账号身份为: " << endl;
	cout << "1,管理员\n2,老师\n3,学生" << endl;
	int Add_choice = 0;
	cin >> Add_choice;
	if (Add_choice == 1)  //管理员
	{
		//实例化对象
		Manager temp_M;
		cout << "职工姓名: ";  cin >> temp_M.m_Name;
		//查重
		int M_pos = MS.Find_Manager(M, temp_M.m_Name);
		if (M_pos != -1)
		{
			cout << "该账号已存在" << endl;
			system("pause");
			system("cls");
			return;
		}
		cout << "密码: "; cin >> temp_M.m_Code;

		M.push_back(temp_M);
		//保存回文档
		MS.GiveManagerFile(M);
		cout << "添加管理员成功" << endl;
		system("pause");
		system("cls");
	}
	else if (Add_choice == 2)  //老师
	{
		//实例化对象
		Teacher temp_T;
		cout << "职工账号: ";  cin >> temp_T.m_Id;
		//查重
		int T_pos = MS.Find_Teacher(T, temp_T.m_Id);
		if (T_pos != -1)
		{
			cout << "该账号已存在" << endl;
			system("pause");
			system("cls");
			return;
		}
		cout << "职工姓名: ";  cin >> temp_T.m_Name;
		cout << "密码: ";  cin >> temp_T.m_Code;

		T.push_back(temp_T);
		//保存回文档
		MS.GiveTeacherFile(T);
		cout << "添加老师成功" << endl;
		system("pause");
		system("cls");
	}
	else if(Add_choice == 3)  //学生
	{
		//实例化对象
		Student temp_S;
		cout << "职工账号: ";  cin >> temp_S.m_Id;
		//查重
		int S_pos = MS.Find_Student(S, temp_S.m_Id);
		if (S_pos != -1)
		{
			cout << "该账号已存在" << endl;
			system("pause");
			system("cls");
			return;
		}
		cout << "职工姓名: ";  cin >> temp_S.m_Name;
		cout << "密码: ";  cin >> temp_S.m_Code;

		S.push_back(temp_S);
		//保存回文档
		MS.GiveStudentFile(S);
		cout << "添加学生成功" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "该系统未创建该身份" << endl;
		system("pause");
		system("cls");
	}
}

//查看账号
void Manager::ShowIdentity(vector<Student>& S, vector<Teacher>& T)
{
	cout << "查看账号身份为: " << endl;
	cout << "1,老师\n2,学生" << endl;
	int Show_choice = 0;
	cin >> Show_choice;
	
	if (Show_choice == 1)  //老师
	{
		if (T.empty())
		{
			cout << "老师账号库为空" << endl;
			system("pasue");
			system("cls");
		}
		for (int i = 0; i < T.size(); i++)
		{
			cout << "职工编号:  " << T[i].m_Id
				<< "\t\t职工姓名:  " << T[i].m_Name
				<< "\t职工密码:  " << T[i].m_Code << endl;
		}
		system("pause");
		system("cls");
	}
	else if (Show_choice == 2)  //学生
	{
		if (S.empty())
		{
			cout << "学生账号库为空" << endl;
			system("pasue");
			system("cls");
		}
		for (int i = 0; i < S.size(); i++)
		{
			cout << "职工编号:  " << S[i].m_Id
				<< "\t职工姓名:  " << S[i].m_Name
				<< "\t职工密码:  " << S[i].m_Code << endl;
		}
		system("pause");
		system("cls");
	}
	else
	{
		cout << "该系统未创建该身份" << endl;
		system("pause");
		system("cls");
	}
}

//查看机房信息
void Manager::ShowComputer(vector<Computer_Room>& CR)
{
	for (int i = 0; i < CR.size(); i++)
	{
		cout << "机房名称: " << CR[i].m_Name << "\t机房最大容量: " << CR[i].m_Max << endl;
	}
	system("pause");
	system("cls");
}

//清空预约记录
void Manager::ClearFile(vector<Order>& Or)
{
	//清空容器
	Or.clear();
	//清空文档
	ofstream ofs;
	ofs.open("order.txt", ios::out | ios::trunc);
	ofs.close();

	cout << "清空成功" << endl;
	system("pause");
	system("cls");
}