#pragma once
#include <iostream>
using namespace std;
#include <string>
class Order
{
public:

	//Ĭ�Ϲ���
	Order();

	// �вι���
	Order(string id, string day, string time, string number,string condition);

	//ԤԼ�˺�
	string m_Id;
	//����
	string m_Day;
	//ʱ��
	string m_Time;
	//������
	string m_Number;
	//ԤԼ״̬
	string m_Condition;
};