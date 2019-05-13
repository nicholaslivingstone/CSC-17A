/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Nicholas
 *
 * Created on May 5, 2019, 10:30 PM
 */

#include <cstdlib>
#include <iostream>
#include "SortableVector.h"


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    	SortableVector<int> myVector = SortableVector<int>(8);

	myVector.setElement(0, 27);
	myVector.setElement(1, 66);
	myVector.setElement(2,42);
	myVector.setElement(3,28);
	myVector.setElement(4,90);
	myVector.setElement(5,21);
	myVector.setElement(6,94);
	myVector.setElement(7,80);
	myVector.sort();


	for (int i = 0; i < 8; i++) {
		cout << myVector[i] << endl;
	}

    
    return 0;
}

