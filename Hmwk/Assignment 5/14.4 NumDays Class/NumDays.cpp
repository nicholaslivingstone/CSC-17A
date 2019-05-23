#include "NumDays.h"

using namespace std; 

float NumDays::toDays(int hrs)	//converts work hours to days
{
	return (float)hrs / 8.0f;
}

NumDays::NumDays(int hrs)	//constructor takes a specified number of integer hours
{
	this->hours = hrs;
	this->days = toDays(hrs);
}

NumDays NumDays::operator+(const NumDays& right)
{
	NumDays temp = NumDays(hours + right.hours);
	return temp; 
}


NumDays NumDays::operator-(const NumDays& right)
{
	NumDays temp = NumDays(hours - right.hours);
	return temp;
}

NumDays NumDays::operator++()	//prefix ++
{
	++this->hours; 
	this->days = toDays(this->hours);
	return *this;
}

NumDays NumDays::operator++(int)	//postfix ++
{
	NumDays temp(this->hours); 

	this->hours++;
	this->days = toDays(this->hours);

	return temp; 
}

NumDays NumDays::operator--()	//prefix --
{
	--this->hours;
	this->days = toDays(this->hours);
	return *this;
}

NumDays NumDays::operator--(int)	//postfix --
{
	NumDays temp(this->hours);

	this->hours--;
	this->days = toDays(this->hours);

	return temp;
}


