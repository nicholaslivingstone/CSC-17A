/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: nick
 *
 * Created on April 3, 2019, 6:24 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

struct division{
    string name;
    float sales[4]; 
};

void getData(division &);
void writeData(division div, fstream &file);

int main(int argc, char** argv) {
    
    //structure of sales data
    division north = {"North"}, south = {"South"}, east = {"East"}, west = {"West"};
    
    //open file for output
    fstream file("sales.dat" , ios::out|ios::binary);
    
    //get sales data;
    getData(north);
    getData(south);
    getData(east);
    getData(west);
    
    cout << "Writing data to file...\n";
    
    writeData(north, file);
    writeData(south, file);
    writeData(east, file);
    writeData(west, file);
    
    cout << "Closing File...";
    file.close();
    
    return 0;
}

void getData(division &div){
    cout << "Enter sales data for " << div.name << "ern Division:" << endl; 
    for (int i = 0; i < 4; i++){    //loop through each quarter6
        do{
            cout << "Quarter " << i + 1 << ":";
            cin >> div.sales[i];
            if(div.sales[i] < 0)
                cout << "Error: invalid value entered\n"; 
        }while(div.sales[i] < 0);
    }
}

void writeData(division div, fstream &file){
    file.write(reinterpret_cast<char *>(&div), sizeof(div)); 
}
