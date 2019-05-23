// 15.6 Essay Class.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Essay.h"

using namespace std; 

int main()
{
	int gram, spell, len, cont; 
	cout << "Grammar:";
	cin >> gram; 
	cout << "Spelling:";
	cin >> spell; 
	cout << "Length:"; 
	cin >> len; 
	cout << "Content:";
	cin >> cont; 
	Essay essayDemo(gram, spell, len, cont);
	cout << "Letter Grade: " << essayDemo.getLetterGrade(); 
}