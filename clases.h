#pragma once
// Содержит классы файл этот
#include "inclusions.h"

//класс авто содержит свойства описывающие идентичность авто, а так же его статус
class AutoExample
{
public:
	AutoExample(Str BrandBought, Str SeriesBought, int Cost);//Konstructor
	~AutoExample();
	int SetSellCost(int Cost);// Устанавливает стоимость проданного авто, можно купить лишь одно авто
	Str GetBrand() { return Brand; };// Получить марку
	Str GetSeries() { return Series; };// Получить серию
private:
	Str Brand;// Мрака
	Str Series;// серия/модель, может быть как цифрой так и названием 
	int BuyCost;// сумма потраченная на покупку авто "Закупочная цена"
	int SellCost;// сумма вырученная с продажи всех авто этой марки и серии "Розничная цена"
	Str YearOfIssue;// Год выпуска авто
	Str Condition;// Состояние авто: "Sold" - продано, "New" - новое, "Used" - поддержаный
};

!! Добавить в конструктор новые поля + исправить ошибки, снять поля, которые не требуются

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

//
class AutoScreen
{
public:
	AutoScreen(AutoList* ptrAL):PtrAutoList(ptrAL) {};
	//~AutoScreen();
	void SetAuto();
private:
	AutoList* PtrAutoList;
	Str Brand;
	Str Series;
	short NumberOfBought;
	int Cost;
};
//22.11
