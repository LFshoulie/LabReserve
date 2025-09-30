#pragma once
#include <iostream>
using namespace std;
#include <string>
class Order
{
public:

	//默认构造
	Order();

	// 有参构造
	Order(string id, string day, string time, string number,string condition);

	//预约账号
	string m_Id;
	//日期
	string m_Day;
	//时段
	string m_Time;
	//机房号
	string m_Number;
	//预约状态
	string m_Condition;
};