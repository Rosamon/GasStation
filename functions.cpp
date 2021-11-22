#pragma once
#include "inclusions.h"

// ������� ����
void MyMainMenu(int mode = 0, int time_out = 1)
{
    int numb = 0;
    out "Welcome to AutoGasStation app. Develop for DIRVE-MOTORS.\n\n";
    out "Here you can make a report about: \n1. Car sale\n2. Sale of auto parts";
    out "\n3. Gas station\n";
    if (mode)
    {
        if (time_out == 5)
        {
            out "Your limit is out. Maybe it's our mistake. Please try agani later.\n\n";
            return;//����� �� �������� � ������ ���������� ���������� ���������
        }
        out "You wrote a WRONG number! Please write again\n\n>>> ";
    }
    else
    {
        out "(Write a number for choose)\n\n>>> ";
    }

    input numb;
    ChooseMenu(numb, time_out);

}

//������� � ����������� �� ����������� �������� ������� ����� ��� �������������� � �������������
int ChooseMenu(int numb, int time_out)
{
    switch (numb)
    {
    case 1:
        out "\nYour numb is 1 - " << numb << "\n";
        break;
    case 2:
        out "\nYour numb is 2 - " << numb << "\n";
        break;
    case 3:
        out "\nYour numb is 3 - " << numb << "\n";
        break;
    default:
        system("cls"); // ������� ������! ������ ������� �� ����������������
        MyMainMenu(2, ++time_out); // ����� ������� �������� ���� � ������� ������, ��� �������������� ���������� ����� �������������� ������ ��������
        //������������ ���������� ������ � �������. �������� 5.
        break;
    }

    return 0;
}