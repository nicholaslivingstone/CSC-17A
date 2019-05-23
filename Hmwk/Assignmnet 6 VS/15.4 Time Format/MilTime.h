#pragma once
#include "Time.h"

using namespace std;

class MilTime : Time
{
private:
	int milHours,
		milSeconds; 
	void isValid(); 
public:
	using Time::getMin;
	MilTime(int, int);
	void setTime(int, int); 
	
	int getHour();
	int getStandHour(); 
};

