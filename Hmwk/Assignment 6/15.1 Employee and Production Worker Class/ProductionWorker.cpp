/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ProductionWorker.cpp
 * Author: Nicholas
 * 
 * Created on May 23, 2019, 10:21 PM
 */

#include "ProductionWorker.h"
void ProductionWorker::setShift(int _shift)
{
	this->shift = _shift; 
}

void ProductionWorker::setPayRate(double _payRate)
{
	this->payRate = _payRate;
}
