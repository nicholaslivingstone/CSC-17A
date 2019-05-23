/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NumDays.h
 * Author: Nicholas
 *
 * Created on May 12, 2019, 11:12 PM
 */

#ifndef NUMDAYS_H
#define NUMDAYS_H

using namespace std; 

class NumDays
{
private:
	int hours; 
	float days; 
	float toDays(int); 
public:
	//constructors
	NumDays(int);

	//Accessor Functions
	float getDays() const
		{return days;}
	int getHours() const
		{return hours;}

	//overloaded operators
	NumDays operator + (const NumDays &); 
	NumDays operator - (const NumDays &);
	NumDays operator ++ ();
	NumDays operator ++ (int);
	NumDays operator -- ();
	NumDays operator -- (int);
};


#endif /* NUMDAYS_H */
