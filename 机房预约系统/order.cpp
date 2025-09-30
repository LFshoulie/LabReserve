#include "order.h"

//默认构造
Order::Order()
{
	this->m_Condition = "待审核";
}

// 有参构造
Order::Order(string id, string day, string time, string number,string condition)
{
	this->m_Id = id;
	this->m_Day = day;
	this->m_Time = time;
	this->m_Number = number;
	this->m_Condition = condition;
}