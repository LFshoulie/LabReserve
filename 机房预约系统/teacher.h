#pragma once
#include <iostream>
using namespace std;
#include <string>
#include "identity.h"
#include "order.h"
#include <vector>
#include "computer_room.h"

class Teacher : public Identity
{
public:

	//默认构造
	Teacher();

	//有参构造
	Teacher(string id, string name, string code);

	//调用菜单  重写重虚函数
	void OperMenu();

	//查看所有预约
	void ShowOrder(vector<Order> &Or);

	//审核预约
	void CheckOrder(vector<Order>& Or,vector<Computer_Room> &CR);


	//职工编号
	string m_Id;
};