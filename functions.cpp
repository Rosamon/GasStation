#pragma once
#include "clases.h"

// Главное меню
void MyMainMenu(int mode = 0, int time_out = 1)
{
    int numb = 0;
    out "Welcome to AutoGasStation app. Develop for DIRVE-MOTORS.\n\n";
    out "Here you can make a report about: \n1. Car sale\n2. Sale of auto parts";
    out "\n3. Gas station\n";
    if (mode)
    {
        if (time_out == 4)
        {
            out"It's last try. Please don't be angry\n\n";
        }
        if (time_out == 5)
        {
            out "Your limit is out. Maybe it's our mistake. Please try agani later.\n\n";
            return;//выход из програмы в случае привышения количества вхождений
        }
        out "You wrote a WRONG number! Please write again\n\n>>> ";
    }
    else
    {
        out "(Write a number for choose)\n\n>>> ";
    }

    input numb;
    ChooseMenu(numb, time_out);

}

//Функция в зависимости от принимаемых значений выводит менюю для взаимодействия с пользователем
int ChooseMenu(int numb, int time_out)
{
    switch (numb)
    {
    case 1:
        out "\nYour numb is 1 - " << numb << "\n";
        break;
    case 2:
        out "\nYour numb is 2 - " << numb << "\n";
        break;
    case 3:
        out "\nYour numb is 3 - " << numb << "\n";
        break;
    default:
        system("cls"); // очистка экрана! Другой вариант не рассматриваеться
        MyMainMenu(2, ++time_out); // вызов функции главного меню с выводом ошибки, для предотвращения перегрузки будет использоваться второй параметр
        //обозначающий количество входов в функцию. Максимум 5.
        break;
    }

    return 0;
}

//далее методы классов

//класс AutoExamples

//Конструктор задает значения марки, серии, количество и стоимость купленных авто
AutoExample::AutoExample(Str BrandBought, Str SeriesBought, short Number, int Cost) :
    Brand(BrandBought), Series(SeriesBought), NumberOfBought(Number), BuyCost(Cost)
{
    NumberOfSold = 0;
    SellCost = 0;
}

//Деструктор. Здесь для галочки)
AutoExample::~AutoExample()
{
}
//Возвращает разницу купли / продажи, Проданные - Купленные
int AutoExample::GetDifference()
{
    return SellCost - BuyCost;
}

// Устанавливает стоимость проданного авто, можно купить лишь одно авто
int AutoExample::SetSellCost(int Cost)
{
    if (NumberOfBought >= NumberOfSold)
    {
        return -1;// Ошибка, связанная с отсутствием авто на базе
    }
    SellCost += Cost;
    NumberOfSold++;// +1 проданный автомобиль
    return 0;
}

// Класс AutoList

// деструктор, удаляет весь список авто
AutoList::~AutoList()
{
    while (!PtrAutoList.empty()) // удаление всех auto
    { // удаление указателей из контейнера
        iter = PtrAutoList.begin();
        delete* iter;
        PtrAutoList.erase(iter);
    }

}

//Вставка в список нового авто
int AutoList::insertAuto(AutoExample* PtrAuto)
{
    PtrAutoList.push_back(PtrAuto); // вставка нового авто в список
}
