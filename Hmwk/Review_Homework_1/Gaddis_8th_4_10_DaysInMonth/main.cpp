/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: nick
 *
 * Created on February 20, 2019, 1:54 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    //variables
    int MONTH, YEAR, DAYS;
    bool LEAP = false; 
    
    //get month and year
    cout << "Enter a month (1-12): ";
    cin >> MONTH;
    cout << "Enter a year: ";
    cin >> YEAR; 
    
    //check if it's a leap year 
    if(YEAR % 100 == 0){
        if(YEAR % 400 == 0)
            LEAP = true; 
    }
    else if (YEAR % 4 == 0){
        LEAP = true; 
    }
    
    
    switch(MONTH){
        case 2:
            if(LEAP)
                DAYS = 29;
            else
                DAYS = 28;
            break; 
        case 4:
        case 6:
        case 9:
        case 11:
            DAYS = 30;
            break; 
        default: 
            DAYS = 31; 
    }
    
    cout << DAYS << " days";

    return 0;
}

