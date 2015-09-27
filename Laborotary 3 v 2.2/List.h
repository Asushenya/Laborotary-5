#pragma once

#include "Product.h"

using namespace std;

 class List
{
public:
    List()
    {
        begin = 0;
    }

    ~List();
    void Insert(Product*);
    void Show(void);
    void Delete(Product*);

private:
    Product *begin;



};

List::~List()
{
    Product *r;
    while (begin)
    {
        r = begin;
        begin = begin->next;
        delete r;
    }
}

void List::Insert(Product *p)
{
    Product *r;
    r = begin;
    begin = p;
    p->next = r;
   
}

void List::Show(void)
{
    if (begin == NULL)
    {
        cout << "Выводить нечего список пуст" << endl;return;
    }
    Product *r;
    r = begin;
    while (r)
    {
        r->showInfo();
        r = r->next;
    }
}

void List::Delete(Product *p)

{
    if (begin == NULL)
    {
        cout << "Удалять нечего. Список пуст"<<endl;
        return;
    }

    Product *t = begin;
    if (p == begin)
    {
        begin = t->next;
         cout << "Удален Объект типа "<<typeid(t).name()<<endl;
         cout << "информация об удаленном объекте: {" << endl;
         p->showInfo(); cout << "\n}\n\n";
        delete t;
        
        return;
    }

    Product *t1 = t->next;
    while (t1)
    {
        if (t1 == p)
        {
            t->next = t1->next;
            cout << "Удален Объект типа " << typeid(*t).name()<<endl;
            cout << "информация об удаленном объекте: {" << endl;
            p->showInfo(); cout << "\n}\n\n";
            
            delete t1;
            return;
        }
            t = t1;
            t1 = t1->next;
    }
 
   
}