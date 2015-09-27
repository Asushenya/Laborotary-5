#pragma once
#include "Product.h"
class HeadPhone:
	public Product
{
private :
 

protected:
    string headPhonename;
	int upBorder;
	int downBorder;
public:
    HeadPhone() {};
	HeadPhone(string,int,int);
	~HeadPhone();

	void showInfo();

    int getUPBorder();
    int getDownBorder();
};

