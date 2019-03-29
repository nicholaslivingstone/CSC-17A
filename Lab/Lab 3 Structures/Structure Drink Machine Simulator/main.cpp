/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: nick
 *
 * Created on March 28, 2019, 8:08 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

struct sodaMachine{
    string name;
    float cost;
    int num; 
};

void showSodas(sodaMachine []);
void buySoda(string, sodaMachine [], int &);
/*
 * 
 */
int main(int argc, char** argv) {
    int profit = 0; 
    sodaMachine soda[5] = {{"Cola", .75, 20}, {"Root Beer", .75, 20}, {"Lemon-Lime", .75, 20}, {"Grape Soda", .80, 20}, {"Cream Soda", .80, 20}};
    string choice; 

    do{
        showSodas(soda);
        getline(cin, choice); 
        if (choice != "Quit")
            buySoda(choice, soda, profit);
        else{
            cout << profit << endl;
            return 0; 
        }
        cin.ignore();
    }while(choice != "Quit");

    return 0;
}
void showSodas(sodaMachine soda[]){
    for(int i = 0; i < 5; i++){
        cout << left << setfill(' ');
        cout << setw(11) << soda[i].name << soda[i].cost * 100 << "  " << soda[i].num << endl; 
    }
    cout << "Quit" << endl; 
}

void buySoda(string choice, sodaMachine soda[], int &profit){
    int i, money, change; 
    if (choice == "Cola") i = 0; 
    else if (choice == "Root Beer") i = 1; 
    else if (choice == "Lemon-Lime") i = 2; 
    else if (choice == "Grape Soda") i = 3; 
    else if (choice == "Cream Soda") i = 4; 
    
    if (soda[i].num == 0){
        cout << "DRINK SOLD OUT, make a new selection" << endl;
        return;
    }
    
    soda[i].num--;
    bool error = false;
    do{
        error = false;
        cin >> money;
        if ((money < 0 | money > 100)|money < soda[i].cost * 100 > money){
            error = true; 
            cout << "ERROR: INVALID AMOUNT OF MONEY INSERTED\n" << endl; 
        }
    }while(error);
    change = money - soda[i].cost * 100;
    profit += soda[i].cost * 100;

    cout << change << endl; 
}
