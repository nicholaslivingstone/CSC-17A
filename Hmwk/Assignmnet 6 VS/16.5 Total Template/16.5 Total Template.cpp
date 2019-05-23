// 16.5 Total Template.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std; 

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

int main()
{
	float count; 
	cout << "Enter count: ";
	cin >> count; 
	float tot = total(count);
	cout << "Total: " << tot; 
}