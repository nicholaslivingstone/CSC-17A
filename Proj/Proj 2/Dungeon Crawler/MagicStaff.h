/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MagicStaff.h
 * Author: Nicholas
 *
 * Created on June 7, 2019, 7:09 PM
 */
#include "Weapon.h"
#include "RandomNumber.h"

#ifndef MAGICSTAFF_H
#define MAGICSTAFF_H

class MagicStaff : public Weapon{
public:
    const std::string name = "Magic Staff";
    int hit(){
        return Random::getRand(20) + 5; 
    }
    int damage(){
        return (Random::getRand(4) + 1) + (Random::getRand(4) + 1) + (Random::getRand(4) + 1);
    }
};

#endif /* MAGICSTAFF_H */

