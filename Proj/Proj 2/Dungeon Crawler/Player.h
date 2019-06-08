/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.h
 * Author: Nicholas
 *
 * Created on June 7, 2019, 3:30 PM
 */

#ifndef PLAYER_H
#define PLAYER_H
#include "Weapon.h"
#include "Monster.h"
#include "Sword.h"
#include "Longbow.h"
#include "MagicStaff.h"
#include <iostream>


class Player{
public:
    Player(int _HP, int _AC, std::string _name, Weapon * _weapon){
        name = _name;
        HP = _HP;       
        AC = _AC;       
        XP = 0;         
        lvl = 1;
        gold = 100; 
        this->weapon = _weapon; 
    };
    void addXp(int _xpGained);
    Player(const Player& orig);
    virtual ~Player();
    void printInfo(){
        std::cout << "HP: " << HP << std::endl; 
        std::cout << "AC: " << AC << std::endl; 
        std::cout << "Level: " << lvl << std::endl; 
        std::cout << "Gold: " << gold << std::endl;
    }
    bool attack(Monster * _monster); 
    void defend(Monster & _monster);
    //Access & Mutator Functions
    void setAC(int AC);
    int getAC() const;
    void setHP(int HP);
    int getHP() const;
    void setXP(int XP);
    int getXP() const;
    void setLvl(int lvl);
    int getLvl() const;
    void setGold(int gold);
    int getGold() const;
private:
    std::string name; 
    int gold;   
    int lvl;   
    int XP;     
    int HP;    
    int AC;
    Weapon *weapon;
    void addXP(int);
};

#endif /* PLAYER_H */

