/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Nicholas
 *
 * Created on May 12, 2019, 11:06 PM
 */

#include <cstdlib>
#include <iostream>
#include "DayOfYear.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int day; 
	bool error; 
	do {
		error = false; 
		try {
			cout << "Enter day of the year (1 - 365):";
			cin >> day; 
			DayOfYear myDay(day);
			myDay.print();
		}
		catch (range_error e) {
			cout << "Error caught: " << e.what() << endl; 
			error = true; 
		}
	} while (error);
    return 0;
}

