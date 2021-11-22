#pragma once
// �������� ������ ���� ����
#include "inclusions.h"

//����� ���� �������� �������� ����������� ������������ ����, � ��� �� ��� ������
class AutoExample
{
public:
	AutoExample(Str BrandBought, Str SeriesBought, short Number, int Cost);
	~AutoExample();
	int GetDifference();//���������� ������� �����/�������
	int SetSellCost(int Cost);// ������������� ��������� ���������� ����, ����� ������ ���� ���� ����
private:
	Str Brand;// �����
	Str Series;// �����, ����� ���� ��� ������ ��� � ��������� 
	//�������� - char Status;// s - �������, b - ������� � ���� �� ��������
	short NumberOfBought;// ���������� �������������
	short NumberOfSold;// ���������� ���������
	int BuyCost;// ����� ����������� �� ������� ����
	int SellCost;// ����� ���������� � ������� ���� ���� ���� ����� � �����
};


