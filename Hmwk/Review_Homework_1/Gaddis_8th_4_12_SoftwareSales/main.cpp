/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: nick
 *
 * Created on February 20, 2019, 2:12 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    float UNITS, DISCOUNT; 
    bool error; 
    
    //input and validate number of units sold
    do{
        error = false; 
        cout << "Number of Units Sold: ";
        cin >> UNITS;
        if (UNITS <= 0){
            cout << "ERROR: Invalid number of units" << endl;
            error = true; 
        }
    }while(error);
    
    //determine discount
    if (UNITS >= 100)
        DISCOUNT = .5; 
    else if (UNITS >= 50)
        DISCOUNT = .4; 
    else if (UNITS >= 20)
        DISCOUNT = .3; 
    else if (UNITS >= 10)
        DISCOUNT = .2; 
    else
        DISCOUNT = 0;
        
    cout << setprecision(2) << fixed; 
    cout << "Total cost: $" << UNITS * 99.0 * DISCOUNT; 
        
    return 0;
}

