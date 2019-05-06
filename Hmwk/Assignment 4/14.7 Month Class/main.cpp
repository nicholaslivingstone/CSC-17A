/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Nicholas
 *
 * Created on May 5, 2019, 10:17 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "Month.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Month testMonth = Month("March");
	cout << "Month name: " << testMonth.getName() << endl;
	cout << "Month number: " << testMonth.getNum() << endl;
	cout << "Default constructor: " << endl; 
	Month defaultMonth = Month();
	cout << "Month name: " << defaultMonth.getName() << endl;
	cout << "Month number: " << defaultMonth.getNum() << endl;
	cout << "Changing default construtor: " << endl;
	defaultMonth.setMonth(6);
	cout << "Month name: " << defaultMonth.getName() << endl;
	cout << "Month number: " << defaultMonth.getNum() << endl;
	cout << "Testing << and >> operators" << endl; 
	cin >> defaultMonth;
	cout << defaultMonth; 

    return 0;
}

