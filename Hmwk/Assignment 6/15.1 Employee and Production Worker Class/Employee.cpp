/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Employee.cpp
 * Author: Nicholas
 * 
 * Created on May 23, 2019, 10:19 PM
 */

#include "Employee.h"

void Employee::setName(string _name)
{
	this->name = _name; 
}

void Employee::setNumber(unsigned int _number)
{	
	this->number = _number; 
}

void Employee::setHired(date _hired)
{
	this->hired = _hired;
}
