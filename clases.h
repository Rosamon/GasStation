#pragma once
// Содержит классы файл этот
#include "inclusions.h"

//класс авто содержит свойства описывающие идентичность авто, а так же его статус
class AutoExample
{
public:
	AutoExample(Str BrandBought, Str SeriesBought, short Number, int Cost);
	~AutoExample();
	int GetDifference();//Возвращает разницу купли/продажи
	int SetSellCost(int Cost);// Устанавливает стоимость проданного авто, можно купить лишь одно авто
	Str GetBrand() { return Brand; };// Получить марку
	Str GetSeries() { return Series; };// Получить серию
private:
	Str Brand;// Мрака
	Str Series;// серия, может быть как цифрой так и названием 
	//рудимент - char Status;// s - продано, b - куплено и есть во владении
	short NumberOfBought;// Количество приобретенных
	short NumberOfSold;// количество проданных
	int BuyCost;// сумма потраченная на покупку авто
	int SellCost;// сумма вырученная с продажи всех авто этой марки и серии
};

// Класс содержит указатели на AutoExample, создает список из элементов класса AutoExample
class AutoList
{
public:
	//AutoList();
	~AutoList();
	int insertAuto(AutoExample*);// Позволяет добавть авто в список
	int ShowAutoList();// Показыает список авто
	int ShowAnAutoCost(Str, Str);// Разница отдельной марки
private:
	std::list <AutoExample*> PtrAutoList; // указатели на класс AutoExample
	std::list <AutoExample*>::iterator iter; //итератор
};


//22.11
