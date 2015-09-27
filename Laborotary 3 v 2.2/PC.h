#pragma once
#include "Product.h"
class PC:
	public Product
    {
    protected:
        string proccesorName;
	    double cpu;
    public:
        PC() {};
	    PC(string,double );
	    ~PC();

	    void showInfo();

	    void setCpu(double);
	    double getCpu();

      

 


    };

