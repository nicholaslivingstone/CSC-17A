/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Employee.h
 * Author: Nicholas
 *
 * Created on June 7, 2019, 5:07 AM
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee {
    public:
        Employee(char[],char[],float);  //Constructor
        float  CalculatePay(float,int); //Procedure
        float  getGrossPay(float,int);  //Procedure
        float  getNetPay(float);        //Procedure
        void   toString();              //Procedure
        int    setHoursWorked(int);     //Procedure
        float  setHourlyRate(float);    //Procedure
    private:
        double Tax(float);      //Utility Procedure
        char   MyName[20];    
        char   JobTitle[20];    
        float  HourlyRate;      
        int    HoursWorked;    
        float  GrossPay;        
        float  NetPay;          
};

#endif /* EMPLOYEE_H */

