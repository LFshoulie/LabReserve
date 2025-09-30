#include "computer_room.h"

//默认构造 
Computer_Room::Computer_Room()
{
	this->m_Max = 0;
}

//有参构造
Computer_Room::Computer_Room(string name, int max)
{
	this->m_Name = name;
	this->m_Max = max;
}