#pragma once
// Содержит классы файл этот
#include "inclusions.h"

//класс авто содержит свойства описывающие идентичность авто, а так же его статус
class AutoExample
{
public:
	AutoExample(Str BrandBought, Str SeriesBought, int Cost, Str Year, Str Condition);//Konstructor
	~AutoExample();
	int SetSellCost(int Cost);// Устанавливает стоимость проданного авто, можно купить лишь одно авто
	Str GetBrand() { return Brand; };// Получить марку
	Str GetSeries() { return Series; };// Получить серию
	Str GetYear() { return YearOfIssue; };// получить год выпуска авто
	Str GetCondition() { return Condition; };//Поучить статус авто
	void SetCondition(Str Cond) { Condition = Cond; };
private:
	Str Brand;// Марка
	Str Series;// серия/модель, может быть как цифрой так и названием 
	int BuyCost;// сумма потраченная на покупку авто "Закупочная цена"
	int SellCost;// сумма вырученная с продажи авто "Розничная цена"
	Str YearOfIssue;// Год выпуска авто
	Str Condition;// Состояние авто: "Sold" - продано, "New" - новое, "Used" - поддержаный
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
	int DeleteCar(Str, Str);// удалить из списка выбранное авто
	int SellCar(Str, Str);// Поменять стутс авто из списка
private:
	std::list <AutoExample*> PtrAutoList; // указатели на класс AutoExample
	std::list <AutoExample*>::iterator iter; //итератор
};

//
class AutoScreen
{
public:
	AutoScreen(AutoList* ptrAL):PtrAutoList(ptrAL) {};
	//~AutoScreen();
	AutoExample* SetAuto();
private:
	AutoList* PtrAutoList;
	Str Brand;
	Str Series;
	Str Year;
	Str Condition;
	short NumberOfBought;
	int Cost;
};
//22.11
