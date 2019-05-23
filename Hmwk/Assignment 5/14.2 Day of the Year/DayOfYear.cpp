#include "DayOfYear.h"
#include <stdexcept>
#include <iostream>

using namespace std; 

const string DayOfYear::month[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
const int DayOfYear::dayCount[] = {31, 28, 31, 30, 31, 30 , 31 , 31, 30 ,31 , 30, 31};

string DayOfYear::getWords(int dayInput)	//determine month and day
{
	int n = 0, i = -1;
	
	//determine the month
	do {
		i++; 
		n += dayCount[i];
	} while (n < dayInput); 

	return month[i] + " " + to_string(dayInput - n + dayCount[i]);
}

DayOfYear::DayOfYear(int dayInput)	//constructor that takes a single day of the year integer
{
	if (dayInput > 365 || dayInput < 1) {
		throw range_error("number too big");	//throw a range error if number inputted is not within the year
	}
	day = dayInput; 
	words = getWords(dayInput);
}

void DayOfYear::print()		//prints string of month + day
{
	cout << words; 
}
