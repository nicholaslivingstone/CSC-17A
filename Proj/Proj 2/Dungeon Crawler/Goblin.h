/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Goblin.h
 * Author: Nicholas
 *
 * Created on June 7, 2019, 4:25 PM
 */
#include "Monster.h"
#include "RandomNumber.h"
#include <iostream>

#ifndef GOBLIN_H
#define GOBLIN_H

class Goblin : public Monster{
public:
    Goblin() : Monster::Monster(15, 7, 50, "Goblin") {};
    int attack(int _ac){
        int dmg = 0; 
        if(Random::getRand(20) + 4 > _ac){
            dmg = Random::getRand(6) + 2;
            std::cout << "The Goblin attacked with a Scimitar for " << dmg << " damage!\n";
        }
        else
            std::cout << "Goblin missed his attack!\n";
        return dmg; 
    }
};

#endif /* GOBLIN_H */

