#pragma once
//класс AutoExamples
#include "clases.h"
#include "ads.h"
// онструктор задает значени€ марки, серии, количество и стоимость купленных авто
AutoExample::AutoExample(Str BrandBought, Str SeriesBought, int Cost, Str Year, Str Condition) :
    Brand(BrandBought), Series(SeriesBought), BuyCost(Cost), YearOfIssue(Year), Condition(Condition)
{
    SellCost = 0;
}

//ƒеструктор. «десь дл€ галочки)
AutoExample::~AutoExample()
{
}

// ”станавливает стоимость проданного авто, можно купить лишь одно авто
int AutoExample::SetSellCost(int Cost)
{
    SellCost = Cost;
    SetCondition("Sold");
    return 0;
}
