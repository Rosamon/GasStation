#pragma once
#include "clases.h"
#include "ads.h"


int menu() {
    AutoList* ptrAutoList = new AutoList();
    PartList* ptrPartsList = new PartList();
    system("cls");
   MyMainMenu(*ptrAutoList, *ptrPartsList);
    ptrAutoList->~AutoList();//
    ptrPartsList->~PartList();//
    return 1;
}
int WorkReportScreen(AutoList& ptrAutoList, PartList& ptrPartList)
{
    //
    out "What kind of report do you wandt to make? \n";
    out "1. Income from car sales for the current mounth\n2. Income from the sale of auto parts for the current mounth\n";
    //out "3. Make an year report\n";
    out "4. Exit\n>>>";
    int numb = 0;
    input numb;
    switch (numb)
    {
    case 1:
        writeAutoReport(&ptrAutoList);
        break;
    case 2:
        writePartsReport(&ptrPartList);
        break;
    case 3:
        return 2;
        break;
    case 4:
    default:
        return 0;
        break;
    }
}
int writeAutoReport(AutoList* ptrAutoList)
{
    if (!ptrAutoList->MakeReport())
    {
        return 0;
        out "\n\n Do you want save this report in a TXT file?\nEnter y for yes\n>>>";
        Str Ans;
        input Ans;
        if (Ans != "y")
        {
            out "Sorry but this feature dosen't work yet :(";
            //ptrAutoList->SaveReport();
        }
    }
    return 0;
}

int writePartsReport(PartList* ptrPartList)
{
    if (!ptrPartList->MakeReport())
    {
        return 0;
        out "\n\n Do you want save this report in a TXT file?\nEnter y for yes\n>>>";
        Str Ans;
        input Ans;
        if (Ans != "y")
        {
            out "Sorry but this feature dosen't work yet :(";
            //ptrPartList->SaveReport();
        }
    }
    return 0;
}
// Главное меню
int MyMainMenu(AutoList ptrAutoList, PartList ptrPartsList)
{
    while (true)
    {
        int mode =0;
        system("cls");
        out "\n\n";
        int numb = 0;
        out "Welcome to AutoGasStation app. Develop for DIRVE-MOTORS.\n";
        out Str(40, '-') << "\n\n";
        out "Here you can work with: \n1. Car sale\n2. Sale of auto parts";
        out "\n3. Make an report\n4. Save an information\n5. Exit\n";
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
        {   
            WorkAutoScreen(ptrAutoList);
        break;
        }
        case 2:
            WorkPartsScreen(ptrPartsList);
            break;
        case 3:
            if (WorkReportScreen(ptrAutoList, ptrPartsList))
                return 2;
            break;
        case 4:
        {   
            out "\nWrite current mounth\n>>> ";
            int Mounth = 0;
            input Mounth;
            SaveDataAuto(Mounth, ptrAutoList);
            break;
        }
        case 5:
            return 1;
        default: 
            mode++;
            break;
        }
        out"\n";
        system("pause");
    }
}

int WorkAutoScreen(AutoList& ptrAutoList)
{
    int numb;
    out "\n1. Add a car\n2. Delete a car\n3. Sell a car\n4. Show all cars\n >>> ";
    input numb; // Принимаем решение в зависимости от выбранной цифры (переменная была уже использована)
    switch (numb)
    {
    case 1:
    {
        system("cls");
        out "Now you can only add one car\n";
        AutoScreen* ptrAutoScreen = new AutoScreen(&ptrAutoList);
        AutoExample* BuffAuto = ptrAutoScreen->SetAuto();
        ptrAutoList.insertAuto(BuffAuto);
        delete ptrAutoScreen;
    }
    break;
    case 2:
    {
        ptrAutoList.ShowAutoList();
        out "\n\nWrite the brand and series of a car for delete";
        out "\n\nWrite the brand >> ";
        Str BrandCar;
        input BrandCar;
        out "\n\nWrite the series >> ";
        Str SeriesCar;
        input SeriesCar;
        if (!ptrAutoList.DeleteCar(BrandCar, SeriesCar))
        {
            out "\n Deleted\n";
        }
        else
        {
            out "\nCar wasn't delete!!!\n";
        }
    }
    break;
    case 3:
    {
        ptrAutoList.ShowAutoList();
        out "\n\nWrite the brand and series of a car for sell";
        out "\n\nWrite the brand >> ";
        Str BrandCar;
        input BrandCar;
        out "\n\nWrite the series >> ";
        Str SeriesCar;
        input SeriesCar;
        if (!ptrAutoList.SellCar(BrandCar, SeriesCar))
        {
            out "\n Sold\n";
        }
        else
        {
            out "\nCar wasn't sell!!!\n";
        }
    }
    break;
    case 4:
    {
        ptrAutoList.ShowAutoList();
    }
    }
    return 0;
}

int WorkPartsScreen(PartList& ptrPartsList)
{
    int numb;
    out "\n1. Add spare parts\n2. Delete spare parts\n3. Sell spare parts\n4. Show all list of parts\n >>> ";
    input numb; // Принимаем решение в зависимости от выбранной цифры (переменная была уже использована)
    switch (numb)
    {
    case 1:
    {
        system("cls");
        out "Now you can only add one car\n";
        PartsScreen* ptrPartsScreen = new PartsScreen(&ptrPartsList);
        SparePart* Buffer = ptrPartsScreen->SetParts();
        ptrPartsList.insertParts(Buffer);
        delete ptrPartsScreen;
    }
    break;
    case 2:
    {
        ptrPartsList.ShowAllList();
        out "\n\nWrite the name of a part and series number of a part for delete";
        out "\n\nWrite the name >> ";
        Str Name;
        input Name;
        out "\n\nWrite the series number >> ";
        int SeriesNumber;
        input SeriesNumber;
        if (!ptrPartsList.DeleteParts(Name, SeriesNumber))
        {
            out "\n Deleted\n";
        }
        else
        {
            out "\nLine wasn't delete!!!\n";
        }
    }
    break;
    case 3:
    {
        ptrPartsList.ShowAllList();
        out "\n\nWrite the name of a part and series number of a part for sell";
        out "\n\nWrite the name >> ";
        Str Name;
        input Name;
        out "\n\nWrite the series number >> ";
        int SeriesNumber;
        input SeriesNumber;
        if (!ptrPartsList.SellParts(Name, SeriesNumber))
        {
            out "\n Sold\n";
        }
        else
        {
            out "\nParts weren't sell!!!\n";
        }
    }
    break;
    case 4:
    {
        ptrPartsList.ShowAllList();
    }
    }
    return 0;
}

//далее методы классов

// Класс AutoScreen

// интерфейс записи в список
AutoExample* AutoScreen::SetAuto()
{
    
    out "Enter brand of a car:\n>>> ";
    input Brand;
    out "\n";
    out "Enter series of a car\n>>> ";
    input Series;
    out "\n";
    out "Enter car's year of issue:\n>>> ";
    input Year;
    out "\n";
    out "Enter condition of a car (New, Used):\n>>> ";
    input Condition;
    out "\n";
    out "Enter cost of purchased car\n>>> ";
    input Cost;
    AutoExample* ptrAuto = new AutoExample(Brand, Series, Cost,Year, Condition);// создать экземпляр авто
    return ptrAuto;
}

int SaveDataAuto(int Mounth, AutoList& WriteList)
{
    out "\nSorry but this feature doesn't work yet\n";
    return 0;
}


