/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TimeOff.h
 * Author: Nicholas
 *
 * Created on May 12, 2019, 11:14 PM
 */

#ifndef TIMEOFF_H
#define TIMEOFF_H
#include "NumDays.h"
#include <string>

using namespace std; 

class TimeOff
{
private: 
	NumDays maxSickDays,	//maximum number of days of sick leave the employee may take.
		sickTaken,			//number of days of sick leave the employee has already taken.
		maxVacation,		//maximum number of days of paid vacation the employee may take.
		vacTaken,			//number of days of paid vacation the employee has already taken.
		maxUnpaid,			//maximum number of days of unpaid vacation the employee may take.
		unpaidTaken;		//number of days of unpaid leave the employee has taken.
	string name;			//employee name
	unsigned int ID;		//employee ID number
public:
	TimeOff();

	//setters
	void setMaxSickDays(NumDays);
	void setSickTaken(NumDays); 
	void setMaxVac(NumDays);
	void setVacTaken(NumDays);
	void setMaxUnpaid(NumDays);
	void setUnpaidTaken(NumDays);

	//accessors
	NumDays getMaxSickDays();
	NumDays getsickTaken(); 
	NumDays getMaxVac();
	NumDays getVacTaken();
	NumDays getMaxUnpaid();
	NumDays getUnPaidTaken();
	string getName();
	unsigned int getID();


};


#endif /* TIMEOFF_H */
