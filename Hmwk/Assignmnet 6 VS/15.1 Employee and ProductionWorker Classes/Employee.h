#pragma once
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

