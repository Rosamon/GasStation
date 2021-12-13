#pragma once
#include "clases.h"
#include "ads.h"

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

//Вставка в список нового авто, в качестве аргумента принимает класс
int AutoList::insertAuto(AutoExample* PtrAuto)
{
    PtrAutoList.push_back(PtrAuto); // вставка нового авто в список
    return 0;
}

//Удаление авто по введенным значениям марки и серии (Удаляется первое вхождение)
int AutoList::DeleteCar(Str Brand, Str Series)
{
    if (PtrAutoList.empty()) // если список  пуст
    {
        out "Cars is out!\n"; // выводим запись, что он пуст)
        return 1; //выходим с ошибкой
    }
    else
    {
        iter = PtrAutoList.begin();
        while (iter != PtrAutoList.end()) // вывод пока не конец
        {
            if ((Brand == (*iter)->GetBrand()) && (Series == (*iter)->GetSeries()))
            {
                delete* iter;
                iter = PtrAutoList.erase(iter);//удаление из списка и присваивание новой ссылки итератору
                return 0;
            }

            *iter++;
            out"\n";
        }
    }
    return 1;
}

int AutoList::SellCar(Str Brand, Str Series)
{
    if (PtrAutoList.empty()) // если список  пуст
    {
        out "Cars is out!\n"; // выводим запись, что он пуст)
        return 1; //выходим с ошибкой
    }
    else
    {
        iter = PtrAutoList.begin();
        while (iter != PtrAutoList.end()) // вывод пока не конец
        {
            if ((Brand == (*iter)->GetBrand()) && (Series == (*iter)->GetSeries()))
            {
                int numb = 0;
                out "\n Write a sell cost\n >>> ";
                input numb;
                (*iter)->SetSellCost(numb);
                return 0;
            }

            *iter++;
            out"\n";
        }
    }
    return 1;
}

// Выводит на экран список авто в формате Марка серия: количество
int AutoList::ShowAutoList()
{
    pass(10);
    out "Brand ";
    pass(10);
    out "| Series ";
    pass(10);
    out "| Year ";
    pass(10);
    out "| Condition ";
    out"\n";
    if (PtrAutoList.empty()) // если список жильцов пуст
        out "Cars is out!\n"; // выводим запись, что он пуст)
    else
    {
        iter = PtrAutoList.begin();
        while (iter != PtrAutoList.end()) // вывод пока не конец
        {
            pass(10);
            out(*iter)->GetBrand();
            pass(10);
            out(*iter)->GetSeries();
            pass(10);
            out(*iter)->GetYear();
            pass(10);
            out(*iter)->GetCondition();
            *iter++;
            out"\n";
        }
    }
    return 0;
}
int AutoList::MakeReport()
{
    pass(10);
    out "Brand ";
    pass(10);
    out "| Series ";
    pass(10);
    out "| Year ";
    pass(15);
    out "| Condition ";
    pass(15);
    out "| Price ";
    pass(15);
    out "| Proceeds  |";
    out"\n";
    int TotalIncome = 0;
    if (PtrAutoList.empty()) // если список жильцов пуст
    {
        out "Cars is out!\n"; // выводим запись, что он пуст)
        return 1;
    }
    else
    {
        iter = PtrAutoList.begin();
        while (iter != PtrAutoList.end()) // вывод пока не конец
        {
            pass(10);
            out(*iter)->GetBrand();
            pass(10);
            out(*iter)->GetSeries();
            pass(10);
            out(*iter)->GetYear();
            pass(15);
            out(*iter)->GetCondition();
            pass(15);
            out(*iter)->GetBuycost();
            pass(15);
            int Buff = (*iter)->ShowAnAutoCost();
            out Buff;
            TotalIncome += Buff;
            *iter++;
            out"\n";
        }
    }
    out "\n\n";
    pass(40);
    out "Total income: " << TotalIncome;
    return 0;
}
