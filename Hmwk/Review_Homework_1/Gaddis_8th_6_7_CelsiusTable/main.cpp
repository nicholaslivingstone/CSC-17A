/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: nick
 *
 * Created on February 21, 2019, 9:46 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

float convert(float);

int main(int argc, char** argv) {
    
    
    cout << "Fahrenheit | Celsius" << endl;
    cout << "--------------------" << endl;
    for(int i = 0; i <= 20; i++){
        cout << setprecision(4) << fixed << setfill(' ') << setw(2) << i << setw(18) << setfill('.') << convert(i) << endl;
    }
    
    return 0;
}

float convert(float F){
    return (5.0/9.0) * (F - 32);
}

