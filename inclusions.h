#pragma once
// здесь находятся директивы включения библиотек и директивы подстановки
#include <iostream>

#ifndef out
#define out std::cout <<
#endif

#ifndef input
#define input std::cin >>
#endif
//для простоты вывода в консоль сокращаем запись

//#include "clases.h"
// 20.11
#include <string>
#include <list>
// 21.11
#ifndef Str
#define Str std::string
#endif
// Для простоты объявления строк.
#ifndef pass
#define pass(x) std::cout << std::setw(x) // Пропуск символов в количестве x
#endif
// Для форматирования вывода
#include <iomanip>
//22.11
