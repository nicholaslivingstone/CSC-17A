/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RandomNumber.h
 * Author: Nicholas
 *
 * Created on June 7, 2019, 3:56 PM
 */
#include <random>

#ifndef RANDOMNUMBER_H
#define RANDOMNUMBER_H

class Random{
public:
    static getRand(int _max){
        std::random_device rd;  
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, _max);
        return dis(gen);
    }
    
    static getRand(int _min , int _max){
        std::random_device rd;  
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(_min, _max);
        return dis(gen);
    }
};

#endif /* RANDOMNUMBER_H */

