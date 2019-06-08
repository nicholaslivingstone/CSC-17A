/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Wolf.h
 * Author: Nicholas
 *
 * Created on June 7, 2019, 4:26 PM
 */

#include "Monster.h"
#include "RandomNumber.h"
#include <iostream>

#ifndef WOLF_H
#define WOLF_H

class Wolf : public Monster{
public:
    Wolf() : Monster::Monster(13, 11, 50, "Wolf") {};
    int attack(int _ac){
        int dmg = 0; 
        if(Random::getRand(20) + 4 > _ac){
            dmg = Random::getRand(4) + Random::getRand(4) + 2;
            std::cout << "The wolf bit you for " << dmg << " damage!\n";
        }
        else
            std::cout << "Wolf missed his attack!\n";
        return dmg; 
    }
};

#endif /* WOLF_H */

