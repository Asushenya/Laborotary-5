#include "stdafx.h"
#include "HeadPhone.h"
#include <Windows.h>


HANDLE hConsole5 = GetStdHandle(STD_OUTPUT_HANDLE);

HeadPhone::HeadPhone(string Name,int UPBorder,int DOWNBorder):
	Product(/*Name*/)
{
    quantityOfDays = 1450;
    price = 2000;
    headPhonename = Name;
	upBorder = UPBorder;
	downBorder = DOWNBorder;
}


HeadPhone::~HeadPhone()
{
}

void HeadPhone::showInfo()
{
	SetConsoleTextAttribute(hConsole5, (WORD)((2 << 4) | 10));
	cout << "Информация о Наушниках: " << endl;
	
    SetConsoleTextAttribute(hConsole5, (WORD)((2 << 2) | 20));
    cout << "Производитель Наушников: " << headPhonename << endl;

	SetConsoleTextAttribute(hConsole5, (WORD)((2 << 1) | 1));
	cout << "	Нижняя граница: " << downBorder << "GHz" << endl;
	cout << "	Верхняя граница: " << upBorder << "GHz" << endl;
    cout << "Количество дней в работе " << quantityOfDays << endl;
    cout << "Цна наушников: " << price << endl;
	SetConsoleTextAttribute(hConsole5, (WORD)((0 << 0) | 7));
	

}

int HeadPhone::getDownBorder()
{
    return downBorder;
}

int HeadPhone::getUPBorder()
{
    return upBorder;
}