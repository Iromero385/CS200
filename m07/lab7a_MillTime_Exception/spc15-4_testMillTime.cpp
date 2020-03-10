// Chapter 15, Programming Challege 4: Time Format
#include <iostream>
#include "MilTime.h"
using namespace std;

int main()
{
   // Create a MilTime object for 1445 hours, 27 seconds.
   MilTime timeObj(1445, 27);

   // Display the hours, minutes, and seconds.
   cout << "The hour in military format is " 
	    << timeObj.getHour() << endl;
   cout << "The hour in standard format is " 
	    << timeObj.getStandHr() << endl;
   cout << "The minutes are " 
	    << timeObj.getMin() << endl;
   cout << "The seconds are " 
	    << timeObj.getSec() << endl;
   return 0;
}