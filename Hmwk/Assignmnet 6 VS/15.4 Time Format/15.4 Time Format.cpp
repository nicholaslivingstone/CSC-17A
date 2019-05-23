// 15.4 Time Format.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MilTime.h"

using namespace std; 

int main()
{
	int hour, sec; 
	cout << "Enter military hour:";
	cin >> hour;
	cout << "Enter second:";
	cin >> sec; 
	MilTime timeDemo(hour, sec);

	cout << timeDemo.getHour() << endl;
	cout << timeDemo.getStandHour() << ':' << timeDemo.getMin();
}