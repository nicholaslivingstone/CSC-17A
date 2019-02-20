/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: nick
 *
 * Created on February 20, 2019, 1:39 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;


int main(int argc, char** argv) {
    double DOLLAR, YEN_PER_DOLLAR, EUROS_PER_DOLLAR;
    
    cout << "Enter USD: ";
    cin >> DOLLAR;
    
    YEN_PER_DOLLAR = DOLLAR * 110.87;
    EUROS_PER_DOLLAR = DOLLAR * 0.88;
    
    cout << setprecision(2) << fixed; 
    cout << "Yen: " << YEN_PER_DOLLAR << endl;
    cout << "Euro: " << EUROS_PER_DOLLAR;
    
    
    
    return 0;
}

