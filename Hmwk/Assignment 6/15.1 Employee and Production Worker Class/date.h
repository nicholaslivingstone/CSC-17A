/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   date.h
 * Author: Nicholas
 *
 * Created on May 23, 2019, 10:11 PM
 */

#ifndef DATE_H
#define DATE_H
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

#endif /* DATE_H */
