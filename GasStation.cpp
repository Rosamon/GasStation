﻿//GasStation.cpp  main file
//Здесь находится вход в программу. Функция содержит вызов функции "главное меню" - MainMenu
//Все подпрограммы распологаються в других файлах.
#include "inclusions.h" //Содержит в себе директивы включения библиотек и директивы подстановки

int main()
{
    //Функция setlocale() задаёт локализацию программы.
    setlocale(LC_ALL, "rus");
    int x = 1;
    while (!x)
    {
        MyMainMenu(0, 1);
    }
    return 0;
}
