/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Nicholas
 *
 * Created on May 12, 2019, 11:09 PM
 */

#include <cstdlib>
#include <iostream>
#include "DayOfYear.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    string month; 
	int day, input; 
	bool error; 
	do {
		error = false; 
		try {
			cout << "Enter month name:";
			cin >> month; 
			cout << "Enter day of month:"; 
			cin >> day;
			DayOfYear myDay(month, day);
			do {
				cout << "-----------" << endl;
				cout << "1. day++\n2. day--\n3. ++day\n4. --day\n";
				cin >> input;
				switch (input) {
				case 1: myDay++; myDay.print(); break;
				case 2: myDay--; myDay.print(); break;
				case 3: ++myDay; myDay.print(); break;
				case 4: --myDay; myDay.print(); break;
				}
			} while (true);
		}
		catch (range_error e) {
			cout << "Error caught: " << e.what() << endl; 
			error = true; 
		}
	} while (error);
    return 0;
}

