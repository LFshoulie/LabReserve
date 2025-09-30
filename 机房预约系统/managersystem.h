#pragma once
#include <iostream>
using namespace std;
#include <string>
#include "student.h"
#include "teacher.h"
#include "manager.h"
#include "order.h"
#include "computer_room.h"
#include <vector>
#include <fstream>

class ManagerSystem
{
public:

	//菜单功能
	void ShouMenu();

	//读文件
	void GetFile(vector<Student> &S,vector<Manager> &M,vector<Teacher> &T,vector<Order> &Or,vector<Computer_Room> &CR);

	//写文件
	void GiveStudentFile(vector<Student>& S);
	void GiveManagerFile(vector<Manager>& M);
	void GiveTeacherFile(vector<Teacher>& T);
	void GiveOrderFile(vector<Order>& Or);
	void GiveComputerFile(vector<Computer_Room>& CR);

	//查找功能
	int Find_Teacher(vector<Teacher>& T,string &val_id);
	int Find_Teacher(vector<Teacher>& T,Teacher &TT);
	int Find_Order(vector<Order>& Or, string &val_id);
	int Find_Student(vector<Student>& S, string &val_id);
	int Find_Student(vector<Student>& S, Student& s);
	int Find_Manager(vector<Manager>& M, string& val_id);
	int Find_Manager(vector<Manager>& M, Manager& m);
	
	//退出功能
	void ExitSystem();
};