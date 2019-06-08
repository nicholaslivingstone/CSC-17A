/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Longbow.h
 * Author: Nicholas
 *
 * Created on June 7, 2019, 7:10 PM
 */
#include "RandomNumber.h"
#include "Weapon.h"

#ifndef LONGBOW_H
#define LONGBOW_H

class Longbow : public Weapon{
public:
    const std::string name = "Longbow";
    int hit(){
        return Random::getRand(20) + 7; 
    }
    int damage(){
        return Random::getRand(8) + 3;
    }
};

#endif /* LONGBOW_H */

