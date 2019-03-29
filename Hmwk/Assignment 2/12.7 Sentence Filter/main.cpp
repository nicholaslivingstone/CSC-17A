/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: nick
 *
 * Created on March 29, 2019, 12:11 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <cctype>
#include <fstream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    string fileName;    //input file name
    char ch;            //character being read
    ifstream inFile;    //input file object

    ofstream outFile("output");    //output file object

    cout << "File Name:";
    cin >> fileName; 

    //open file
    inFile.open(fileName);

    if(inFile){ //check if file was opened successfully
        cout << "Reading file..." << endl; 
        inFile.get(ch);
        if (isalpha(ch)){   //capitalize the first char if it's a letter
            outFile.put(toupper(ch));
            inFile.get(ch);
        }
        while(inFile){
            if(ch == '.'){
                outFile.put('.');
                inFile.get(ch);
                //account for spaces after a period
                if (ch == ' '){     
                    outFile.put(' ');
                    inFile.get(ch);
                }
                //check if there is more letters
                if(inFile)
                    outFile.put(toupper(ch));
            }
            else{
                //lower case all letters
                if (isalpha(ch))
                    outFile.put(tolower(ch));
                else    //otherwise reprint the character
                    outFile.put(ch);
            }
            inFile.get(ch);
        }
    }
    else{
        cout << "Error: File not found/cannot be opened";
    }
    
    //close files
    cout << "Closing files...";
    inFile.close();
    outFile.close();

    return 0;
}

