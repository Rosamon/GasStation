#pragma once
// здесь наход€тьс€ директивы включени€ библиотек и директивы подстановки
#include <iostream>

#ifndef out
#define out std::cout <<
#endif

#ifndef input
#define input std::cin >>
#endif
//дл€ простоты вывода в консоль сокращаем запись
#include "ads.h"
//#include "clases.h"
// 20.11
#include <string>
#include <list>
// 21.11
#ifndef Str
#define Str std::string
#endif
// ƒл€ простоты объ€влени€ строк. 
#ifndef pass
#define pass(x) std::cout << std::setw(x)
#endif
// ƒл€ форматировани€ вывода
#include <iomanip>
//22.11