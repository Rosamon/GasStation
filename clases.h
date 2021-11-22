#pragma once
// �������� ������ ���� ����
#include "inclusions.h"

//����� ���� �������� �������� ����������� ������������ ����, � ��� �� ��� ������
class AutoExample
{
public:
	AutoExample(Str BrandBought, Str SeriesBought, short Number, int Cost);//Konstructor
	~AutoExample();
	int GetDifference();//���������� ������� �����/�������
	int SetSellCost(int Cost);// ������������� ��������� ���������� ����, ����� ������ ���� ���� ����
	Str GetBrand() { return Brand; };// �������� �����
	Str GetSeries() { return Series; };// �������� �����
	int GetNumberAuto() { return NumberOfBought - NumberOfSold; };//���������� ���� �� ������
private:
	Str Brand;// �����
	Str Series;// �����, ����� ���� ��� ������ ��� � ��������� 
	//�������� - char Status;// s - �������, b - ������� � ���� �� ��������
	short NumberOfBought;// ���������� �������������
	short NumberOfSold;// ���������� ���������
	int BuyCost;// ����� ����������� �� ������� ����
	int SellCost;// ����� ���������� � ������� ���� ���� ���� ����� � �����
};

// ����� �������� ��������� �� AutoExample, ������� ������ �� ��������� ������ AutoExample
class AutoList
{
public:
	//AutoList();
	~AutoList();
	int insertAuto(AutoExample*);// ��������� ������� ���� � ������
	int ShowAutoList();// ��������� ������ ����
	int ShowAnAutoCost(Str, Str);// ������� ��������� �����
private:
	std::list <AutoExample*> PtrAutoList; // ��������� �� ����� AutoExample
	std::list <AutoExample*>::iterator iter; //��������
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
