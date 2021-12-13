#pragma once
#include "clases.h"
#include "ads.h"

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

//�������� ���� �� ��������� ��������� ����� � ����� (��������� ������ ���������)
int AutoList::DeleteCar(Str Brand, Str Series)
{
    if (PtrAutoList.empty()) // ���� ������  ����
    {
        out "Cars is out!\n"; // ������� ������, ��� �� ����)
        return 1; //������� � �������
    }
    else
    {
        iter = PtrAutoList.begin();
        while (iter != PtrAutoList.end()) // ����� ���� �� �����
        {
            if ((Brand == (*iter)->GetBrand()) && (Series == (*iter)->GetSeries()))
            {
                delete* iter;
                iter = PtrAutoList.erase(iter);//�������� �� ������ � ������������ ����� ������ ���������
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
    if (PtrAutoList.empty()) // ���� ������  ����
    {
        out "Cars is out!\n"; // ������� ������, ��� �� ����)
        return 1; //������� � �������
    }
    else
    {
        iter = PtrAutoList.begin();
        while (iter != PtrAutoList.end()) // ����� ���� �� �����
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

// ������� �� ����� ������ ���� � ������� ����� �����: ����������
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
    if (PtrAutoList.empty()) // ���� ������ ������� ����
        out "Cars is out!\n"; // ������� ������, ��� �� ����)
    else
    {
        iter = PtrAutoList.begin();
        while (iter != PtrAutoList.end()) // ����� ���� �� �����
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
    if (PtrAutoList.empty()) // ���� ������ ������� ����
    {
        out "Cars is out!\n"; // ������� ������, ��� �� ����)
        return 1;
    }
    else
    {
        iter = PtrAutoList.begin();
        while (iter != PtrAutoList.end()) // ����� ���� �� �����
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
