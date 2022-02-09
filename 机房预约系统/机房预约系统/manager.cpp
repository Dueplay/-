#include "manager.h"

Manager::Manager()
{
}

Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;
	this->initVector();
	ifstream ifs;

	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	cout << "当前机房数量为： " << vCom.size() << endl;

	ifs.close();
}

void Manager::operMenu()
{	
	cout << "欢迎管理员：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.添加账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.查看账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.查看机房            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.清空预约            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

void Manager::addPerson()
{
	cout << "请输入添加账号的类型" << endl;
	cout << "1·添加学生" << endl;
	cout << "2·添加老师" << endl;
	string fileName;
	string tip;
	string errorTip;
	int select;
	while (true)
	{
		cin >> select;
		if (select == 1)
		{
			fileName = STUDENT_FILE;
			tip = "请输入学号";
			errorTip = "学号重复，请重新输入";
			break;
		}
		else if (select == 2) {
			fileName = TEACHER_FILE;
			tip = "请输入职工号";
			errorTip = "职工号重复，请重新输入";
			break;
		}
		else {
			cout << "输入有误请重新输入" << endl;
		}

	}

	ofstream ofs;
	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	cout << tip << endl;
	while (true)
	{	
		cin >> id;
		bool ret = this->checkRepeat(id, select);
		if (ret)
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}                                                                                    


	}
	cout << "请输入用户名" << endl;
	cin >> name;
	cout << "请输入密码" << endl;
	cin >> pwd;
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功" << endl;
	system("pause");
	system("cls");
	ofs.close();
	this->initVector();


}
void printStu(Student s) {
	cout << "学号：" << s.m_Id << " 姓名：" << s.m_Name << " 密码：" << s.m_Pwd << endl;
}
void printTea(Teacher t) {
	cout << "学号：" <<t.m_EmpId<< " 姓名：" << t.m_Name << " 密码：" << t.m_Pwd << endl;
}
void Manager::
showPerson()
{
	cout << "请选择要查看的内容" << endl;
	cout << "1.查看所有的学生" << endl;
	cout << "2.查看所有的老师" << endl;
	int select;
	cin >> select;
	if (select == 1)
	{
		cout << "所有学生信息如下" << endl;
		for_each(this->vStu.begin(), this->vStu.end(), printStu);
	}
	else
	{
		cout << "所有老师信息如下" << endl;
		for_each(this->vTea.begin(), this->vTea.end(), printTea);

	}
	system("pause");
	system("cls");
}


void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "清空成功！" << endl;
	system("pause");
	system("cls");
}                                                                                                                                             
 

void Manager::initVector()
{
	this->vStu.clear();
	this->vTea.clear();
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd) {
		vStu.push_back(s);
	}
	cout << "当前学生的数量为" << vStu.size()<<endl;
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd) {
		vTea.push_back(t);
	}
	cout << "当前老师的数量为" << vTea.size() << endl;
	ifs.close();

}

bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++) {
			if (it->m_Id == id)
			{
				return true;
			}
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++) {
			if (it->m_EmpId == id) {
				return true;
			}
		}
	}
	return false;
}

void Manager::showComputer()
{
	cout << "机房信息如下： " << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "机房编号： " << it->m_ComId << " 机房最大容量： " << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}
