/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: nick
 *
 * Created on February 21, 2019, 8:51 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int DAYS;
    float RATE, POP = 0;
    bool ERROR = false; 
    
    cout << "CALCULATE POPULATION GROWTH" << endl; 
    
    do{
        ERROR = false; 
        cout << "Initial population:";
        cin >> POP;
        if (POP < 2){
            cout << "ERROR: POPULATION MUST BE GREATER THAN 2" << endl;
            ERROR = true; 
        }
    }while(ERROR);
    
    
    do{
        ERROR = false; 
        cout << "Growth rate(%):";
        cin >> RATE; 
        if (RATE < 0){
            cout << "ERROR: GROWTH RATE MUST BE POSITIVE" << endl;
            ERROR = true; 
        }
    }while(ERROR);
    
    
    do{
        ERROR = false; 
        cout << "Number of Days:";
        cin >> DAYS;
        if (DAYS < 1){
            cout << "ERROR: DAYS MUST BE GREATER THAN 1" << endl;
            ERROR = true; 
        }
    }while(ERROR);
    
    
    for(int i = 1; i <= DAYS;i++)
    {
        POP += POP * RATE;
        cout << "Day " << i << ":...." << POP << endl; 
    }
    
    return 0;
}

