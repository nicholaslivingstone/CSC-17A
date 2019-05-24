// Linked List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SimpleVector.h"

using namespace std;

int main()
{
	int size, choice; 
	cout << "Enter size of array:";
	cin >> size; 
	SimpleVector<int> myVector(size);
	do {
		cout << endl; 
		myVector.print();
		cout << "1. Add a random element to the end\n"; 
		cout << "2. Add a random element to the front\n";
		cout << "3. Remove an element from the front\n";
		cout << "4. Remove an element from the end\n";
		cout << "5. Exit program\n"; 
		cout << "Enter choice:";
		cin >> choice; 
		switch(choice){
		case 1: 
			myVector.addLast();
			break; 
		case 2:
			myVector.addFront(); 
			break; 
		case 3: 
			myVector.removeFront();
			break;
		case 4: 
			myVector.removeLast();
			break;
		case 5:
			cout << "Exiting..."; 
			exit(EXIT_SUCCESS);
		default: 
			cout << "Error invalid input"; 
		}
	} while (true);
}
