#pragma once
#include "Product.h"
#include <algorithm>

class ComputerClassArray
{
    Product *array[50];
    int arraySize = 0;
public:

    void add(Product*p)
    {
        array[arraySize++] = p;
    }



    void Delete(Product*p)
    {
        for (int i = 0;i < arraySize;i++)
        {

            if (typeid(p).name() == typeid(array[i]).name())
            {
                for (int j = i;j < arraySize;j++)
                {
                    array[j] = array[j + 1];
                }
                arraySize--;
                return;
            }
        }
        cout << "Не удалено ничего";
    }


    void show()
    {
        for (int i = 0;i < arraySize;i++)
        {
            array[i]->showInfo();
        }
    }

    void badEqupment()
    {
        cout << "инфо об обородовании с большим сроком эксплуатиции {\n";
        for (int i = 0;i < arraySize;i++)
        {
            if (array[i]->getQuantityOfDays()>1000) array[i]->showInfo();
        }
        cout << "}\n";
    }


    int getSumOFPrices()
    {
        int sum = 0;
        for (int i = 0;i < arraySize;i++)
        {
            sum += array[i]->getPrice();
        }
        return sum;
    }


    void downWalk()
    {
        Product *extraArray[50];
        int arrayOfPrices[50];
        for (int i = 0;i < arraySize;i++)
        {
            extraArray[i] = array[i];
            arrayOfPrices[i] = extraArray[i]->getPrice();
        }
        sort(arrayOfPrices, arrayOfPrices + arraySize);

        for (int i = 0;i < arraySize;i++)
        {
            for (int j = 0;j < arraySize;j++)
            {
                if (extraArray[j]->getPrice() == arrayOfPrices[arraySize-i-1])
                {
                    extraArray[j]->showInfo();
                    extraArray[j]->setPrice(0);
                }
            }
        }

    }
};