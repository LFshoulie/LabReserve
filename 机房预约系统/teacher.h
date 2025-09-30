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

	//Ĭ�Ϲ���
	Teacher();

	//�вι���
	Teacher(string id, string name, string code);

	//���ò˵�  ��д���麯��
	void OperMenu();

	//�鿴����ԤԼ
	void ShowOrder(vector<Order> &Or);

	//���ԤԼ
	void CheckOrder(vector<Order>& Or,vector<Computer_Room> &CR);


	//ְ�����
	string m_Id;
};