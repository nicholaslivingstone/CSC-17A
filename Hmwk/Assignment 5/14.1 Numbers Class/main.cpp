/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Nicholas
 *
 * Created on May 12, 2019, 11:03 PM
 */

#include <cstdlib>
#include <iostream>
#include "Numbers.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int input; 
	cout << "Type in a number 0-9999 to see the english equivalent: ";
	bool error; 
	do {
		error = false; 
		cin >> input;
		if (input > 9999) {
			cout << "Error number too large" << endl; 
			cout << "Type in a number 0-9999 to see the english equivalent: ";
			error = true; 
		}
	} while (error);
	Numbers number(input);
	number.print();
    return 0;
}

