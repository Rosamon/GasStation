#pragma once
// ����� ���������� ��������� ��������� ��������� � ��������� �����������
#include <iostream>

#ifndef out
#define out std::cout <<
#endif

#ifndef input
#define input std::cin >>
#endif
//��� �������� ������ � ������� ��������� ������
#include "ads.h"
//#include "clases.h"
// 20.11
#include <string>
#include <list>
// 21.11
#ifndef Str
#define Str std::string
#endif
// ��� �������� ���������� �����. 
#ifndef pass
#define pass(x) std::cout << std::setw(x)
#endif
// ��� �������������� ������
#include <iomanip>
//22.11