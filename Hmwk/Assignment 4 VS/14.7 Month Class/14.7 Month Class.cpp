
#include <iostream>
#include <string>
#include "Month.h"

using namespace std; 

int main()
{
	Month testMonth = Month("March");
	cout << "Month name: " << testMonth.getName() << endl;
	cout << "Month number: " << testMonth.getNum() << endl;
	cout << "Default constructor: " << endl; 
	Month defaultMonth = Month();
	cout << "Month name: " << defaultMonth.getName() << endl;
	cout << "Month number: " << defaultMonth.getNum() << endl;
	cout << "Changing default construtor: " << endl;
	defaultMonth.setMonth(6);
	cout << "Month name: " << defaultMonth.getName() << endl;
	cout << "Month number: " << defaultMonth.getNum() << endl;
	cout << "Testing << and >> operators" << endl; 
	cin >> defaultMonth;
	cout << defaultMonth; 
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
