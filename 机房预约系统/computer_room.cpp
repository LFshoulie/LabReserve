#include "computer_room.h"

//Ĭ�Ϲ��� 
Computer_Room::Computer_Room()
{
	this->m_Max = 0;
}

//�вι���
Computer_Room::Computer_Room(string name, int max)
{
	this->m_Name = name;
	this->m_Max = max;
}