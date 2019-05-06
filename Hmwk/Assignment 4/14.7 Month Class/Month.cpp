#include "Month.h"
#include <iostream>

using namespace std; 

 string Month::getName(int n)
{
	const string nameList[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	return nameList[n - 1];
}

 int Month::getNum(string nam)
 {
	int i = 1;
	do {
		if (nam == getName(i)) {
			return i;
		}
		else
			i++; 
	} while (i <= 12);

	return NULL; 
 }

Month::Month()
{
	name = getName(1); 
	number = 1; 
}

Month::Month(string name)
{
	this->name = name;
	this->number = getNum(name);
}

Month::Month(int n)
{
	name = getName(n);
	number = n;
}


Month::~Month()
{
	cout << "Month destructor running..." << endl;
}

void Month::setMonth(string name)
{
	this->name = name; 
	this->number = getNum(name); 
}

void Month::setMonth(int n)
{
	number = n;
	name = getName(n);
}

int Month::getNum()
{
	return this->number; 
}

string Month::getName()
{
	return getName(number); 
}

Month Month::operator++()
{
	if (number == 12) {
		setMonth(1); 
	}
	else {
		setMonth(this->number + 1);
	}

	return Month();
}

Month Month::operator--()
{
	if (number == 1) {
		setMonth(12);
	}
	else {
		setMonth(this->number - 1);
	}

	return Month();
}

ostream& operator<<(ostream& strm, const Month& month)
{
	strm << month.name << endl;
	return strm; 
}

istream& operator>>(istream& strm, Month& month)
{
	cout << "Enter month number: ";
	strm >> month.number;
	month.setMonth(month.number);
	
	return strm; 
}
