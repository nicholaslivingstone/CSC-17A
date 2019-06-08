/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.cpp
 * Author: Nicholas
 * 
 * Created on June 7, 2019, 3:30 PM
 */

#include "Player.h"
#include <cmath>
#include <iostream>
#include <string>


Player::Player(const Player& orig) {
}

Player::~Player() {
}

void Player::setAC(int AC) {
    this->AC = AC;
}

int Player::getAC() const {
    return AC;
}

void Player::setHP(int HP) {
    this->HP = HP;
}

int Player::getHP() const {
    return HP;
}

void Player::setXP(int XP) {
    this->XP = XP;
}

int Player::getXP() const {
    return XP;
}

void Player::setLvl(int lvl) {
    this->lvl = lvl;
}

int Player::getLvl() const {
    return lvl;
}

void Player::setGold(int gold) {
    this->gold = gold;
}

int Player::getGold() const {
    return gold;
}



void Player::addXP(int _gained){
    XP += _gained; 
    if(XP >= pow(300, lvl)){
        lvl++;
        std::cout << "You leveled up!\n";
    }
    
}

bool Player::attack(Monster * _monster){
    int dmg, choice, enemyDmg; 
    
    do{
        
        std::cout << "\n\n1. Attack with weapon\n";
        std::cout << "2. Use Item\n";
        std::cout << "3. Flee\n";
        std::cout << "Choice:";
        std::cin >> choice; 
        std::cout << std::string( 100, '\n' );
        switch(choice){
            case 1: 
                if(this->weapon->hit() > _monster->getAC()){
                    dmg = this->weapon->damage();
                    std::cout << this->weapon->name << "hit for " << dmg << " damage!\n";
                    _monster->setHP(_monster->getHP() - dmg);
                    std::cout << _monster->getName() << " has " << _monster->getHP() << " HP\n\n";
                }
                else
                    std::cout << "Attack missed!\n";
                break;
            case 2:
                    std::cout << "Nothing in bag!\n";
                break;
            case 3:
                return true; 
            default: 
                std::cout << "Input error\n";
        }
        enemyDmg = _monster->attack(this->AC);
        if(enemyDmg){
            this->HP -= enemyDmg;
            if(this->HP < 0)
                std::cout << "YOU DIED\n";
            else
                std::cout << "\nCurrent HP: " << this->HP << std::endl; 
        }
        
    }while(_monster->isAlive());
    std::cout << "Congrats the monster was defeated!\n";
    std::cout << "You gained " << _monster->getXP() << " XP." << std::endl;
    std::cout << "-New stats-";
    this->addXP(_monster->getXP());
    this->printInfo(); 
    return true; 
}
