// 16.3 Minimum-Maximum Templates.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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

int main()
{
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
}