#pragma once
#include <iostream>
using namespace std;
#include <string>

class Computer_Room
{
public:
	//默认构造 
	Computer_Room();

	//有参构造
	Computer_Room(string name, int max);

	//机房名称
	string m_Name;
	//机房最大容量
	int m_Max;
};