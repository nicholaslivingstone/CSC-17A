/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Numbers.h
 * Author: Nicholas
 *
 * Created on May 12, 2019, 11:05 PM
 */

#ifndef NUMBERS_H
#define NUMBERS_H
#include <string>

using namespace std;

class Numbers
{
private:
	int number;			//integer number
	string english;                 //English equivalent
	string toEnglish(int n);	//converts number to English
public:
	Numbers(int);		//constructor that takes integer number
	void print();
	void setNumber(int);
};


#endif /* NUMBERS_H */
