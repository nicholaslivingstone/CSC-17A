/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: nick
 *
 * Created on April 3, 2019, 7:10 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
using namespace std;

struct division{
    string name;
    float sales[4]; 
};



int main(int argc, char** argv) {
    fstream file("sales.dat", ios::in|ios::binary);
    
    float quarterSales[4], //total sales of each quarter
            annDivSales[4],//annual sales for each division
            annSales = 0,   //total yearly sales
            avgQuart[4];     //average quarterly sales for each division
    
    division * divs = nullptr; 
    divs = new division[4]; //[each territory(north, south...)]
    string name[4] = {"North", "South", "East", "West"};
    
    
    
    if(!file){
        cout << "ERROR OPENING FILE. EXITING";
        return 0; 
    }
    
    for(int i = 0; i < 4; i++){
        file.read(reinterpret_cast<char *>(&divs[i]), sizeof(divs[i]));
    }
    
    for(int i = 0; i < 4; i++){
        quarterSales[i] = divs[0].sales[i] + divs[1].sales[i] + divs[2].sales[i] + divs[3].sales[i];
        annDivSales[i] = divs[i].sales[0] + divs[i].sales[1] + divs[i].sales[2] + divs[i].sales[3];
        annSales += annDivSales[i];
        avgQuart[i] = annDivSales[i] / 4.0F;
    }
    
    
    cout << fixed << setprecision(2) << setfill('.');
    cout << "CORPORATE YEARLY SALES" << endl; 
    cout << "   Total Annual" << fixed << setw(20) << setprecision(2) << annSales << endl;
    for(int i = 0; i < 4; i++){
        cout << "Total Quarter " << i + 1 << fixed << setw(20) << setprecision(2) << quarterSales[i] << endl;
    }
    for(int i = 0; i < 4; i++){
        cout << "  Avg Quarter " << i + 1 << setw(20) << avgQuart[i] << endl; 
    }
    for(int i = 0; i < 4; i++){
        cout << setfill(' ') << setw(5) << name[i] << "ern Division Annual" << setfill('.') << setw(11) << annDivSales[i] << endl;
    }
    
    file.close();
    
    return 0;
}