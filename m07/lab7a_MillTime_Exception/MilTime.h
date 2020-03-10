// Specification file for the MilTime class
#ifndef MILTIME_H
#define MILTIME_H
#include "Time.h"

// Declaration of the MilTime class

class MilTime : public Time
{
private:
	int milHours;
    int milSeconds;
public:
	MilTime(int, int);

    void convert();

	void setTime(int, int);

    int getHour() 
		{ return milHours; }

    int getStandHr() 
		{ return hour; }
};

MilTime::MilTime(int h = 0, int s = 0) : Time(0, 0, s)
{
	if (h < 0 || h > 2359)
	{
		std::cout << "Hours must be in the range 0 - 2359.\n";
		milHours = 0;
		milSeconds = 0;
	}
	else if (s < 0 || s > 59)
	{
		std::cout << "Seconds must be in the range 0 - 59.\n";
		milSeconds = 0;
	}
	else
	{
		milHours = h;
   	    milSeconds = s;
	}
	convert();
}

//***********************************************
// convert member function                      *
//***********************************************

void MilTime::convert()
{
	double temp;

	if (milHours > 1200)
		hour = milHours - 1200;
	else
		hour = milHours;
	
	hour /= 100;
	temp = (milHours - 1200) / 100.0;
	min = static_cast<int>(((temp - static_cast<int>(temp)) * 100));
}

//***********************************************
// setTime member function                      *
//***********************************************

void MilTime::setTime(int h, int s)
{
	milHours = h;
	milSeconds = s;
	convert();
}

#endif