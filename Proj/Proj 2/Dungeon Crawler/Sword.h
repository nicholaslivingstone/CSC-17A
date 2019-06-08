/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sword.h
 * Author: Nicholas
 *
 * Created on June 7, 2019, 7:09 PM
 */
#include "RandomNumber.h"
#include "Weapon.h"
#include <string>

#ifndef SWORD_H
#define SWORD_H

class Sword : public Weapon{
public:
    const std::string name = "Sword";
    int hit(){
        return Random::getRand(20) + 4; 
    }
    int damage(){
        return Random::getRand(12) + 3;
    }
};

#endif /* SWORD_H */

