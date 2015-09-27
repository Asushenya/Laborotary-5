#pragma once
#include "PC.h"
#include "Product.h"
#include "Monitor.h"
#include "HeadPhone.h"
#include "Mouse.h"

class NewWorkStation :
    public Product
{
private:
    string newWorkStationName;
private:
    PC newPC;
    Monitor newMonitor;
    Mouse newMouse;
    HeadPhone newHeadPhone;
public:
    NewWorkStation(string name, PC pc, Monitor monitor, Mouse mouse, HeadPhone hp)//,HeadPhone hp)
    {
        quantityOfDays = 7850;
        newWorkStationName = name;
        newPC = pc;
        newMonitor = monitor;
        newMouse = mouse;
        newHeadPhone = hp;
        price = pc.getPrice() + monitor.getPrice() + mouse.getPrice() + hp.getPrice();;
    }

    NewWorkStation(NewWorkStation &copy)
    {
        this->newWorkStationName = copy.newWorkStationName;
        this->newPC = copy.newPC;
        this->newMonitor = copy.newMonitor;
        this->newMouse = copy.newMouse;
        this->newHeadPhone = copy.newHeadPhone;
    }

    void showInfo()
    {
        cout << "Наименование рабочей станции:" << newWorkStationName << endl;
        cout << "{{" << endl;
        newPC.showInfo();
        newMonitor.showInfo();
        newMouse.showInfo();
        newHeadPhone.showInfo();
        cout << "Количество дней в работе " << quantityOfDays << endl;
        cout << "Цена рабочей станции: " << price << endl;
        cout << "}}" << endl;
    }

    void setPrice(int p)
    {
        price = p;
    }
};

