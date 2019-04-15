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
#include <cctype>

using namespace std;

struct player{
    string name; 
    int wins; 
};

void showWord(char *);
int chkGuess(char, char [], char []);
void clearMatch(char [], char []);
bool chkWin(char [], char []);
void getPlayerNames(player [], int);
void writeExWords();

int main(int argc, char** argv) {
    //variables
    char * word = nullptr,  //char pointer array to word being guessed
        * match = nullptr,  //char pointer array to store matched guesses
       * failed = nullptr,  
            letter;         //letter guess
    player * P = nullptr;   //pointer array to players
    int pcount,             //player count
        tries = 8;          //number of letter tries remaining
    word = new char[80];    //more elements than needed
    match = new char[80];   //matched character array
    failed = new char[26];  //attempted failed characters
    string temp;            //temporary string for phrase input
    fstream file;           //file to store past phrases and provides some examples 
    char * binword = nullptr;
    binword = new char [80] {'e', 'x', 'a', 'm', 'p', 'l', 'e'};
    
    //file processing
    file.open("words.txt", ios::in|ios::out|ios::binary);   //attempt to open file
    if(file.fail()){    //create if it's failed
        file.open("words.txt", ios::out|ios::binary);
        file.write(binword, sizeof(binword)); 
        file.close();    
        file.open("words.txt", ios::in|ios::out|ios::binary);
    }
    
    file.read(binword, sizeof(binword));
    
    cout << "Welcome to hangman!\n";    
    cout << "Most recent word: ";
    int x = 0; 
    while(binword[x] != NULL){
        cout << binword[x];
        x++;
    }
    cout << "\nEnter number of players:";
    
    
    //get player numbers
    do{
        cin >> pcount; 
        if (pcount <= 0)
            cout << "Error. Enter Again:";
    }while(pcount <= 0); 

    P = new player[pcount]; //create array of player structures
    
    //enter player names
    getPlayerNames(P, pcount);
    
    //have host enter word
    cout << "Enter word/phrase to be guessed:";
    cin.ignore(); 
    getline(cin, temp); 
    
    
    for(int i = 0; i < temp.length(); i++){
        word[i] = temp[i];
    }
    file.write(word, sizeof(word)); 
    clearMatch(match, word);  //replace all letters with '?'

    //clear console so players don't see input of host
    for(int i = 0; i < 100; i++){
        cout << endl; 
    }
    
    
    //play game
    
    int i = 0; 
    bool error; 
    //showWord(); 
    do{
        cout << P[i].name << "'s turn\n";
        do{
            cout << "Enter letter to guess:";
            error = false; 
            cin >> letter; 
            int j = 0; 
            while(match[j] != NULL){
                if(match[j] == letter){
                    cout << "Error. Letter has already been guessed";
                    error = true; 
                }
                j++;
            }
            j = 0; 
            while(failed[j] != NULL){   //check against already failed letters
                cout << "Error";
            }
        }while(error);
        if (chkGuess(letter, word, match)){  //player has successfully guessed a letter
            cout << letter << " matched " << chkGuess(letter, word, match) << " times" << endl;
            showWord(match);
            if(chkWin(match, word)){ //check win conditions
                tries = 0;  //set to zero to exit do while loop
                cout << "Congrats! You guessed the whole phrase!";
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
            else{                   //otherwise print number of remaining attempts 
                cout << tries << " many attempts left";
                showWord(match);
            }
        }
        i++;    //increment i to move onto each player
        if(i == pcount)
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
        i++; 
    }
    cout << endl; 
}

//replace all characters besides space with '?' to be displayed later
void clearMatch(char match[], char phrase[]){
    int i = 0; 
    while(phrase[i] != NULL){
        if(isspace(phrase[i])){
            match[i] = ' ';     //ignore all spaces
        }
        else
            match[i] = '?';
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

void getPlayerNames(player P[], int n){
    for(int i = 0; i < n; i++){
        cout << "Enter player " << i + 1 << " name: ";
        cin >> P[i].name;
    }
}
