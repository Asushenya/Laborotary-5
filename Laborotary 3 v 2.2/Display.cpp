#include "stdafx.h"
#include "Display.h"
#include <Windows.h>

HANDLE hConsole3 = GetStdHandle(STD_OUTPUT_HANDLE);

Display::Display( float Diagonal,int PPI)
	
    {
	    diagonal = Diagonal;
	    ppi = PPI;
    }


Display::~Display()
    {
    }

void Display::showInfo()
    {
	    SetConsoleTextAttribute(hConsole3, (WORD)((2 << 2) | 10));
	    cout << "       Дианональ: '" << diagonal << "'\n";
	    cout << "       ppi: " << ppi<<endl;
	    SetConsoleTextAttribute(hConsole3, (WORD)((0 << 0) | 7));
    }

void Display::setDiagonal(float Diag)
    {
	    if (Diag < 0)
		    diagonal = abs(Diag);
	    else diagonal = Diag;
    }

float Display::gerDiagonal()
    {
	    return diagonal;
    }