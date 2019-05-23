#include "Numbers.h"
#include <string>
#include <iostream>

using namespace std;

string ones[20] = {
		"",
		"one",
		"two",
		"three",
		"four",
		"five",
		"six",
		"seven",
		"eight",
		"nine",
		"ten",
		"eleven",
		"twelve",
		"thirteen",
		"fourteen",
		"fifteen",
		"sixteen",
		"seventeen",
		"eighteen",
		"nineteen"
};

string tens[10] = {
	"",
	"",
	"twenty",
	"thirty",
	"forty",
	"fifty",
	"sixty",
	"seventy",
	"eighty",
	"ninety"
};

Numbers::Numbers(int input)	//constructor takes on integer
{
	number = input;			//store Integer
	english = toEnglish(number);	//set english equivalent
}

void Numbers::print()
{
	cout << english; 
}

void Numbers::setNumber(int input)	//sets number and updates english
{
	number = input;			//store Integer
	english = toEnglish(number);
}

string Numbers::toEnglish(int n)	//prints words of numbers
{
	string words = "";; 

	if (n == 0) {
		words = "zero";
	}
	else {
		if (n >= 1000) {
			words += ones[n / 1000] + " thousand ";
			n -= (n/1000) * 1000;
		}
		if (n >= 100) {
			words += ones[n / 100] + " hundred ";
			n -= (n / 100) * 100;
		}
		if (n < 20) {
			words += ones[n];
		}
		else {
			words += tens[n / 10];
			n -= (n / 10) * 10; 
			words += " " + ones[n];
		}
	}

	return words;
}


