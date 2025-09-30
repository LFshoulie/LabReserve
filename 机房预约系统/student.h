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

	//Ĭ�Ϲ���
	Student();

	//�вι���
	Student(string id, string name, string code);

	//���ò˵�   ��д���麯��
	void OperMenu();

	//����ԤԼ
	void ApplyOrder(vector<Order> &Or,Student &SS, vector<Computer_Room>& CR);

	//�鿴����ԤԼ
	void ShowMyOrder(vector<Order>& Or, Student& SS);

	//�鿴������ԤԼ
	void ShowAllOrder(vector<Order>& Or);

	//ȡ��ԤԼ
	void CancelOrder(vector<Order>& Or, vector<Computer_Room>& CR);

	//ѧ��ѧ��
	string m_Id;
};