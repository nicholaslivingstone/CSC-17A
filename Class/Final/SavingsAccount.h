/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SavingsAccount.h
 * Author: Nicholas
 *
 * Created on June 7, 2019, 10:27 PM
 */

#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

class SavingsAccount {
    public:
        SavingsAccount(float);               //Constructor
        void  Transaction(float);            //Procedure
        float Total(float,int);	         //Savings Procedure
        float TotalRecursive(float,int);
        void  toString();

        void SetFreqDeposit(int FreqDeposit) {
            this->FreqDeposit = FreqDeposit;
        }

        int GetFreqDeposit() const {
            return FreqDeposit;
        }

        void SetFreqWithDraw(int FreqWithDraw) {
            this->FreqWithDraw = FreqWithDraw;
        }

        int GetFreqWithDraw() const {
            return FreqWithDraw;
        }

        void SetBalance(float Balance) {
            this->Balance = Balance;
        }

        float GetBalance() const {
            return Balance;
        }                    //Output Properties
    private:
        float Withdraw(float);               
        float Deposit(float);                
        float Balance;                       
        int   FreqWithDraw;                  
        int   FreqDeposit;                   
};
#endif /* SAVINGSACCOUNT_H */

