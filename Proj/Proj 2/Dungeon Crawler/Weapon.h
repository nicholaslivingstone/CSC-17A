/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Weapon.h
 * Author: Nicholas
 *
 * Created on June 7, 2019, 2:57 PM
 */
#include <string>

#ifndef WEAPON_H
#define WEAPON_H

class Weapon {
public:
    virtual int hit() = 0;
    virtual int damage() = 0;
    std::string name;
};

#endif /* WEAPON_H */

