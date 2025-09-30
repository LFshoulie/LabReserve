#pragma once
#include <iostream>
using namespace std;
#include <string>
#include "identity.h"
#include "teacher.h"
#include "student.h"
#include "computer_room.h"
#include "order.h"
#include <fstream>

class Manager : public Identity
{
public:

	//默认构造
	Manager();

	//有参构造
	Manager(string name, string code);

	//调用菜单  重写重虚函数
	void OperMenu();

	//添加账号
	void AddIdentity(vector<Student>& S, vector<Manager>& M, vector<Teacher>& T);

	//查看账号
	void ShowIdentity(vector<Student>& S, vector<Teacher>& T);

	//查看机房信息
	void ShowComputer(vector<Computer_Room>& CR);

	//清空预约记录
	void ClearFile(vector<Order>& Or);
};