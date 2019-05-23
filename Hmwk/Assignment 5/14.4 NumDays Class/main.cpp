/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Nicholas
 *
 * Created on May 12, 2019, 11:12 PM
 */

#include <cstdlib>
#include <iostream>
#include "NumDays.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int hours; 
	cout << "Enter number of hours:"; 
	cin >> hours; 
	NumDays myDays(hours);
	cout << "Current days: " << myDays.getDays() << endl;
	cout << "Incrementing..." << endl; 
	myDays++; 
	cout << "Current days: " << myDays.getDays() << endl;
	cout << "Decrementing..." << endl; 
	myDays--; 
	cout << "Current days: " << myDays.getDays() << endl;
	NumDays temp(12); 
	cout << "Adding 12 hours..." << endl; 
	NumDays added(0); 
	added = temp + myDays;
	cout << "Combined time: " << added.getDays() << endl; 
	cout << "Subtracting 12 hours..." << endl;
	NumDays subtracted(0);
	subtracted = myDays - temp; 
	cout << "Combined time: " <<  subtracted.getDays() << endl;
    return 0;
}

