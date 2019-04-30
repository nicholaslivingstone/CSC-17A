/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Nicholas
 *
 * Created on April 29, 2019, 5:00 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

struct EmployeeInfo{
    string name;
    double hrsWrkd,
        payRate,
        grossPay;
};

const vector<std::string> EnglishWords[3] = 
{
    {
        "zero", 
        "one", 
        "two", 
        "three", 
        "four", 
        "five", 
        "six", 
        "seven", 
        "eight", 
        "nine",
        "ten",
        "eleven",
        "twelve", 
        "thirteen", 
        "fourteen", 
        "fifteen", 
        "sixteen", 
        "seventeen", 
        "eighteen", 
        "nineteen" 
    },
    {
         "", 
         "", 
         "twenty",
         "thirty",
         "forty", 
         "fifty", 
         "sixty", 
         "seventy", 
         "eighty", 
         "ninety",
         "hundred"
    },
    {
        "", 
        " thousand", 
        " million", 
        " billion", 
        " trillion"
    },
};

void printPayCheck(EmployeeInfo);
void calcGrossPay(EmployeeInfo &);
string convertEnglish(size_t);
string toEnglish(size_t);
        
int main(int argc, char** argv) {
    
    EmployeeInfo *employee = nullptr; 
    int numEmployees;
    
    cout << "How many employees?:";
    cin >> numEmployees;
    employee = new EmployeeInfo[numEmployees];
    
    for(int i = 0; i < numEmployees; i++){
        //getName
        cin.ignore();
        cout << "Employee name:";
        getline(cin, employee[i].name);
        
        //get hours worked
        cout << "Hours worked:";
        cin >> employee[i].hrsWrkd;
        if(employee[i].hrsWrkd < 0){
            cout << "Error invalid number of hours entered, exiting program...";
            delete [] employee; 
            return 0;
        }
        
        //get Pay rate
        cout << "Pay Rate:$";
        cin >> employee[i].payRate;
        if(employee[i].payRate < 0){
            cout << "Error invalid pay rate entered, exiting program...";
            delete [] employee; 
            return 0;
        }
        
        //
        calcGrossPay(employee[i]);
        printPayCheck(employee[i]);
    }
    
    delete [] employee;
    
    
    return 0;
}

void calcGrossPay(EmployeeInfo &emp){
    emp.grossPay = 0; 
    double tempHrs = emp.hrsWrkd; 
    if(tempHrs > 50){
        emp.grossPay += ((tempHrs - 50) * emp.payRate * 3);
        tempHrs = 50; 
    }
    if(tempHrs > 40){
        emp.grossPay += ((tempHrs - 40) * emp.payRate * 2);
        tempHrs = 40; 
    }
    emp.grossPay +=(tempHrs * emp.payRate);
}

void printPayCheck(EmployeeInfo emp){
    cout << "Company\n";
    cout << "Address\n";
    cout << "Name: " << left << setw(20) << emp.name << "Amount: $" << setprecision(2) << fixed << emp.grossPay << endl;
    cout << "Amount: " << toEnglish(emp.grossPay) << " and " << toEnglish(fmod(emp.grossPay, 1L) * 100L) << " cents" << endl;
    cout << "Signature line: ___________________________\n\n";
}

string convertEnglish(size_t number){
    if (number == 0)
        return "";
    int hundreds = number / 100;
    number %= 100;   // just keep last two digits
    std::string words;

    if (hundreds) {
        words = EnglishWords[0][hundreds] 
            + " " + EnglishWords[1][10] 
            + (number ? " " : "");
    }
    if (number == 0) {
        return words;
    }
    if (number < 20) {
        return words + EnglishWords[0][number];
    }
    int tens = number / 10;
    int units = number % 10;
    if (tens) {
        words += EnglishWords[1][tens];
    }
    if (units) {
        words += (tens ? " " : "") + EnglishWords[0][units];
    }
    return words;
}

string toEnglish(size_t number){
    
    if (number == 0) 
    {
        return EnglishWords[0][number];
    }
    string words;
    for (int thousands = 0; number; ++thousands, number /= 1000)
    {
        int chunk = number % 1000;
        if (chunk) {
            words = convertEnglish(chunk) 
                + EnglishWords[2][thousands] 
                + (words.size() ? " " : "") 
                + words;
        }
    }
    return words;
}