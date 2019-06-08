/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Nicholas
 *
 * Created on June 7, 2019, 1:27 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

string convert(float,int);

int main(int argc, char** argv) {
    
    cout << "Binary" << endl; 
    cout << 3.75 << "  " << convert(3.75, 2) << endl;
    cout << 0.7 << "   " << convert(0.7, 2) << endl;
    cout << 89.9 << "  " << convert(89.9, 2) << endl;
    
    cout << "Octal" << endl; 
    cout << 3.75 << "  " << convert(3.75, 8) << endl;
    cout << 0.7 << "   " << convert(0.7, 8) << endl;
    cout << 89.9 << "  " << convert(89.9, 8) << endl;
    
    cout << "Hexadecimal" << endl; 
    cout << 3.75 << "  " << convert(3.75, 16) << endl;
    cout << 0.7 << "   " << convert(0.7, 16) << endl;
    cout << 89.9 << "  " << convert(89.9, 16) << endl;
    
    cout << "Float Point" << endl;
    printf("%a\n", 3.75);
    printf("%a\n", 0.7);
    printf("%a\n", 89.9);
    
    
    return 0;
}

string convert(float _num, int _base){
    char hex[] = {'0', '1', '2', '3', '4', '5', '6', '7' , '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    string bin = "";
    int intNum = _num; 
    float fract = _num - intNum; 
    while(intNum){
        if(_base == 16)
            bin = hex[(intNum % _base)] + bin;
        else
            bin += (intNum % _base) + '0';
        intNum /= _base;
    }
    
    if(fract != 0){
        bin += '.';
        while(fract){
            fract *= _base;
            int intPart = fract; 
            if(_base == 16)
                bin += hex[intPart];
            else
                bin += intPart + '0';
            fract -= intPart;
        }
    }
    
    return bin;
}