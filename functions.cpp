#pragma once
#include "clases.h"

// ������� ����
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
            return;//����� �� �������� � ������ ���������� ���������� ���������
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

//������� � ����������� �� ����������� �������� ������� ����� ��� �������������� � �������������
int ChooseMenu(int numb, int time_out)
{
    system("cls"); // ������� ������! ������ ������� �� ����������������
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
        
        MyMainMenu(2, ++time_out); // ����� ������� �������� ���� � ������� ������, ��� �������������� ���������� ����� �������������� ������ ��������
        //������������ ���������� ������ � �������. �������� 5.
        break;
    }

    return 0;
}

//����� ������ �������

//����� AutoExamples

//����������� ������ �������� �����, �����, ���������� � ��������� ��������� ����
AutoExample::AutoExample(Str BrandBought, Str SeriesBought, short Number, int Cost) :
    Brand(BrandBought), Series(SeriesBought), NumberOfBought(Number), BuyCost(Cost)
{
    NumberOfSold = 0;
    SellCost = 0;
}

//����������. ����� ��� �������)
AutoExample::~AutoExample()
{
}
//���������� ������� ����� / �������, ��������� - ���������
int AutoExample::GetDifference()
{
    return SellCost - BuyCost;
}

// ������������� ��������� ���������� ����, ����� ������ ���� ���� ����
int AutoExample::SetSellCost(int Cost)
{
    if (NumberOfBought >= NumberOfSold)
    {
        return -1;// ������, ��������� � ����������� ���� �� ����
    }
    SellCost += Cost;
    NumberOfSold++;// +1 ��������� ����������
    return 0;
}

// ����� AutoList

// ����������, ������� ���� ������ ����
AutoList::~AutoList()
{
    while (!PtrAutoList.empty()) // �������� ���� auto
    { // �������� ���������� �� ����������
        iter = PtrAutoList.begin();
        delete* iter;
        PtrAutoList.erase(iter);
    }

}

//������� � ������ ������ ����, � �������� ��������� ��������� �����
int AutoList::insertAuto(AutoExample* PtrAuto)
{
    PtrAutoList.push_back(PtrAuto); // ������� ������ ���� � ������
    return 0;
}

// ������� �� ����� ������ ���� � ������� ����� �����: ����������
int AutoList::ShowAutoList()
{
    pass(10);
    out "Brand ";
    pass(10);
    out "| Series ";
    pass(10);
    out "| Amount";
    out"\n";
    if (PtrAutoList.empty()) // ���� ������ ������� ����
        out "Cars is out!\n"; // ������� ������, ��� �� ����)
    else
    {
        iter = PtrAutoList.begin();
        while (iter != PtrAutoList.end()) // ����� ���� �� �����
        {
            pass(10);
            out (*iter)->GetBrand(); 
            pass(10);
            out (*iter)->GetSeries();
            pass(10);
            out (*iter)->GetNumberAuto();//���������� �� ������
            *iter++;
            out"\n";
        }
    }
   return 0;
}

//���������� ����� ������� �� ������� ���� � ������ �������, ���� ���� �� ������� -"-1"
int AutoList::ShowAnAutoCost(Str Brand, Str Series)
{
    iter = PtrAutoList.begin();
    while (iter != PtrAutoList.end())
    { // ����� ���� � ������ 
        if (Brand == ((*iter)->GetBrand()) && Series == (*iter)->GetSeries()) // ���������� �� ����� � �����
        {
            // ���� ������������ ���� ��������� - ������, 
            //�� ����� ������ �� ���� � ������, � ���� ������ 
            return (*iter)->GetDifference(); // ���������� ������� �����/�������
        }
        iter++;
    }
    return -1; // ���� ��� - ���������� -1
}

// ����� AutoScreen

// ��������� ������ � ������
void AutoScreen::SetAuto() 
{
    
    //Str BufStr;
    //char temp[21];

    out "Enter brand of a car:\n>>> ";
    input Brand;
    out "\n";
    //std::cin.get(temp, 20, '\n');
    //std::cin.ignore(20, '\n'); //����� ������������ �������� � ������ ����������
    //BufStr = temp;
    out "Enter series of a car\n>>>";
    input Series;
    out "\n";
    out "Enter number of purchased cars\n>>>";
    input NumberOfBought;
    out "\n";
    out "Enter cost of purchased cars\n>>>";
    input Cost;
    AutoExample* ptrAuto = new AutoExample(Brand, Series, NumberOfBought, Cost);// ������� ��������� ����
    PtrAutoList->insertAuto(ptrAuto);//������� � ������
    PtrAutoList->ShowAutoList();
}



