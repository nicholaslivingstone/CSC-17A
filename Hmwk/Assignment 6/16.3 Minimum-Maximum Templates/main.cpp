/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Nicholas
 *
 * Created on May 23, 2019, 10:32 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

template <class T>
T minimum(T x, T y) {
	if (x < y) 
		return x;
	else
		return y; 
}

template <class T>
T maximum(T x, T y) {
	if (x > y)
		return x;
	else
		return y;
}

/*
 * 
 */
int main(int argc, char** argv) {
    double x, y; 
    cout << "Enter two numbers to find the minumum\n";
    cout << "First Number: "; 
    cin >> x; 
    cout << "Second Number: ";
    cin >> y; 
    cout << "Minimum: " << minimum(x, y);
    cout << "\nEnter two numbers to find the maximum\n";
    cout << "First Number: ";
    cin >> x;
    cout << "Second Number: ";
    cin >> y;
    cout << "Maximum: " << maximum(x, y);
    return 0;
}

