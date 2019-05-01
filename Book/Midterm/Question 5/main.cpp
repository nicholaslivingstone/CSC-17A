/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Nicholas
 *
 * Created on April 30, 2019, 12:29 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    short SHORT = 7 * 6 * 5 * 4 * 3 * 2 * 1;
    unsigned short unSHORT = 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1;
    int INT = 12 * 11 * 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1;
    unsigned int unINT = 12 * 11 * 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1;
    long LONG = 12 * 11 * 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1;
    unsigned long unLONG = 12 * 11 * 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1;
    float FLOAT = 12 * 11 * 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1;
    double DOUBLE =  12 * 11 * 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1;
    long double longDOUBLE = 12 * 11 * 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1;
    
    
    
    cout << "Byte: 5! = 120" << endl;
    cout << "Short: 7! = " << SHORT << endl;
    cout << "Unsigned Short: 8! = " << unSHORT<< endl;
    cout << "Integer: 12! = " << INT << endl;
    cout << "Unsigned Integer: 12! = " << unINT << endl;
    cout << "Long: 12! = " << LONG << endl;
    cout << "Unsigned Long: 12! = " << unLONG << endl;
    cout << "Float: 12! = " << FLOAT << endl;
    cout << "Double: 12! = " << DOUBLE << endl;
    cout << "Long Double: 12! = " << longDOUBLE;
    
    return 0;
}

