#pragma once
// —одержит классы файл этот
#include "inclusions.h"

//класс авто содержит свойства описывающие идентичность авто, а так же его статус
class AutoExample
{
public:
	AutoExample(Str BrandBought, Str SeriesBought, short Number, int Cost);
	~AutoExample();
	int GetDifference();//¬озвращает разницу купли/продажи
	int SetSellCost(int Cost);// ”станавливает стоимость проданного авто, можно купить лишь одно авто
private:
	Str Brand;// ћрака
	Str Series;// сери€, может быть как цифрой так и названием 
	//рудимент - char Status;// s - продано, b - куплено и есть во владении
	short NumberOfBought;//  оличество приобретенных
	short NumberOfSold;// количество проданных
	int BuyCost;// сумма потраченна€ на покупку авто
	int SellCost;// сумма вырученна€ с продажи всех авто этой марки и серии
};

//  ласс содержит указатели на AutoExample, создает список из элементов класса AutoExample
class AutoList
{
public:
	//AutoList();
	~AutoList();
	int insertAuto(AutoExample*);// ѕозвол€ет добавть авто в список
	int ShowAutoList();// ѕоказыает список авто
private:
	std::list <AutoExample*> PtrAutoList; // указатели на класс AutoExample
	std::list <AutoExample*>::iterator iter; //итератор
};


//22.11
