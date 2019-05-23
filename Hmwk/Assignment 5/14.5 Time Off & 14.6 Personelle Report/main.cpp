/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Nicholas
 *
 * Created on May 12, 2019, 11:13 PM
 */

#include <cstdlib>
#include <string>
#include "TimeOff.h"
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    TimeOff myTime = TimeOff();
    unsigned int months, hours; 
    cout << "Enter number of months worked:";
    cin >> months;
    myTime.setMaxSickDays(NumDays(8 * months));
    myTime.setMaxVac(NumDays(12 * months));
    cout << "Max sick days: " << myTime.getMaxSickDays().getDays() << endl; 
    cout << "Max vacation days: " << myTime.getMaxVac().getDays() << endl;
    return 0;
}

