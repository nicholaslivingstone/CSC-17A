/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DayOfYear.h
 * Author: Nicholas
 *
 * Created on May 12, 2019, 11:09 PM
 */

#ifndef DAYOFYEAR_H
#define DAYOFYEAR_H
#include <string>

using namespace std;

class DayOfYear
{
	//static variables to help with conversion
	const static int dayCount[];
	const static string months[];
private:
	int day,
		dayOfMonth,
		monthInt; 
	string month;
	void getWords(int);	//sets day and month from an integer day of the year
public:
	//consructors
	DayOfYear(int);
	DayOfYear(string, int); 

	//member functions
	void print();
	void printDay(); 

	//overloaded operators
	DayOfYear operator ++ ();	//postifx
	DayOfYear operator ++ (int);//prefix
	DayOfYear operator -- ();	
	DayOfYear operator -- (int);
};
#endif /* DAYOFYEAR_H */
