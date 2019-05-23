// Simple Vector and Linked Lists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SimpleVector.h"

using namespace std;

int main()
{
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
}