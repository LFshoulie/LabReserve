#pragma once
#include <iostream>
using namespace std;
#include <string>

class Computer_Room
{
public:
	//Ĭ�Ϲ��� 
	Computer_Room();

	//�вι���
	Computer_Room(string name, int max);

	//��������
	string m_Name;
	//�����������
	int m_Max;
};