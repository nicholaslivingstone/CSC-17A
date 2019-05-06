#ifndef MONTH_H
#define MONTH_H
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std; 

class Month{
private:
	string name; 
	int number; 
	string getName(int); 
	int getNum(string);
public:
	//constructors & destructors
	Month();					//default constructor
	Month(string);	//accepts month name
	Month(int);		//accepts month number
	~Month();

	//set & get functions
	void setMonth(string);
	void setMonth(int);
	int getNum();
	string getName();

	//overloaded operators
	Month operator ++ ();
	Month operator -- (); 
	friend ostream &operator << (ostream &, const Month &);
	friend istream &operator >> (istream &, Month &);
};
#endif

