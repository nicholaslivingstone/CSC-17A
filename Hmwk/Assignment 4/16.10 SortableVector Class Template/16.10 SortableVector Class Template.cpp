// 16.10 SortableVector Class Template.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SortableVector.h"

using namespace std; 

int main()
{
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
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
