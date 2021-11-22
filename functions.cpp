#pragma once
#include "clases.h"

// √лавное меню
void MyMainMenu(int mode = 0, int time_out = 1)
{
    int numb = 0;
    out "Welcome to AutoGasStation app. Develop for DIRVE-MOTORS.\n";
    out Str(40, '-') <<"\n\n";
    out "Here you can make a report about: \n1. Car sale\n2. Sale of auto parts";
    out "\n3. Gas station\n";
    out Str(40, '-') << "\n\n";
    if (mode)
    {
        if (time_out == 4)
        {
            out"It's last try. Please don't be angry\n\n";
        }
        if (time_out == 5)
        {
            out "Your limit is out. Maybe it's our mistake. Please try agani later.\n\n";
            return;//выход из програмы в случае привышени€ количества вхождений
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

//‘ункци€ в зависимости от принимаемых значений выводит менюю дл€ взаимодействи€ с пользователем
int ChooseMenu(int numb, int time_out)
{
    switch (numb)
    {
    case 1:
        out "\nYour numb is 1 - " << numb << "\n";
        pass(10);
        out "|123|456789";
        break;
    case 2:
        out "\nYour numb is 2 - " << numb << "\n";
        break;
    case 3:
        out "\nYour numb is 3 - " << numb << "\n";
        break;
    default:
        system("cls"); // очистка экрана! ƒругой вариант не рассматриваетьс€
        MyMainMenu(2, ++time_out); // вызов функции главного меню с выводом ошибки, дл€ предотвращени€ перегрузки будет использоватьс€ второй параметр
        //обозначающий количество входов в функцию. ћаксимум 5.
        break;
    }

    return 0;
}

//далее методы классов

//класс AutoExamples

// онструктор задает значени€ марки, серии, количество и стоимость купленных авто
AutoExample::AutoExample(Str BrandBought, Str SeriesBought, short Number, int Cost) :
    Brand(BrandBought), Series(SeriesBought), NumberOfBought(Number), BuyCost(Cost)
{
    NumberOfSold = 0;
    SellCost = 0;
}

//ƒеструктор. «десь дл€ галочки)
AutoExample::~AutoExample()
{
}
//¬озвращает разницу купли / продажи, ѕроданные -  упленные
int AutoExample::GetDifference()
{
    return SellCost - BuyCost;
}

// ”станавливает стоимость проданного авто, можно купить лишь одно авто
int AutoExample::SetSellCost(int Cost)
{
    if (NumberOfBought >= NumberOfSold)
    {
        return -1;// ќшибка, св€занна€ с отсутствием авто на базе
    }
    SellCost += Cost;
    NumberOfSold++;// +1 проданный автомобиль
    return 0;
}

//  ласс AutoList

// деструктор, удал€ет весь список авто
AutoList::~AutoList()
{
    while (!PtrAutoList.empty()) // удаление всех auto
    { // удаление указателей из контейнера
        iter = PtrAutoList.begin();
        delete* iter;
        PtrAutoList.erase(iter);
    }

}

//¬ставка в список нового авто, в качестве аргумента принимает класс
int AutoList::insertAuto(AutoExample* PtrAuto)
{
    PtrAutoList.push_back(PtrAuto); // вставка нового авто в список
    return 0;
}

// ¬ыводит на экран список авто в формате ћарка сери€: количество
int AutoList::ShowAutoList()
{
   ///
   return 0;
}

//возвращает сумму доходов от продажи авто с учетом затраты, если авто не найдено -"-1"
int AutoList::ShowAnAutoCost(Str Brand, Str Series)
{
    iter = PtrAutoList.begin();
    while (iter != PtrAutoList.end())
    { // поиск авто в списке 
        if (Brand == ((*iter)->GetBrand()) && Series == (*iter)->GetSeries()) // сравниваем по именам и
        {
            // если получивша€с€ пара совпадает - значит, 
            //мы нашли запись об авто в списке, в этом случае 
            return (*iter)->GetDifference(); // возвращаем разницу купли/продажи
        }
        iter++;
    }
    return -1; // если нет - возвращаем -1
}

