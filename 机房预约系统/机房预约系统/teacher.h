#pragma once
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>
#include "identity.h"
#include <fstream>
#include "orderFile.h"
#include <string>
#include<vector>
class Teacher :public Identity
{
public:

	//Ĭ�Ϲ���
	Teacher();

	//�вι��� (ְ����ţ�����������)
	Teacher(int empId, string name, string pwd);

	//�˵�����
	virtual void operMenu();

	//�鿴����ԤԼ
	void showAllOrder();

	//���ԤԼ
	void validOrder();

	int m_EmpId; //��ʦ���

};