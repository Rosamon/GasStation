#pragma once
#include "clases.h"
#include "ads.h"

//деструктор
PartList::~PartList()
{
    while (!PtrPartList.empty()) // удаление всех записей
    { // удаление указателей из контейнера
        iter = PtrPartList.begin();
        delete* iter;
        PtrPartList.erase(iter);
    }

}

//Вставка в список нового авто, в качестве аргумента принимает класс
int PartList::insertParts(SparePart* PtrSparePart)
{
    PtrPartList.push_back(PtrSparePart); // вставка нового авто в список
    return 0;
}

int PartList::SellParts(Str Name, int Number)
{
    if (PtrPartList.empty()) // если список  пуст
    {
        out "List is empty!\n"; // выводим запись, что он пуст)
        return 1; //выходим с ошибкой
    }
    else
    {
        iter = PtrPartList.begin();
        while (iter != PtrPartList.end()) // вывод пока не конец
        {
            if ((Name == (*iter)->GetName()) && (Number == (*iter)->GetNumber()))
            {
                int cost = 0;
                out "\n Write a sell cost of one part and amount of it\n Cost >>> ";
                input cost;
                int Amount=0;
                out "\nAmount >>> ";
                input Amount;
                if ((*iter)->SetSellCost(cost * Amount, Amount))
                {
                    out "\nAmount of parts more than in stock!!\n";
                    return 1;
                }
                return 0;
            }

            *iter++;
            out"\n";
        }
    }
    return 1;
}

//Удаление из списка
int PartList::DeleteParts(Str Name, int Number)
{
    if (PtrPartList.empty()) // если список  пуст
    {
        out "List is empty!\n"; // выводим запись, что он пуст)
        return 1; //выходим с ошибкой
    }
    else
    {
        iter = PtrPartList.begin();
        while (iter != PtrPartList.end()) // вывод пока не конец
        {
            if ((Name == (*iter)->GetName()) && (Number == (*iter)->GetNumber()))
            {
                delete* iter;
                iter = PtrPartList.erase(iter);//удаление из списка и присваивание новой ссылки итератору
                return 0;
            }

            *iter++;
            out"\n";
        }
    }
    return 1;
}

// Выводит на экран список
int PartList::ShowAllList()
{
    pass(10);
    out "Name ";
    pass(10);
    out "| Brand ";
    pass(10);
    out "| Series ";
    pass(10);
    out "| Amount ";
    pass(10);
    out "| Number ";
    pass(10);
    out "| Condition ";
    out"\n";
    if (PtrPartList.empty()) // если список  пуст
        out "List is empty!\n"; // выводим запись, что он пуст)
    else
    {
        iter = PtrPartList.begin();
        while (iter != PtrPartList.end()) // вывод пока не конец
        {
            pass(10);
            out(*iter)->GetName();
            pass(10);
            out(*iter)->GetBrand();
            pass(10);
            out(*iter)->GetSeries();
            pass(10);
            out(*iter)->GetAmount();
            pass(10);
            out(*iter)->GetNumber();
            pass(10);
            out(*iter)->GetCondition();
            *iter++;
            out"\n";
        }
    }
    return 0;
}
int PartList::MakeReport()
{
    pass(10);
    out "Name ";
    pass(10);
    out "| Brand ";
    pass(10);
    out "| Series ";
    pass(10);
    out "| Amount ";
    pass(10);
    out "| Number ";
    pass(10);
    out "| Condition ";
    pass(15);
    out "| Proceeds  |";
    out"\n";
    int TotalIncome = 0;
    if (PtrPartList.empty()) // если список жильцов пуст
    {
        out "Cars is out!\n"; // выводим запись, что он пуст)
        return 1;
    }
    else
    {
        iter = PtrPartList.begin();
        while (iter != PtrPartList.end()) // вывод пока не конец
        {
            pass(10);
            out(*iter)->GetName();//
            pass(10);
            out(*iter)->GetBrand();//
            pass(10);
            out(*iter)->GetSeries(); //
            pass(10);
            out(*iter)->GetAmount();//
            pass(10);
            out(*iter)->GetNumber();//
            pass(10);
            out(*iter)->GetCondition();//
            pass(10);
            out(*iter)->GetBuyCost();
            int Buff = (*iter)->GetDiference();
            pass(10);
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
