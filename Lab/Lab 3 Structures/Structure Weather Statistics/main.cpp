/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: nick
 *
 * Created on March 28, 2019, 7:25 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;


struct weather {
    string monthName;
    float rain, highTemp, lowTemp, avgTemp;
};

void setInfo(weather &);
float getAvgTemp(weather []);
float getAvgRain(weather []);
string getHighTemp(weather []);
string getLowTemp(weather []);

int main(int argc, char** argv) {
    weather year[12];

    //get weather data
    for(int i = 0; i < 12; i++){
        setInfo(year[i]);
    }


    cout << "Average Rainfall " << setprecision(1) << fixed << getAvgRain(year) << " inches/month\n";
    cout << "Lowest  Temperature " << getLowTemp(year) << " Degrees Fahrenheit\n";
    cout << "Highest Temperature " << getHighTemp(year) << " Degrees Fahrenheit\n";
    cout << "Average Temperature for the year " << setprecision(0) << fixed << getAvgTemp(year) << " Degrees Fahrenheit\n";

    return 0;
}

void setInfo(weather &month){
    cin >> month.monthName; 
    cin >> month.rain;
    cin >> month.lowTemp;
    cin >> month.highTemp;
    month.avgTemp = (month.highTemp + month.lowTemp)/2; 
}

float getAvgTemp(weather year[]){
    float tot = 0; 
    for(int i = 0; i < 12; i++){
        tot += year[i].avgTemp;
    }
    return tot/12;
}

float getAvgRain(weather year[]){
    float tot = 0; 
    for(int i = 0; i < 12; i++){
        tot += year[i].rain;
    }
    return tot/12;
}

string getHighTemp(weather year[]){
    float high = year[0].highTemp;
    string highMonth = year[0].monthName;
    for(int i = 1; i < 12; i++){
        if (year[i].highTemp > high){
            high = year[i].highTemp; 
            highMonth = year[i].monthName;
        }
    }

    int highInt = high;
    
    return highMonth + "  " + to_string(highInt);
}

string getLowTemp(weather year[]){
    float low = year[0].lowTemp;
    string lowMonth = year[0].monthName;
    for(int i = 1; i < 12; i++){
        if (year[i].lowTemp < low){
            low = year[i].lowTemp; 
            lowMonth = year[i].monthName;
        }
    }

    int lowInt = low; 

    return lowMonth + "  " + to_string(lowInt);
}