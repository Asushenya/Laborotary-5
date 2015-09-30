// Laborotary 5 cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Product.h"
#include "PC.h"
#include "WorkStation.h"
#include "Display.h"
#include "Monitor.h"
#include "HeadPhone.h"
#include "Mouse.h"
#include "List.h"
#include "NewWorkStation.h"
#include "ComputerClass.h"
#include <vector>

int main()
{
	setlocale(0, "");
  
    PC *pc1;
    pc1 = new PC("intel", 2.4);
   //    pc1.showInfo();
    Mouse *mouse1;
    mouse1 = new Mouse ("Razer", 450, 6);
     //  mouse1.showInfo();
    Monitor *monitor1;
    monitor1 = new Monitor("LG", 24.5, 456);
     //  monitor1.showInfo();
    HeadPhone *headphone1;
    headphone1 = new HeadPhone("Sony", 20, 20000);
     //  headphone1.showInfo();

    NewWorkStation *WS1;
    WS1 = new NewWorkStation ("Apple", *pc1, *monitor1, *mouse1, *headphone1);
  
     // WS1.showInfo();

       ComputerClass obj1;
       obj1.Insert(pc1);
      
       obj1.Insert(mouse1);
       obj1.Insert(headphone1);
       obj1.Insert(WS1);
       WS1->setPrice(2000);
       obj1.downWalkMod();
       cout << "////////////////////////\n";
       obj1.Show();
    return 0;
}

