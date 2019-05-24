/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Nicholas
 *
 * Created on May 23, 2019, 10:39 PM
 */

#include <cstdlib>
#include <iostream>
#include "SimpleVector.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int size; 
    cout << "Enter the size of the array:";
    cin >> size;
    SimpleVector<int> myVector(size); //declare vector
    for (int i = 0; i < size; i++) {
            myVector.addRand(i);
    }
    int choice; 
    do {
            myVector.print();
            cout << "1. Append a random number" << endl;
            cout << "2. Delete last number" << endl;
            cout << "3. Append a specific number" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter choice:";
            cin >> choice; 
            switch (choice) {
                    case 1: 
                            myVector.push(myVector.getRand());
                            break; 
                    case 2: 
                            myVector.pull(); 
                            break; 
                    case 3:
                            cout << "Enter a digit:";
                            int digit; 
                            cin >> digit; 
                            myVector.push(digit); 
                            break;
                    case 4: 
                            cout << "Exiting..."; 
                            exit(EXIT_SUCCESS);
                    default: 
                            cout << "Error: Invalid Input\n";
            }
    } while (true); 
    return 0;
}

