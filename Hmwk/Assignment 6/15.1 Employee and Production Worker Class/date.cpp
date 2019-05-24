/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   date.cpp
 * Author: Nicholas
 * 
 * Created on May 23, 2019, 10:11 PM
 */

#include "date.h"

date::date(int _day, int _month, int _year)
{
	this->day = _day; 
	this->month = _month; 
	this->year = _year; 
}

void date::operator=(const date& right)
{
	this->day = right.day;
	this->month = right.month;
	this->year = right.year; 
}

void date::isValid() {
	int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month > 12 || month < 1)
		throw range_error("Invalid month");
	if (day > days[month - 1] || day < 1)
		throw range_error("Invalid day");
	if (year < 0)
		throw range_error("Invalid year");
}

istream& operator>>(istream& strm, date& obj)
{
	cout << "\nMonth:";
	strm >> obj.month;
	cout << "Day:"; 
	strm >> obj.day; 
	cout << "Year:";
	strm >> obj.year;
	obj.isValid();
	return strm; 
}
