/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Nicholas
 *
 * Created on May 23, 2019, 10:33 PM
 */

#include <cstdlib>

using namespace std;
#include <iostream>

template <class T>
T total(T _count) {
	T total = 0, 
		n; 
	for (T i = 0; i < _count; i++) {
		cout << "Value " << i + 1 << ":";
		cin >> n;
		total += n; 
	}

	return total; 
}

int main(int argc, char** argv) {
    float count; 
    cout << "Enter count: ";
    cin >> count; 
    float tot = total(count);
    cout << "Total: " << tot; 
    return 0;
}

