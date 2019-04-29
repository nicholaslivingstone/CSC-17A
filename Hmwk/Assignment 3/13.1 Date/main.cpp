/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Nicholas
 *
 * Created on April 28, 2019, 8:41 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

class Date{
private:
    int month, 
            day,
            year;
    string monthWord(int m){
        switch(m){
            case 1:
                return "January";
            case 2:
                return "February";
            case 3:
                return "March";
            case 4: 
                return "April";
            case 5:
                return "May";
            case 6:
                return "June";
            case 7:
                return "July";
            case 8:
                return "August";
            case 9:
                return "September";
            case 10:
                return "October";
            case 11:
                return "November";
            case 12: 
                return "December";
        }
    }
public:
    void getMonth(){
        do{
            cout << "Enter month:";
            cin >> month;
            if (month > 12 || month < 1)
                cout << "Error: invalid month entered\n";
        }while(month > 12 || month < 1);
    }
    
    void getDay(){
        do{
            cout << "Enter day:";
            cin >> day;
            if(day < 1 || day > 31)
                cout << "Error: invalid day entered\n";
        }while(day < 1 || day > 31);
    }
    
    void getYear(){
        cout << "Enter year:";
        cin >> year;
    }
    
    void showDate1(){
        cout << month << "/" << day << "/" << year << endl; 
    }
    void showDate2(){
        cout << monthWord(month) << " " << day << ", " << year << endl;
    }
    void showDate3(){
        cout << day << " " << monthWord(month) << " " << year << endl;
    }
    
};

int main(int argc, char** argv) {
    
    Date day; 
    
    day.getMonth(); 
    day.getDay();
    day.getYear();
    
    day.showDate1();
    day.showDate2();
    day.showDate3();
    
    return 0;
}

