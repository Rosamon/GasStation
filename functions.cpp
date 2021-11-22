#pragma once
#include "clases.h"

// Главное меню
void MyMainMenu(int mode = 0, int time_out = 1)
{
    int numb = 0;
    out "Welcome to AutoGasStation app. Develop for DIRVE-MOTORS.\n";
    out Str(40, '-') <<"\n\n";
    out "Here you can work with: \n1. Car sale\n2. Sale of auto parts";
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
    system("cls"); // очистка экрана! Другой вариант не рассматриваеться
    switch (numb)
    {
    case 1:
    {   out "Now you can only add couple of cars\n";
        AutoList* ptrAutoList = new AutoList();
        AutoScreen* ptrAutoScreen = new AutoScreen(ptrAutoList);
        ptrAutoScreen->SetAuto();
        delete ptrAutoScreen;
        break;
    }
    case 2:
        out "\nYour numb is 2 - " << numb << "\n";
        break;
    case 3:
        out "\nYour numb is 3 - " << numb << "\n";
        break;
    default:
        
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

//Вставка в список нового авто, в качестве аргумента принимает класс
int AutoList::insertAuto(AutoExample* PtrAuto)
{
    PtrAutoList.push_back(PtrAuto); // вставка нового авто в список
    return 0;
}

// Выводит на экран список авто в формате Марка серия: количество
int AutoList::ShowAutoList()
{
    pass(10);
    out "Brand ";
    pass(10);
    out "| Series ";
    pass(10);
    out "| Amount";
    out"\n";
    if (PtrAutoList.empty()) // если список жильцов пуст
        out "Cars is out!\n"; // выводим запись, что он пуст)
    else
    {
        iter = PtrAutoList.begin();
        while (iter != PtrAutoList.end()) // вывод пока не конец
        {
            pass(10);
            out (*iter)->GetBrand(); 
            pass(10);
            out (*iter)->GetSeries();
            pass(10);
            out (*iter)->GetNumberAuto();//количество на складе
            *iter++;
            out"\n";
        }
    }
   return 0;
}

//возвращает сумму доходов от продажи авто с учетом затраты, если авто не найдено -"-1"
int AutoList::ShowAnAutoCost(Str Brand, Str Series)
{
    iter = PtrAutoList.begin();
    while (iter != PtrAutoList.end())
    { // поиск авто в списке 
        if (Brand == ((*iter)->GetBrand()) && Series == (*iter)->GetSeries()) // сравниваем по марке и серии
        {
            // если получившаяся пара совпадает - значит, 
            //мы нашли запись об авто в списке, в этом случае 
            return (*iter)->GetDifference(); // возвращаем разницу купли/продажи
        }
        iter++;
    }
    return -1; // если нет - возвращаем -1
}

// Класс AutoScreen

// интерфейс записи в список
void AutoScreen::SetAuto() 
{
    
    //Str BufStr;
    //char temp[21];

    out "Enter brand of a car:\n>>> ";
    input Brand;
    out "\n";
    //std::cin.get(temp, 20, '\n');
    //std::cin.ignore(20, '\n'); //число пропускаемых символов и символ разделения
    //BufStr = temp;
    out "Enter series of a car\n>>>";
    input Series;
    out "\n";
    out "Enter number of purchased cars\n>>>";
    input NumberOfBought;
    out "\n";
    out "Enter cost of purchased cars\n>>>";
    input Cost;
    AutoExample* ptrAuto = new AutoExample(Brand, Series, NumberOfBought, Cost);// создать экземпляр авто
    PtrAutoList->insertAuto(ptrAuto);//занести в список
    PtrAutoList->ShowAutoList();
}



