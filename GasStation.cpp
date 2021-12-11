//GasStation.cpp  main file
//Здесь находится вход в программу. Функция содержит вызов функции "главное меню" - MainMenu
//Все подпрограммы распологаються в других файлах.
#include "inclusions.h" //Содержит в себе директивы включения библиотек и директивы подстановки
#include "ads.h"
int main()
{
    //Функция setlocale() задаёт локализацию программы.
    setlocale(LC_ALL, "rus");
    menu();
    system("cls");
    out "Yure a best";
    return 0;
}
