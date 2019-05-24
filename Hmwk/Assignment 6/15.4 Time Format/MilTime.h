/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MilTime.h
 * Author: Nicholas
 *
 * Created on May 23, 2019, 10:25 PM
 */

#ifndef MILTIME_H
#define MILTIME_H

#include "Time.h"

using namespace std;

class MilTime : Time
{
private:
	int milHours,
		milSeconds; 
	void isValid(); 
public:
	using Time::getMin;
	MilTime(int, int);
	void setTime(int, int); 
	
	int getHour();
	int getStandHour(); 
};



#endif /* MILTIME_H */
