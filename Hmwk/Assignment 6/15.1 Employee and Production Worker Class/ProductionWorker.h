/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ProductionWorker.h
 * Author: Nicholas
 *
 * Created on May 23, 2019, 10:21 PM
 */

#ifndef PRODUCTIONWORKER_H
#define PRODUCTIONWORKER_H

#include "Employee.h"


class ProductionWorker : public Employee
{
private: 
	int shift;	//day shift 1. night shift 2
	double payRate; //hourly pay rate
public:
	ProductionWorker(int shift, double payRate, string name, unsigned int number, date hired) : shift(shift), payRate(payRate), Employee(name, number, hired){}
	int getShift()
		{ return this->shift; }
	double get()
		{ return this->payRate; }
	void setShift(int);
	void setPayRate(double);

	friend ostream& operator << (ostream& strm, ProductionWorker& obj) {
		strm << "Name: " << obj.getName() << "\nNumber: " << obj.getNumber() << "\nHired: " << obj.getHired() << "\nPay Rate: " << obj.payRate << "\nShift: ";
		if (obj.shift == 1)
			strm << "Day";
		else
			strm << "Night";

		return strm;
	}
	
};

#endif /* PRODUCTIONWORKER_H */
