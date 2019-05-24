/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Nicholas
 *
 * Created on May 23, 2019, 10:24 PM
 */

#include <cstdlib>
#include <iostream>
#include "MilTime.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int hour, sec; 
	cout << "Enter military hour:";
	cin >> hour;
	cout << "Enter second:";
	cin >> sec; 
	MilTime timeDemo(hour, sec);
	cout << timeDemo.getHour() << endl;
	cout << timeDemo.getStandHour() << ':' << timeDemo.getMin();
    return 0;
}

