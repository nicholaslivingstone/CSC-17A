/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Employee.cpp
 * Author: Nicholas
 * 
 * Created on June 7, 2019, 10:29 PM
 */

#include <cstring>
#include <iostream>
#include "Employee.h"

Employee::Employee(std::string _name, std::string _title, float _pay) {
    MyName = _name; 
    JobTitle =_title;
    setHourlyRate(_pay); 
    this->HoursWorked = 0; 
    this->GrossPay = 0;
    this->NetPay = 0;
}


int Employee::setHoursWorked(int HoursWorked) {\
    if(HoursWorked > 84 || HoursWorked < 0){
        std::cout << "Error invalid number of hours" << std::endl;
        this->HoursWorked = 0;
        return 0; 
    }
    this->HoursWorked = HoursWorked;
    return HoursWorked;
}



float Employee::setHourlyRate(float HourlyRate) {
    if(HourlyRate > 200 || HourlyRate < 0){
        std::cout << "Error invalid pay" << std::endl;
        return 0; 
    }
    this->HourlyRate = HourlyRate;
    return HourlyRate; 
}


double Employee::Tax(float _gp){
    if(_gp <= 500)
        return 0.1;
    else if(_gp <= 1000 && _gp > 500)
        return 0.2;
    else
        return 0.3;
}

void Employee::toString(){
    std::cout << "Name = " << this->MyName << " Job Title + " << this->JobTitle <<std::endl;
    std::cout << " Hourly Rate = " << this->HourlyRate << " Hours Worked = " << this->HoursWorked << " Gross Pay = "
            << this->GrossPay << " Net Pay = " << this->NetPay << std::endl;
}

float Employee::getGrossPay(float _rate,int _hours){
    int hours = _hours;
    float pay = 0;
    if(hours > 50){
        pay += (hours - 50) * 2 * _rate; 
        hours -= (hours - 50);
    }
    if(hours > 40){
        pay += (hours - 40) * 1.5 * _rate; 
        hours -= (hours - 40);
    }
    pay += hours * _rate; 
    this->GrossPay = pay; 
    return GrossPay; 
}

float Employee::getNetPay(float _gp){
    this->NetPay = _gp - _gp * Tax(_gp);
}

float Employee::CalculatePay(float _rate,int _hours){
    return getNetPay(getGrossPay(setHourlyRate(_rate),setHoursWorked(_hours)));
}
