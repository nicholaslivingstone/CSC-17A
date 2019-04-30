/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Nicholas
 *
 * Created on April 29, 2019, 3:55 PM
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

struct Customer{
    string name,
        address;
    int accountNum; 
    double balance,
        checkTotal,
        depositTotal;
};

void calcBalance(Customer *);

int main(int argc, char** argv) {
    Customer *cust = nullptr;
    cust = new Customer; 
    
    //get name
    cout << "Enter name: ";
    getline(cin, cust->name);
    //get Address
    cout << "Enter Address: ";
    getline(cin, cust->address);
    //get Account number
    bool error = false; 
    do{
        error = false;
        cout << "Enter account number: ";
        cin >> cust->accountNum;
        //validate the length of the number
        int n =0; 
        int num = cust->accountNum;
        while(num){
            num /= 10;
            n++;
        }
        if (n != 5){
            cout << "Error. Invalid account number entered";
            error = true;
        }
    }while(error);
    //get Balance
    cout << "Enter balance from the beginning of the month: $";
    cin >> cust->balance;
    //get checks written
    cust->checkTotal = 0; 
    double check;
    int num = 0; 
    cout << "Enter value of all checks written, when finished enter 0\n";
    do{
        num++;
        cout << "Check #" << num << ": $";
        cin >> check;
        cust->checkTotal += check; 
    }while(check);
    //get Deposits
    cust->depositTotal = 0; 
    double deposit;
    num = 0; 
    cout << "Enter value of all deposits, when finished enter 0\n";
    do{
        num++;
        cout << "Deposit #" << num << ": $";
        cin >> deposit;
        cust->depositTotal += deposit; 
    }while(deposit);
    //display new balance
    calcBalance(cust);
    cout << cust->name << ", Your new balance is $" << fixed << setprecision(2) << cust->balance << endl;
    cout << "Address: " << cust->address << endl;
    cout << "Account Number: " << cust->accountNum;
    
    return 0;
}

void calcBalance(Customer *cust){
    cust->balance = cust->balance + cust->depositTotal - cust->checkTotal;
    if (cust->balance < 0){
        cout << "You've overdrawn your account, your account will be debited $20\n";
        cust->balance -= 20.0; 
    }
}