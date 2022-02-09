#include<iostream>
#include"Identity.h"
#include <fstream>
#include <string>
#include "globalFile.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"

using namespace std;

void managerMenu(Identity * &manager) {
	while (true) {
		manager->operMenu();
		Manager * man = (Manager*)manager;
		int select;
		cin >> select;
		if (select == 1)
		{
			cout << "添加账号" << endl;
			man->addPerson();
		}
		else if (select == 2) 
		{
			cout << "查看账号" << endl;
			man->showPerson();
		}
		else if(select == 3)
		{
			cout << "查看机房" << endl;
			man->showComputer();
		}
		else if (select == 4) {
			cout << "清空预约" << endl;
			man->cleanFile();
		}
		else
		{
			delete manager;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
void studentMenu(Identity * &student)
{
	while (true)
	{
		//学生菜单
		student->operMenu();

		Student* stu = (Student*)student;
		int select = 0;

		cin >> select;

		if (select == 1) //申请预约
		{
			stu->applyOrder();
		}
		else if (select == 2) //查看自身预约
		{
			stu->showMyOrder();
		}
		else if (select == 3) //查看所有预约
		{
			stu->showAllOrder();
		}
		else if (select == 4) //取消预约
		{
			stu->cancelOrder();
		}
		else
		{
			delete student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
void teacherMenu(Identity * &teacher)
{
	while (true)
	{
		//学生菜单
		teacher->operMenu();

		Teacher* tea = (Teacher*)teacher;
		int select = 0;

		cin >> select;

		if (select == 1) //查看all预约
		{
			tea->showAllOrder();
		}
		else if (select == 2) //审核预约
		{
			tea->validOrder();
		}
		else
		{
			delete teacher;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
void LoginIn(string fileName, int type) {
	Identity * person = NULL;
	ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	int id = 0;
	string name;
	string pwd;

	if (type == 1)
	{
		cout << "请输入你的学号" << endl;
		cin >> id;
	}
	else if (type == 2)
	{	
		cout << "请输入你的职工号" << endl;
		cin >> id;
	}
	cout << "请输入用户名" << endl;
	cin >> name;
	cout << "请输入密码" << endl;
	cin >> pwd;
	if (type ==1)
	{
		//学生登录
		int fId;
		string fName;
		string fPwd;
		while (ifs>>fId&&ifs>>fName&&ifs>>fPwd)
		{
			if (fId ==id &&fName == name&&fPwd == pwd)
			{
				cout << "学生验证登录成功" << endl;
				system("pause");
				system("cls");
				person = new Student(id,name,pwd);
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//教师登录
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "教师验证登录成功" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3) {
		//管理员登录
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if ( fName == name && fPwd == pwd)
			{
				cout << "管理员验证登录成功" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				managerMenu(person);
				return;

			}
		}
	}
	cout << "验证登录失败" << endl;
	system("pause");
	system("cls");
	return;
}
int main() {
	int select = 0;
	while (true)
	{
		cout << "======================  欢迎来到swpu机房预约系统  =====================" << endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.学生代表           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.老    师           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.管 理 员           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.退    出           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择: ";
		cin >> select;
		switch (select)
		{
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		case 1:
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:
			LoginIn(ADMIN_FILE, 3);
			break;
		default:
			cout << "输入有误请重新输入！" << endl;
			system("pause");
			system("cls");
			break;
		}

	}

	system("pause");
	return 0;
}