#pragma once
#include <iostream>
using namespace std;
#include <string>
#include "identity.h"
#include "order.h"
#include "computer_room.h"
#include <vector>

class Student : public Identity
{
public:

	//默认构造
	Student();

	//有参构造
	Student(string id, string name, string code);

	//调用菜单   重写纯虚函数
	void OperMenu();

	//申请预约
	void ApplyOrder(vector<Order> &Or,Student &SS, vector<Computer_Room>& CR);

	//查看自身预约
	void ShowMyOrder(vector<Order>& Or, Student& SS);

	//查看所有人预约
	void ShowAllOrder(vector<Order>& Or);

	//取消预约
	void CancelOrder(vector<Order>& Or, vector<Computer_Room>& CR);

	//学生学号
	string m_Id;
};