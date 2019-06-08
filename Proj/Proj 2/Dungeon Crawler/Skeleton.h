/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Skeleton.h
 * Author: Nicholas
 *
 * Created on June 7, 2019, 4:26 PM
 */
#include "Monster.h"
#include "RandomNumber.h"
#include <iostream>

#ifndef SKELETON_H
#define SKELETON_H

class Skeleton : public Monster{
public:
    Skeleton() : Monster::Monster(13, 13, 50, "Skeleton") {};
    int attack(int _ac){
        int dmg = 0; 
        if(Random::getRand(20) + 4 > _ac){
            dmg = Random::getRand(6) + 2;
            std::cout << "The Skeleton attacked with a Shortsword for " << dmg << " damage!\n";
        }
        else
            std::cout << "Skeleton missed his attack!\n";
        return dmg; 
    }
};

#endif /* SKELETON_H */

