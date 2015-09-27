#pragma once
#include <string>
#include <iostream>
using namespace std;

class Product
    {
    protected:
        
        int price;
        int quantityOfDays;

    private:
        
	    protected:
		    string name;
    public:
     Product *next;
      explicit  Product() { price = 0; };
      explicit  Product(string);
      virtual ~Product() { /*cout << "Destructor:" << typeid(*this).name()<<endl;*/ };
	 virtual   void setName(string) ;
	  virtual  string getName() ;

      virtual void showInfo() = 0;
   
      void setPrice(int p)
      {
          if (sizeof(price) == sizeof(p))
              price = p;
          else cout << "ошибка изменения поля price";
      }

      int getPrice()
      {
          return price;
      }

      int getQuantityOfDays()
      {
          return quantityOfDays;
      }

      void setQuantityOfDays(int days)
      {
          quantityOfDays = days;
      }
      friend class List;

    };


