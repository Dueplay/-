#pragma once
#include<iostream>
using namespace std;
#include <map>
#include "globalFile.h"
#include <string>
#include <fstream>
class OrderFile {
public:
	OrderFile();
	//����ԤԼ��¼
	void updateOrder();
public:
	map<int, map<string, string>> m_orderData;
	int m_Size;
};