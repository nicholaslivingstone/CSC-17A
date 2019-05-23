/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DayOfYear.h
 * Author: Nicholas
 *
 * Created on May 12, 2019, 11:06 PM
 */

#ifndef DAYOFYEAR_H
#define DAYOFYEAR_H
#include <string>

using namespace std; 

class DayOfYear
{
	const static int dayCount[];
	const static string month[];
private:
	int day;
	string words; 
	string getWords(int); 
public:
	DayOfYear(int);
	void print(); 
};
#endif /* DAYOFYEAR_H */
