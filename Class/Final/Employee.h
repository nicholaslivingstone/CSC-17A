/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Employee.h
 * Author: Nicholas
 *
 * Created on June 7, 2019, 10:29 PM
 */
#include <string>
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee {
    public:
        Employee(std::string,std::string,float);  //Constructor
        float  CalculatePay(float,int); //Procedure
        float  getGrossPay(float,int);  //Procedure
        float  getNetPay(float);        //Procedure
        void   toString();              //Procedure
        int    setHoursWorked(int);     //Procedure
        float  setHourlyRate(float);    //Procedure
    private:
        double Tax(float);      //Utility Procedure
        std::string MyName;    
        std::string   JobTitle;    
        float  HourlyRate;      
        int    HoursWorked;    
        float  GrossPay;        
        float  NetPay;          
};

#endif /* EMPLOYEE_H */

