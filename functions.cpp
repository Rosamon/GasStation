#pragma once
#include "clases.h"

int MyMainMenu(AutoList);

int menu() {
    AutoList* ptrAutoList = new AutoList();
    system("cls");
    MyMainMenu(*ptrAutoList);
    
    return 1;
}
// Главное меню
int MyMainMenu(AutoList ptrAutoList)
{
    int mode = 0;
    while (true)
    {
        out "\n\n";
        int numb = 0;
        out "Welcome to AutoGasStation app. Develop for DIRVE-MOTORS.\n";
        out Str(40, '-') << "\n\n";
        out "Here you can work with: \n1. Car sale\n2. Sale of auto parts";
        out "\n3. Gas station\n4. Exit\n";
        out Str(40, '-') << "\n\n";

        if (mode)
        {

            out "You wrote a WRONG number! Please write again\n\n>>> ";
        }
        else
        {
            out "(Write a number for choose)\n\n>>> ";
        }
        mode = 0;

        input numb;

        system("cls"); // очистка экрана! Другой вариант не рассматриваеться
        switch (numb)
        {
        case 1:
        {   out "Now you can only add one car\n";
        ptrAutoList.ShowAutoList();
        AutoScreen* ptrAutoScreen = new AutoScreen(&ptrAutoList);
        AutoExample* BuffAuto = ptrAutoScreen->SetAuto();
        ptrAutoList.insertAuto(BuffAuto);
        delete ptrAutoScreen;

        break;
        }
        case 2:
            out "\nYour numb is 2 - " << numb << "\n";
            break;
        case 3:
            out "\nYour numb is 3 - " << numb << "\n";
            break;
        case 4:
            return 1;
        default:
            mode += 1;
            //MyMainMenu(2); // вызов функции главного меню с выводом ошибки, для предотвращения перегрузки будет использоваться второй параметр
            //обозначающий количество входов в функцию. Максимум 5.
            break;
        }

        system("pause");
    }
}


//далее методы классов

//класс AutoExamples

//Конструктор задает значения марки, серии, количество и стоимость купленных авто
AutoExample::AutoExample(Str BrandBought, Str SeriesBought, int Cost):
    Brand(BrandBought), Series(SeriesBought), BuyCost(Cost)
{
    SellCost = 0;
}

//Деструктор. Здесь для галочки)
AutoExample::~AutoExample()
{
}

// Устанавливает стоимость проданного авто, можно купить лишь одно авто
int AutoExample::SetSellCost(int Cost)
{
    SellCost = Cost;
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
            //out (*iter)->GetNumberAuto();//количество на складе
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
            //return (*iter)->GetDifference(); // возвращаем разницу купли/продажи
        }
        iter++;
    }
    return -1; // если нет - возвращаем -1
}

// Класс AutoScreen

// интерфейс записи в список
AutoExample* AutoScreen::SetAuto()
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
    out "Enter cost of purchased cars\n>>>";
    input Cost;
    AutoExample* ptrAuto = new AutoExample(Brand, Series, Cost);// создать экземпляр авто
    return ptrAuto;
    //PtrAutoList->insertAuto(ptrAuto);//занести в список
    //ptrBuff.insertAuto(ptrAuto);
    //PtrAutoList->ShowAutoList();
}



