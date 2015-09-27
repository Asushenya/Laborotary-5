#include "stdafx.h"
#include "WorkStation.h"
#include <Windows.h>

HANDLE hConsole2 = GetStdHandle(STD_OUTPUT_HANDLE);





WorkStation::WorkStation(string Name1,							//Product
						string Name2 , double CPU,				//PC
						string Name3, float Diagonal,int PPI,   //Monitor
						string Name4, int up, int down,			//HeadPhone
						string Name5, int Dpi, int Counter,		//Mouse
						int counter):							//WorkStation
			Product(/*Name1*/
                
                ), PC(Name2,CPU), Monitor(Name3,Diagonal,PPI),HeadPhone(Name4,down,up),Mouse(Name5,Dpi,Counter)
{
    workStationName = Name1;
	itemCounter  = counter;
}

WorkStation::WorkStation(/*Product obj1*/string Name, PC obj2, Monitor obj3, HeadPhone obj4, Mouse obj5 ,int counter): //конструктор
  //  Product::Product(obj1.getName()),                                                                           //для 
    PC::PC(obj2.getName(), obj2.getCpu()),                                                                  //объектов
    Monitor::Monitor(obj3.getName(), obj3.getDiagonal(), obj3.getPpi()), 
    HeadPhone::HeadPhone(obj4.getName(), obj4.getDownBorder(), obj4.getUPBorder()), 
    Mouse::Mouse(obj5.getName(), obj5.getDpi(), obj5.getCounter())
       
{
    workStationName = Name;
    itemCounter = counter;
}



WorkStation::WorkStation(const WorkStation& A) 

{
   
    WorkStation::Product::name = A.WorkStation::Product::name;

    WorkStation::PC::name = A.WorkStation::PC::name;
    WorkStation::PC::cpu = A.cpu;

    WorkStation::Monitor::name = A.WorkStation::Monitor::name;
    WorkStation::Monitor::Display::diagonal = A.diagonal;
    WorkStation::Monitor::Display::ppi = A.ppi;

    WorkStation::HeadPhone::name = A.WorkStation::HeadPhone::name;
    WorkStation::HeadPhone::downBorder = A.downBorder;
    WorkStation::HeadPhone::upBorder = A.upBorder;

    WorkStation::Mouse::name = A.WorkStation::Mouse::name;
    WorkStation::Mouse::dpi = A.dpi;
    WorkStation::Mouse::buttonCounter = A.buttonCounter;

    WorkStation::itemCounter = A.itemCounter;



}

WorkStation::~WorkStation()
{
}

void WorkStation::showInfo()
{
	cout << "----====| | | | | | | |====----" << endl;
	SetConsoleTextAttribute(hConsole2, (WORD)((2 << 4) | 11));
	cout << "Информация о WS: " << endl;
    SetConsoleTextAttribute(hConsole2, (WORD)((2 << 2) | 20));
    cout << "Производитель Рабочей Станции: " << workStationName << endl;
	SetConsoleTextAttribute(hConsole2, (WORD)((0 << 0) | 7));
	
	PC::showInfo();
	Monitor::showInfo();
	HeadPhone::showInfo();
	Mouse::showInfo();
	SetConsoleTextAttribute(hConsole2, (WORD)((2 << 2) | 6));
	cout << "Количество элементов WS: " << itemCounter << endl;
    //cout << "Цена рабоцей станции:" << price << endl;
	SetConsoleTextAttribute(hConsole2, (WORD)((0 << 0) | 7));
	cout << "----====| | | | | | | |====----" << endl;

	
}

void WorkStation::setName(string Name)
{
	Product::setName(Name);
}

void WorkStation::CAN_I_START_GTAV()
{
    PC::cpu > 3.5 ? cout << "Yes you CAN..." : cout << "not you CAN't";
}