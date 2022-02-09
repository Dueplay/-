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
	cout << "��ǰ��������Ϊ�� " << vCom.size() << endl;

	ifs.close();
}

void Manager::operMenu()
{	
	cout << "��ӭ����Ա��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.����˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.�鿴�˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.�鿴����            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.���ԤԼ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.ע����¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

void Manager::addPerson()
{
	cout << "����������˺ŵ�����" << endl;
	cout << "1�����ѧ��" << endl;
	cout << "2�������ʦ" << endl;
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
			tip = "������ѧ��";
			errorTip = "ѧ���ظ�������������";
			break;
		}
		else if (select == 2) {
			fileName = TEACHER_FILE;
			tip = "������ְ����";
			errorTip = "ְ�����ظ�������������";
			break;
		}
		else {
			cout << "������������������" << endl;
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
	cout << "�������û���" << endl;
	cin >> name;
	cout << "����������" << endl;
	cin >> pwd;
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ�" << endl;
	system("pause");
	system("cls");
	ofs.close();
	this->initVector();


}
void printStu(Student s) {
	cout << "ѧ�ţ�" << s.m_Id << " ������" << s.m_Name << " ���룺" << s.m_Pwd << endl;
}
void printTea(Teacher t) {
	cout << "ѧ�ţ�" <<t.m_EmpId<< " ������" << t.m_Name << " ���룺" << t.m_Pwd << endl;
}
void Manager::
showPerson()
{
	cout << "��ѡ��Ҫ�鿴������" << endl;
	cout << "1.�鿴���е�ѧ��" << endl;
	cout << "2.�鿴���е���ʦ" << endl;
	int select;
	cin >> select;
	if (select == 1)
	{
		cout << "����ѧ����Ϣ����" << endl;
		for_each(this->vStu.begin(), this->vStu.end(), printStu);
	}
	else
	{
		cout << "������ʦ��Ϣ����" << endl;
		for_each(this->vTea.begin(), this->vTea.end(), printTea);

	}
	system("pause");
	system("cls");
}


void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "��ճɹ���" << endl;
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
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd) {
		vStu.push_back(s);
	}
	cout << "��ǰѧ��������Ϊ" << vStu.size()<<endl;
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd) {
		vTea.push_back(t);
	}
	cout << "��ǰ��ʦ������Ϊ" << vTea.size() << endl;
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
	cout << "������Ϣ���£� " << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "������ţ� " << it->m_ComId << " ������������� " << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}
