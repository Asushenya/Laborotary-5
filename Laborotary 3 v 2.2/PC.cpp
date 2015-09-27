#include "stdafx.h"
#include "PC.h"
#include <Windows.h>

HANDLE hConsole1 = GetStdHandle(STD_OUTPUT_HANDLE);

PC::PC(string Name,double Cpu):
	Product(/*Name*/)
    {
        quantityOfDays = 1200;
        price = 1000;
        proccesorName = Name;
	    cpu = Cpu;
    }


PC::~PC()
    {
    }

void PC::showInfo()
    {
        
	    SetConsoleTextAttribute(hConsole1, (WORD)((2 << 4) | 10));
	    cout << "Информация о Процессоре: " << endl;
	    SetConsoleTextAttribute(hConsole1, (WORD)((0 << 0) | 7));
	  
        SetConsoleTextAttribute(hConsole1, (WORD)((2 << 2) | 20));
          cout << "Производитель Процессора: " << proccesorName<<endl;
	    SetConsoleTextAttribute(hConsole1, (WORD)((2 << 2) | 4));
	    cout << "        CPU: " << cpu << endl;
        cout << "Количество дней в работе " << quantityOfDays << endl;
        cout << "Цена процессора:  " << price<<" бел/руб"<<endl;
	    SetConsoleTextAttribute(hConsole1, (WORD)((0 << 0) | 7));
    }

void PC::setCpu(double CPU)
    {
	    if (CPU < 0)
		    cpu = abs(CPU);
	    else cpu = CPU;
    }

double PC::getCpu()
    {
	    return cpu;
    }