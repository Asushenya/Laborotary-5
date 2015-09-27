#pragma once
#include "Display.h"
#include "Product.h"
class Monitor:
	public Product,public Display
        {
        private:
            string monitorName;
        public:
            Monitor() {};
	        Monitor(string,float,int);

	        ~Monitor();

	        void showInfo();
	
            float getDiagonal();
            int getPpi();

            void setMonitoName(string name)
            {
                if (name.compare("empty") == 0)
                    monitorName = "empty";
                else monitorName = name;
            }
        };

