#pragma once
using namespace std;

#include "Identity.h"
#include<string>
#include<vector>
#include "computerRoom.h"
#include<fstream>
#include "globalFile.h"
#include "orderFile.h"
class Student:public Identity
{
public:
	Student();
	Student(int id,string name,string pwd);
	virtual void operMenu();
	void applyOrder();
	void showMyOrder();
	void showAllOrder();
	void cancelOrder();
	~Student();
public:
	int m_Id;
	vector<ComputerRoom>vCom;

};


