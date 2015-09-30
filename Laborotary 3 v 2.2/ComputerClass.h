#pragma once
#include "Product.h"
#include <algorithm>
using namespace std;
class ComputerClass
{
private:
    Product *begin;

    int itemCounter;
public:
    ComputerClass()
    {
        itemCounter = 0;
        begin = 0;
    }

    ~ComputerClass();
    void Insert(Product*);
    void Show(void);
    void Delete(Product*);
   
   inline int getItemCounter() 
    {
        return itemCounter;
    }

   int sumPrice()
   {
       int sum = 0;
       Product *r;
       r = begin;
       while (r)
       {
           sum += r->getPrice();
           r = r->next;
       }
       return sum;
   }

   void downWalk();
  
   int getSumOfEquipment();
   void showBadEquipment();

};

ComputerClass::~ComputerClass()
{
    Product *r;
    while (begin)
    {
        r = begin;
        begin = begin->next;
        delete r;
    }
}

void ComputerClass::Insert(Product *p)
{
    Product *r;
    r = begin;
    begin = p;
 
    itemCounter++;
    p->next = r;
}

void ComputerClass::Show(void)
{
    if (begin == NULL)
    {
        cout << "Выводить нечего список пуст" << endl;return;
    }
    else {
        cout << "количество элементов в списке: " << itemCounter << endl;
        Product *r;
        r = begin;
        while (r)
        {
            r->showInfo();
            r = r->next;
        }
    }
}

void ComputerClass::Delete(Product *p)

{
    if (begin == NULL)
    {
        cout << "Удалять нечего. Список пуст" << endl;
        return;
    }

    Product *t = begin;
    if (p == begin)
    {

        begin = t->next;
        cout << "Удален Объект типа " << typeid(t).name() << endl;
        cout << "информация об удаленном объекте: {" << endl;
        p->showInfo(); cout << "\n}\n\n";
        delete t;
        itemCounter--;

    }

    Product *t1 = t->next;
    while (t1)
    {
        if (t1 == p)
        {
            t->next = t1->next;
            cout << "Удален Объект типа " << typeid(*t).name() << endl;
            cout << "информация об удаленном объекте: {" << endl;
            p->showInfo(); cout << "\n}\n\n";
            delete t1;
            itemCounter--;
            return;
        }
        t = t1;
        t1 = t1->next;
    }


}




int ComputerClass::getSumOfEquipment()
{
    Product *temp;
    temp = begin;

    int sum = 0;

    while (temp)
    {
       sum+= temp->getPrice();
       temp = temp->next;
    }
    cout << "Сумма всего оборудования равна: "<<sum<<" бел/руб." << endl;
    return sum;
}

void ComputerClass::showBadEquipment()
{
    Product *temp;
    temp = begin;
    while (temp)
    {
        if (temp->getQuantityOfDays() >= 1500)
        {
            cout << "Необходимо списать: " << typeid(*temp).name() << endl;
            temp->showInfo();
        }
        temp = temp->next;
    }
}


void ComputerClass::downWalk()
{
    Product *r, *temp;
    int arrayOfPrice[50];
    int extraArray[50];
    r = begin;
    int tempPrise = -1;
    int tempIndex = 0;
    int i = 0;
    //create one more, extra ComputerClass
    ComputerClass *copy = this;
 
    
    while (r)
    {
        arrayOfPrice[tempIndex++] = r->getPrice();

        r = r->next;
    }

    for (int i = 0;i < itemCounter;i++)
    {
        cout << arrayOfPrice[i] << endl;
    }
    //ok, now we have array with prices of our objects
    for (int i(0);i < itemCounter;i++)
    {
        extraArray[i] = arrayOfPrice[i];
    }
    
    sort(arrayOfPrice, (arrayOfPrice + itemCounter));
    r = begin; //set to zero our pointer to begin list

    for (int i = 0;i < itemCounter;i++)
    {
        r = begin;
        while (r)
        {
            if (r->getPrice() == arrayOfPrice[itemCounter - i - 1])// try to equal elements of array and price of every object
            {
                r->showInfo();
                r->setPrice(1);
            }
            r = r->next;
        }
    }

    // now we must back values of prices
    tempIndex = 0;
    r = begin;
    while (r)
    {
        r->setPrice(extraArray[tempIndex++]);
        r = r->next;
    }
}