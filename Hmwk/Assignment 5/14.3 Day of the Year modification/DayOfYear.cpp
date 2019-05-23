#include "DayOfYear.h"
#include <stdexcept>
#include <iostream>
#include <cctype>

using namespace std;

const string DayOfYear::months[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
const int DayOfYear::dayCount[] = { 31, 28, 31, 30, 31, 30 , 31 , 31, 30 ,31 , 30, 31 };

void DayOfYear::getWords(int dayInput)	//determine month and day
{
	int n = 0, i = -1;

	//determine the month
	do {
		i++;
		n += dayCount[i];
	} while (n < dayInput);

	monthInt = i; 
	month = months[i];
	dayOfMonth = dayInput - n + dayCount[i];
}

DayOfYear::DayOfYear(int dayInput)	//constructor that takes a single day of the year integer
{
	if (dayInput > 365 || dayInput < 1)
		throw range_error("number too big");	//throw a range error if number inputted is not within the year
	day = dayInput;
	getWords(dayInput);
}

DayOfYear::DayOfYear(string monthInput, int dayInput)	//constructor takes name of string and day of month
{
	int i = -1; 
	
	monthInput[0] = toupper(monthInput[0]);	//make first character uppercase 

	//compare month inputted to list of months
	do {
		i++;
		if (i == 12) {
			throw range_error("Not a valid month");	//throw a range error if no month is found to match
		}
	} while (monthInput != months[i]);

	month = months[i];	//set month equal to matching month
	monthInt = i; 

	if (dayInput > dayCount[i])	//check if day is within days of month
		throw range_error("Not a valid day of " + month);

	dayOfMonth = dayInput;	

	//calculate day of the year /365
	day = 0; 
	for (int n = 0; n < i; n++) {
		day += dayCount[n];		//add days of each month to day of year
	}
	day += dayInput;	//add remaining day of current month
}

void DayOfYear::print()		//prints string of month + day
{
	cout << month << " " << dayOfMonth << endl; 
}

void DayOfYear::printDay()	//prints day of the year, integer; 
{
	cout << day << endl; 
}

DayOfYear DayOfYear::operator++()
{
	day++;
	if (day > 365)
		day = 1;
	getWords(day);
	return *this;
} 

DayOfYear DayOfYear::operator++(int)
{
	DayOfYear temp(day);
	day++; 
	if (day > 365)
		day = 1;
	getWords(day);
	
	return temp;
}

DayOfYear DayOfYear::operator--()
{
	--day;
	if (day < 1)
		day = 365;

	getWords(day);
	
	return *this;
}

DayOfYear DayOfYear::operator--(int)
{	
	DayOfYear temp(day);

	day--; 
	if (day < 1)
		day = 365;
	getWords(day);
	
	return temp; 
}
