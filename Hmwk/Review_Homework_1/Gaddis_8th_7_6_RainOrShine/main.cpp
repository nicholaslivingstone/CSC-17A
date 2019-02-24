/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: nick
 *
 * Created on February 21, 2019, 11:43 PM
 */

#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

void monthWrite(ofstream&, string, int , int [][3]);
string comp(int [][3]);

/*
 * 
 */
int main(int argc, char** argv) {
    
    char day[3][30];
    int count[3][3];    //stores number of days [month][weather type]
    
    
    //initialize array count to be empty
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            count[i][j] = 0; 
        }
    }
    
    //create object file to read
    ifstream inputFile;
    inputFile.open("RainOrShine.txt");
    
    //read file and sort into counting array
    for (int i = 0; i < 3; i++){    //loop through each month
        for (int j = 0; j < 30; j++){   //loop through each day
            inputFile >> day[i][j];
            switch (day[i][j]){     //switch statement that reads the file input and adds how many of each day there was for each month
                case 'R':          
                    count[i][0] ++;
                    break; 
                case 'C':
                    count[i][1] ++;
                    break;
                case 'S':
                    count[i][2] ++;
                    break; 
            }
        }
    }
    
    
    //create/open the report txt file
    ofstream report;
    report.open("Meteorology_report.txt");
    
    cout << "Writing data to Meteorology_report.txt...";
    
    //write data to the file
    report << "Total" << endl; 
    report << "-----------------" << endl; 
    report << "Rainy Days:  " << count[0][0] + count[1][0] + count[2][0]<< endl;
    report << "Cloudy Days: " << count[0][1] + count[1][1] + count[2][1] << endl;
    report << "Sunny Days:  " << count[0][2] + count[1][2] + count[2][2] << endl << endl;
    monthWrite(report, "January", 0, count);
    monthWrite(report, "February", 1, count);
    monthWrite(report, "March", 2, count);
    report << "Rainiest Month: " << comp(count);
    
    inputFile.close(); 
    return 0;
}


//writes a particular month and it's weather data to the file 
void monthWrite(ofstream& file, string month, int m, int count[][3]){
    file << month << endl; 
    file << "-----------------" << endl; 
    file << "Rainy Days:  " << count[m][0] << endl;
    file << "Cloudy Days: " << count[m][1] << endl;
    file << "Sunny Days:  " << count[m][2] << endl << endl;
}



//function to determine which month has the most rain
string comp(int count[][3]){
    string rain;
    
    int jan = count[0][0],
            feb = count[1][0],
            mar = count[2][0];
    
    rain = jan > feb ? (jan > mar ? "January" : "March") : (feb > mar ?  "February" : "March");
    
    return rain; 
}
