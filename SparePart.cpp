#pragma once
//����� SparePart
#include "clases.h" // ��������� �������� ������
#include "ads.h"
//����������� ������ �������� �����, �����, ���������� � ���������...
SparePart::SparePart(Str PartName, Str BrandBought, Str SeriesBought, Str Condition, int Cost, int Amount, int Number) :
    PartName(PartName), Brand(BrandBought), Series(SeriesBought), Condition(Condition), BuyCost(Cost), PartAmount(Amount), PartNumber(Number)
{
    SellCost = 0;
}

//����������. 
SparePart::~SparePart()
{
}

// ������������� ��������� ��������� ��������, ����� ������ ��������� �� ���
int SparePart::SetSellCost(int Cost, int Amount)
{
    if ((Amount > PartAmount) || (Condition == "Sold"))
    {
        return 1;
    }
    SellCost += Cost;
    PartAmount -= Amount;
    if (PartAmount == 0)
    {
        Condition = "Sold";// ������ "�������" ���������� ����� ������� ���� ���������
    }
    return 0;
}
int SparePart::GetDiference()
{
    return SellCost - BuyCost;
}