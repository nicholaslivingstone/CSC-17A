#include "MilTime.h"
#include <stdexcept>



void MilTime::isValid()
{
	if (this->milHours > 2359 || this->milHours < 0)
		throw range_error("Invalid Hour\n");
	if (this->milSeconds> 2359 || this->milSeconds < 0)
		throw range_error("Invalid Second\n");
}

MilTime::MilTime(int _hour, int _sec)
{
	this->setTime(_hour, _sec);
}

void MilTime::setTime(int _hour, int _sec)
{
	this->milHours = _hour;
	this->milSeconds = _sec;

	this->isValid();

	int h, m;
	h = this->milHours;
	if (this->milHours >= 1300) {
		h = this->milHours - 1300;
	}
	this->min = h - ((h / 100) * 100);
	h /= 100;
	this->hour = h; 
	this->sec = this->milSeconds;
}

int MilTime::getHour()
{
	return milHours;
}

int MilTime::getStandHour()
{
	return hour; 
}



