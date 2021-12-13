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
	int ShowAnAutoCost() { return SellCost - BuyCost; };
	int GetBuycost() { return BuyCost; };
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
	int DeleteCar(Str, Str);// удалить из списка выбранное авто
	int SellCar(Str, Str);// Поменять стутс авто из списка
	int MakeReport();
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
//класс SparePart содержит свойства описывающие идентичность количества запчастей
class SparePart
{
public:
	SparePart(Str , Str , Str, Str, int , int, int );//Konstructor
	~SparePart();
	int SetSellCost(int, int);// Устанавливает стоимость проданной запчасти, можно купить несколько за раз
	int GetDiference();// Возвращает разницу купли/продажи запчастей
	Str GetBrand() { return Brand; };// Получить марку
	Str GetSeries() { return Series; };// Получить серию
	Str GetName() { return PartName; };// получить год выпуска авто
	Str GetCondition() { return Condition; };//Поучить статус авто
	int GetAmount() { return PartAmount; };// получить количество запчатсей на складе
	int GetNumber() { return PartNumber; };
	int GetBuyCost() { return BuyCost; };
private:
	Str Brand;// Марка авто
	Str Series;// серия/модель, может быть как цифрой так и названием
	int BuyCost;// сумма потраченная на покупку запчастей "Закупочная цена"
	int SellCost;// сумма вырученная с продажи запчастей "Розничная цена"
	int PartNumber;// Номер\Код запчасти (из серйиного производства)
	int PartAmount;// Количество запчастей на складе
	Str PartName;// Название запчасти
	Str Condition;// Состояние запчастей: "New" - новые, "Used" - поддержаные
};
//+

// Класс содержит указатели на SpareParts, создает список из элементов класса SpareParts
class PartList
{
public:
	~PartList();
	int insertParts(SparePart*);// Позволяет добавть в список
	int ShowAllList();// Показыает весь список
	int DeleteParts(Str, int);// удалить из списка выбранные запчасти
	int SellParts(Str, int);//продажа запчастей
	int MakeReport();
private:
	std::list <SparePart*> PtrPartList; // указатели на класс 
	std::list <SparePart*>::iterator iter; //итератор
};

//
class PartsScreen
{
public:
	PartsScreen(PartList* ptrPL) : PtrPartList(ptrPL) {};
	SparePart* SetParts();
private:
	PartList* PtrPartList;
	Str Brand;
	Str Series;
	int BuyCost;
	int PartNumber;
	int PartAmount;
	Str PartName;
	Str Condition;
};
