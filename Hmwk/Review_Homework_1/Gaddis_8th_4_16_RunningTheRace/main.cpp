/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: nick
 *
 * Created on February 20, 2019, 2:25 PM
 */

#include <cstdlib>
#include <iostream>


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    string N1, N2, N3, first, second, third; 
    float T1, T2, T3, temp;
    
    cout << "Enter 3 runner names and time" << endl;
    cout << "Name: ";
    cin >> N1;
    cout << "Time: ";
    cin >> T1;
    cout << "Name: ";
    cin >> N2;
    cout << "Time: ";
    cin >> T2;
    cout << "Name: "; 
    cin >> N3;
    cout << "Time: ";
    cin >> T3;
    
    if (T1 > T2){
        if (T3 > T2){
            first = N2;
            second = N3;
            third = N1; 
        }
        else{
            first = N3;
            second = N2;
            third = N1; 
        }
    }
    else{
        if (T3 > T1){
            first = N1;
            second = N3;
            third = N2; 
        }
        else{
            first = N3;
            second = N1;
            third = N2; 
        }
        
    }
    
    cout << endl; 
    cout << "First: " << first << endl;
    cout << "Second: " << second << endl;
    cout << "Third: " << third << endl;
    
    return 0;
}

