/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Nicholas
 *
 * Created on May 23, 2019, 10:10 PM
 */

#include <cstdlib>
#include <iostream>
#include "Employee.h"
#include "ProductionWorker.h"

/*
 * 
 */
int main(int argc, char** argv) {

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
        
        return 0; 
}