#include "order.h"

//Ĭ�Ϲ���
Order::Order()
{
	this->m_Condition = "�����";
}

// �вι���
Order::Order(string id, string day, string time, string number,string condition)
{
	this->m_Id = id;
	this->m_Day = day;
	this->m_Time = time;
	this->m_Number = number;
	this->m_Condition = condition;
}