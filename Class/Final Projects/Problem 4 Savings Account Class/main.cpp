/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Nicholas
 *
 * Created on June 7, 2019, 4:10 AM
 */

#include <cstdlib>
#include <random>
#include <iostream>
#include "SavingsAccount.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    random_device dev; 
    mt19937 gen(dev());
    uniform_real_distribution<> dis(-500, 500);
    
    SavingsAccount sa(-300);
    for(int i = 0; i < 10; i++){
        sa.Transaction(dis(gen));
    }
    sa.toString();
    cout << "Balance after 7 years at 10% Interest = " << sa.Total(0.10f, 7) << endl;
    cout << "Balance after 7 years at 10% Interest = " << sa.TotalRecursive(0.10f, 7) << " Recursive Calculation" << endl;
}

