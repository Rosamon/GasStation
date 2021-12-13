#pragma once
#include "clases.h"
#include "ads.h"

SparePart* PartsScreen::SetParts()
{
    out "Enter part's name:\n>>> ";
    input PartName;
    out "\n";
    out "Enter brand of a car:\n>>> ";
    input Brand;
    out "\n";
    out "Enter series (Mark) of a car\n>>> ";
    input Series;
    out "\n";
    out "Enter amount of buing parts:\n>>> ";
    input PartAmount;
    out "\n";
    out "Enter series number of buing parts:\n>>> ";
    input PartNumber;
    out "\n";
    out "Enter condition of parts (New, Used):\n>>> ";
    input Condition;
    out "\n";
    out "Enter cost of purchased parts\n>>> ";
    input BuyCost;
    SparePart* ptrAuto = new SparePart(PartName, Brand, Series, Condition, BuyCost, PartAmount, PartNumber);// создать экземпляр авто
    return ptrAuto;
}