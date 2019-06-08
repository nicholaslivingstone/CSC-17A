/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Monster.h
 * Author: Nicholas
 *
 * Created on June 7, 2019, 3:06 PM
 */

#include "Weapon.h"
#include <string>
#ifndef MONSTER_H
#define MONSTER_H


class Monster {
protected:
    int AC;
    int HP;
    int XP;
    std::string name; 
    bool alive;
public:
    Monster(int _AC, int _HP, int _XP, std::string _name){
        this->AC = _AC; 
        this->HP = _HP; 
        this->XP = _XP; 
        name = _name; 
        alive = true;
    }

    std::string getName() const {
        return name;
    }

    int getXP() const {
        return XP;
    }

    void setHP(int HP) {
        if(HP < 0)
            alive = false;
        this->HP = HP;
    }

    int getHP() const {
        return HP;
    }

    void setAC(int AC) {
        this->AC = AC;
    }

    int getAC() const {
        return AC;
    }

    void setAlive(bool alive) {
        this->alive = alive;
    }

    bool isAlive() const {
        return alive;
    }
    
    virtual int attack(int) = 0; 
};
#endif /* MONSTER_H */

