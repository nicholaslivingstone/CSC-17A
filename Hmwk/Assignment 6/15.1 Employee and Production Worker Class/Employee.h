/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Employee.h
 * Author: Nicholas
 *
 * Created on May 23, 2019, 10:19 PM
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "date.h"


using namespace std; 

class Employee
{
private:
	string name;
	unsigned int number; 
	date hired; 
public:
	//constructors
	Employee(string name, unsigned int number, date hired) : name(name), number(number), hired(hired) {}	//paramtized constructor (name, number, date hired)
	Employee()	//default constructor
		{ name = ""; number = NULL; hired = date(); }

	//set functions
	void setName(string);
	void setNumber(unsigned int);
	void setHired(date); 
	
	//accessor functions
	string getName() 
		{ return this->name; }
	unsigned int getNumber()
		{ return this->number; }
	date getHired()
		{ return this->hired; }
};



#endif /* EMPLOYEE_H */
