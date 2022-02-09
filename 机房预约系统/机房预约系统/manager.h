#pragma once
#include "Identity.h"
#include<iostream>
using namespace std;
#include <string>
#include <fstream>
#include "globalFile.h"
#include <vector>
#include "student.h"
#include "teacher.h"
#include <algorithm>
#include "computerRoom.h"


class Manager:public Identity {
public:
	Manager();
	Manager(string name, string pwd);
	virtual void operMenu();
	void addPerson();
	void showPerson();
	void showComputer();
	void cleanFile();
	void initVector();
	bool checkRepeat(int id,int type);//ºÏ≤Èid «∑Ò÷ÿ∏¥
public:
	vector<Student>vStu;
	vector<Teacher>vTea;
	vector<ComputerRoom> vCom;
};