#pragma once
//����� AutoExamples
#include "clases.h"
#include "ads.h"
//����������� ������ �������� �����, �����, ���������� � ��������� ��������� ����
AutoExample::AutoExample(Str BrandBought, Str SeriesBought, int Cost, Str Year, Str Condition) :
    Brand(BrandBought), Series(SeriesBought), BuyCost(Cost), YearOfIssue(Year), Condition(Condition)
{
    SellCost = 0;
}

//����������. ����� ��� �������)
AutoExample::~AutoExample()
{
}

// ������������� ��������� ���������� ����, ����� ������ ���� ���� ����
int AutoExample::SetSellCost(int Cost)
{
    SellCost = Cost;
    SetCondition("Sold");
    return 0;
}
