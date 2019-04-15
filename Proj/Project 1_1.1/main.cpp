/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: nick
 *
 * Created on April 9, 2019, 7:57 PM
 */

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

struct player{
    string name; 
    int wins; 
};

void showWord(char *);
int chkGuess(char, char [], char []);
void clearMatch(char []);
bool chkWin(char [], char []);

int main(int argc, char** argv) {
    //variables
    char * word = nullptr,  //char pointer array to word being guessed
        * match = nullptr,
            letter;         //letter guess
    player * P = nullptr;   //pointer array to players
    int pcount,             //player count
        tries = 8;          //number of letter tries remaining
    word = new char[80];    //more elements than needed
    match = new char[80]; 
    
    cout << "Welcome to hangman!\n"; 
    cout << "Enter number of players:";
    
    //get player numbers
    do{
        cin >> pcount; 
        if (pcount <= 0)
            cout << "Error. Enter Again:";
    }while(pcount <= 0); 

    P = new player[pcount]; //create array of player structures
    
    //enter player names
    for(int i = 0; i < pcount; i++){
        cout << "Enter player " << i + 1 << " name: ";
        cin >> P[i].name;
    }
    
    //have host enter word
    cout << "Enter word/phrase to be guessed:";
    cin >> word; 
    
    match = word; //set the dummy match array to real word
    
    clearMatch(match);  //replace all letters with '?'

    //clear console so players don't see input of host
    for(int i = 0; i < 100; i++){
        cout << endl; 
    }
    
    
    //play game
    
    int i = 0; 
    //showWord(); 
    do{
        cout << P[i].name << "'s turn";
        cout << "Enter letter to guess:";
        cin >> letter;
        if (chkGuess(letter, word, match)){  //player has successfully guessed a letter
            cout << letter << " matched " << chkGuess(letter, word, match) << " times";
            showWord(match);
            if(chkWin(match, word)){ //check win conditions
                tries = 0;  //set to zero to exit do while loop
                cout << "Congrats! You guessed the whole phrase!";
                showWord(word);
            }
        }
        else{
            tries--; 
            cout << "No matching letter found!\n";
            if(tries == 0){         //if there are no tries remaining, provide end game display
                cout << "No tries remaining!";
                cout << "Revealed word:"; 
                showWord(word);
            }
            else{   
                cout << tries << " many attempts left";
                showWord(match);
            }
        }
        i++;    //increment i to move onto each player
        if(i > pcount)
            i = 0;      //reset player count to zero if highest number player has been reached
    }while(tries > 0);

    
    
    //clean up and exit
    delete [] word; 
    delete [] P; 
    
    return 0;
}

//checks if guessed letter is in the word/phrase and adjusts, returns false otherwise;
int chkGuess(char ch, char phrase[], char match[]){
    int i = 0, matches = 0; 
    while(phrase[i] != NULL){
        if(phrase[i] == ch){
            matches++; 
            match[i] = ch; 
        }
        i++;
    }
    return matches;
    
}

//display phrase
void showWord(char phrase[]){
    int i = 0; 
    while(phrase[i] != NULL){
        cout << phrase[i];
    }
}

//replace all charcaters besides space with '?' to be displayed later
void clearMatch(char match[]){
    int i = 0; 
    while(match[i] != NULL){
        if(match[i] != ' '){
            match[i] = '?';
        }
        i++;
    }
}

//check if the arrays are now equal
bool chkWin(char match[], char phrase[]){
    int i = 0; 
    while(match[i] != NULL){
        if(match[i] != phrase[i])
            return false; 
        i++;
    }

    return true; 
}