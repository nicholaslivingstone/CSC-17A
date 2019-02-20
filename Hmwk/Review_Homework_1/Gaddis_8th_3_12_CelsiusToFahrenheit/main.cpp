/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: nick
 *
 * Created on February 20, 2019, 1:19 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    float C, F = 0;
    
    cout << "Enter a temp in Celsius: ";
    cin >> C; 
    
    F = ((9.0/5.0)*C) + 32;
    
    cout << "Fahrenheit: " << F;
    return 0;   
}

