#pragma once
#include <iostream>
#include <stdexcept>

using namespace std; 

class date
{
public:
	int day,
		month,
		year;

	date()
		{ day = 1; month = 1; year = 1; }
	date(int, int, int);

	friend ostream & operator << (ostream& strm, const date& obj) {
		strm << obj.month << "/" << obj.day << "/" << obj.year;
		return strm;
	}

	friend istream& operator >> (istream&, date&); 

	void operator = (const date& right);

private:
	void isValid();
};

