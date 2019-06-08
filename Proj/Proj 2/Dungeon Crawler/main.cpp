/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Nicholas
 *
 * Created on June 7, 2019, 2:57 PM
 */

#include <cstdlib>
#include "RandomNumber.h"
#include "Monster.h"
#include "Goblin.h"
#include "Player.h"
#include "Wolf.h"
#include "Skeleton.h"
#include "Sword.h"
#include "MagicStaff.h"
#include "Longbow.h"
#include <iostream>

using namespace std;

void enterDungeon(Player &);
void visitMerchant();


int main(int argc, char** argv){
    
    //variables
    string name;
    int choice;

    
    cout << "Welcome to...\n"
            "   THE DUNGEON\n"
            "       a text based dungeon crawler\n";
    cout << "Enter your name to begin:";
    cin >> name; 
    
    
    cout << "-Class selection-\n"; 
    cout << "Information displayed is your starting stats\n";
    cout << "1. Warrior\n"
            "   Weapon: Sword\n"
            "   Hit Points: 12\n"
            "   Armor Class: 17\n";
    cout << "2. Mage\n"
            "   Weapon: Magic Staff\n"
            "   Hit Points: 8\n"
            "   Armor Class: 12\n";
    cout << "3. Ranger\n"
            "   Weapon: Longbow\n"
            "   Hit Points: 12\n"
            "   Armor Class: 14\n";
    cout << "Choice:";
    cin >> choice;
    Weapon *wp;
    int stats[3][2] = {{12, 17}, {8, 12}, {12, 14}};
    switch(choice){
            case 1: 
                wp = new Sword();
                break;
            case 2:
                wp = new MagicStaff();
                break;
            case 3:
                wp = new Longbow();
                break;
        }
    Player player(stats[choice - 1][0], stats[choice - 1][1], name, wp);
    do{
        cout << endl; 
        cout << "1. Enter the dungeon\n";
        cout << "2. Visit the Merchant\n";
        cout << "3. View character info\n";
        cout << "4. Quit the game\n";
        cout << "Choice:";
        cin >> choice; 
        
        switch(choice){
            case 1: 
                enterDungeon(player); 
                break;
            case 2:
                cout << "Merchant is currently away.\n";
                break;
            case 3:
                player.printInfo();
            case 4:
                exit(EXIT_SUCCESS);
            default: 
                cout << "Input error\n";
        }
    }while(true);

    return 0;
}

void enterDungeon(Player &player){
    int choice; 
    cout << "You begin you descent..\n";
    bool alive = true, error;
    do{
        Monster *enemy;
        switch(Random::getRand(3)){
            case 1:
                enemy = new Goblin();
                break;
            case 2:
                enemy = new Wolf();
                break;
            case 3:
                enemy = new Skeleton();
                break;
        }
        cout << "\n\nA " << enemy->getName() << " appears before you!\n";
        cout << "-Current Stats-\n";
        player.printInfo();
        cout << "What would you like to do?\n";
        do{
            error = false; 
            cout << "1. Attack\n";
            cout << "2. Run\n";
            cout << "Choice:";
            cin >> choice;
        
            switch(choice){
                case 1: 
                    break;
                case 2:
                    cout << "You dash towards the entrance. Narrowly escaping!\n";
                    return; 
                default: 
                    cout << "Input error\n";
                    error = true; 
            }
        }while(error);
        alive = player.attack(enemy);
    }while(alive);
}

void visitMerchant(){
    do{
        
    }while(true);
}


