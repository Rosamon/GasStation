#pragma once
//класс SparePart
#include "clases.h" // включение описани€ класса
#include "ads.h"
// онструктор задает значени€ марки, серии, количество и стоимость...
SparePart::SparePart(Str PartName, Str BrandBought, Str SeriesBought, Str Condition, int Cost, int Amount, int Number) :
    PartName(PartName), Brand(BrandBought), Series(SeriesBought), Condition(Condition), BuyCost(Cost), PartAmount(Amount), PartNumber(Number)
{
    SellCost = 0;
}

//ƒеструктор. 
SparePart::~SparePart()
{
}

// ”станавливает стоимость проданной запчасти, можно купить несколько за раз
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
        Condition = "Sold";// статус "продано" по€вл€етс€ после продажи всех запчастей
    }
    return 0;
}
int SparePart::GetDiference()
{
    return SellCost - BuyCost;
}