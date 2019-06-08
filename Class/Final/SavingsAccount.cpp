/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SavingsAccount.cpp
 * Author: Nicholas
 * 
 * Created on June 7, 2019, 10:27 PM
 */

#include "SavingsAccount.h"

#include <iostream>



SavingsAccount::SavingsAccount(float _initDeposit) {
    if(_initDeposit > 0)
        this->Balance = _initDeposit; 
    else
        this->Balance = 0; 
    this->FreqWithDraw = 0;
    this->FreqDeposit = 0;
    
}

float SavingsAccount::Withdraw(float _amount){
    if(this->Balance - _amount < 0){
        std::cout << "Error:Withdrawal exceeds current balance.";
        return 0;
    }
    this->Balance -= _amount;
    this->FreqWithDraw++; 
}

float SavingsAccount::Deposit(float _amount){
    this->Balance += _amount;
    this->FreqDeposit++; 
}

void SavingsAccount::Transaction(float _amount){
    if(_amount > 0)
        Deposit(_amount);
    else
        Withdraw(_amount);
}

void SavingsAccount::toString(){
    std::cout << "Balance=" << this->Balance << std::endl;
    std::cout << "Withdrawals=" << this->FreqWithDraw << std::endl;
    std::cout << "Deposits=" << this->FreqDeposit << std::endl;
}

float SavingsAccount::Total(float _rate, int _years){
    float total = 1; 
    for(int i = 0; i < _years; i++){
        total *= _rate + 1;
    }
    total *= Balance; 
    return total;
}

float SavingsAccount::TotalRecursive(float _rate, int _years){
    if(_years == 0)
        return Balance;
    return (_rate + 1) * TotalRecursive(_rate, _years - 1);
}

