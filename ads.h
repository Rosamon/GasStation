#pragma once
//здесь находятся объявления функций
//Запуск главного меню
#include "clases.h"
int menu();
int MyMainMenu(AutoList);
int SaveDataAuto(int, AutoList&);
int WorkAutoScreen(AutoList&);
int WorkPartsScreen(PartList&);
int WorkReportScreen(AutoList&, PartList&);
int writeAutoReport(AutoList*);
int writePartsReport(PartList*);