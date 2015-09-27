#pragma once
#include "Product.h"
class Mouse:
	public Product
{
protected :
    string mouseName;
	unsigned int dpi;
	unsigned int buttonCounter;
public:
    Mouse() {};
	Mouse(string,int,int);
	~Mouse();

	void showInfo();

    int getDpi();
    int getCounter();
};

