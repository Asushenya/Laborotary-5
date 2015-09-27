#pragma once
#include "Product.h"
class Display

    {
    protected:
	    float diagonal;
	    unsigned int ppi;
    public:
        Display() {};
	    Display(float,int);
	    ~Display();

	    void setDiagonal(float);
	    float gerDiagonal();
	    void showInfo();
    };

