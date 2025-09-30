#pragma once
#include <iostream>
using namespace std;
#include <string>
#include "identity.h"
#include "teacher.h"
#include "student.h"
#include "computer_room.h"
#include "order.h"
#include <fstream>

class Manager : public Identity
{
public:

	//Ĭ�Ϲ���
	Manager();

	//�вι���
	Manager(string name, string code);

	//���ò˵�  ��д���麯��
	void OperMenu();

	//����˺�
	void AddIdentity(vector<Student>& S, vector<Manager>& M, vector<Teacher>& T);

	//�鿴�˺�
	void ShowIdentity(vector<Student>& S, vector<Teacher>& T);

	//�鿴������Ϣ
	void ShowComputer(vector<Computer_Room>& CR);

	//���ԤԼ��¼
	void ClearFile(vector<Order>& Or);
};