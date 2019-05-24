/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Nicholas
 *
 * Created on May 23, 2019, 10:30 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

class Date {
private:
	int month,
		day,
		year;
	string monthWord(int m) {
		switch (m) {
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
	void getMonth() {
		do {
			cout << "Enter month:";
			cin >> month;
			if (month > 12 || month < 1)
				throw InvalidMonth(); 
		} while (month > 12 || month < 1);
	}

	void getDay() {
		do {
			cout << "Enter day:";
			cin >> day;
			if (day < 1 || day > 31)
				throw InvalidDay();
		} while (day < 1 || day > 31);
	}

	void getYear() {
		cout << "Enter year:";
		cin >> year;
	}

	void showDate1() {
		cout << month << "/" << day << "/" << year << endl;
	}
	void showDate2() {
		cout << monthWord(month) << " " << day << ", " << year << endl;
	}
	void showDate3() {
		cout << day << " " << monthWord(month) << " " << year << endl;
	}

	//Exceptions
	class InvalidDay
		{};
	class InvalidMonth
		{};
};

int main(int argc, char** argv) {

    Date day;
    try {
            day.getMonth();
            day.getDay();
            day.getYear();

            day.showDate1();
            day.showDate2();
            day.showDate3();
    }
    catch (Date::InvalidDay) {
            cout << "Error Invalid Day. Exiting...";
    }
    catch (Date::InvalidMonth) {
            cout << "Error Invalid Month. Exiting..."; 
    }
    return 0;
}

