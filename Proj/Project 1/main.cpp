/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: nick
 *
 * Created on April 9, 2019, 12:24 PM
 */

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

/* 
 * hang man
 * memory allocation with arrays and structures
 * pointer with arrays and arrays of structures
 * use of character arrays as well as string objects
 * reading and writing to binary files
 */

struct player{
    string name; 
    int wins; 
};

int main(int argc, char** argv) {
    
    //variables
    char * word = nullptr;  //char pointer array to word being guessed
    player * P = nullptr;   //pointer array to players
    int pcount;             //player count
    word = new char[80];    //more elements than needed
    
    cout << "Welcome to hangman!\n"; 
    cout << "Enter number of players:";
    
    //get player numbers
    do{
        cin >> pcount; 
        if (pcount <= 0)
            cout << "Error. Enter Again:";
    }while(pcount <= 0); 

    P = new player[pcount]; //create array of player structures
    
    //have host enter word
    cout << "Enter word to be guessed:";
    
    //clean up
    delete [] word; 
    delete [] P; 
    
    return 0;
}

void setName(string name){
    cout << "Enter player name:";
    cin >> name;
}

char * setWord(){
    char * temp = new char[5]; 
    cout << "Enter word to guess: ";
    cin >> temp; 
    return temp;  
}

void showPlayerData(){
   
}