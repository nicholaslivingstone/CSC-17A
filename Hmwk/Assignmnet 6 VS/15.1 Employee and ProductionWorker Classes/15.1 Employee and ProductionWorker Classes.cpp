// 15.1 Employee and ProductionWorker Classes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Employee.h"
#include "ProductionWorker.h"



int main()
{
	int shift; 
	double payRate;
	string name; 
	unsigned int number; 
	date hired = date(); 

	std::cout << "Enter employee name:";
	getline(std::cin, name);
	std::cout << "Enter number:";
	std::cin >> number;
	std::cout << "Enter payRate:$";
	std::cin >> payRate;
	std::cout << "Enter shft(1 for day, 2 for night):";
	std::cin >> shift;
	bool error = false; 
	do {
		error = false; 
		try {
			std::cout << "Enter date hired:";
			std::cin >> hired;
		}
		catch (range_error e) {
			cout << e.what(); 
			error = true; 
		}
	} while (error);
	ProductionWorker myWorker(shift, payRate, name, number, hired);
	std::cout << myWorker;
}