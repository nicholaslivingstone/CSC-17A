#include "TimeOff.h"
#include <iostream>
using namespace std; 


TimeOff::TimeOff()
{
}

void TimeOff::setMaxSickDays(NumDays days)
{
	this->maxSickDays = days; 
}


void TimeOff::setSickTaken(NumDays days)
{
	this->sickTaken = days; 
}

void TimeOff::setMaxVac(NumDays days)	//240 max
{
	if (days.getHours() > 240) {
		this->maxVacation = NumDays(240);
		cout << "Max vacation cannot exceed 240 hours\n";
	}
	this->maxVacation = days; 
}

void TimeOff::setVacTaken(NumDays days)
{
	this->vacTaken = days; 
}

void TimeOff::setMaxUnpaid(NumDays days)
{
	this->maxUnpaid = days; 
}

void TimeOff::setUnpaidTaken(NumDays days)
{
	this->unpaidTaken = days;
}

NumDays TimeOff::getMaxSickDays()
{
	return this->maxSickDays;
}

NumDays TimeOff::getsickTaken()
{
	return this->sickTaken;
}

NumDays TimeOff::getMaxVac()
{
	return this->maxVacation;
}

NumDays TimeOff::getVacTaken()
{
	return this->vacTaken;
}

NumDays TimeOff::getMaxUnpaid()
{
	return this->maxUnpaid;
}

NumDays TimeOff::getUnPaidTaken()
{
	return this->unpaidTaken;
}

string TimeOff::getName()
{
	return this->name;
}

unsigned int TimeOff::getID()
{
	return this->ID;
}
