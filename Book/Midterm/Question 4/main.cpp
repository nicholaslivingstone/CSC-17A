/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Nicholas
 *
 * Created on April 30, 2019, 12:38 AM
 */

#include <cstdlib>
#include <iostream>
using namespace std;


void encrypt(int *);
void decrypt(int *); 

int main(int argc, char** argv) {
    
    int choice;
    
    cout << "Options\n";
    cout << "-------\n";
    cout << "1.Encrypt\n";
    cout << "2.Decrypt\n";
    do{
        cout << "Enter 1 or 2: "; 
        cin >> choice; 
        if (choice != 1 && choice != 2){
            cout << "Error invalid option selected\n";
        }
    }while(choice != 1 && choice != 2);
    
    char * charData = new char[4];
    int * data = new int[4];
    bool error = false; 
    
    
    do{
        error = false; 
        cout << "Enter 4 digit data: ";
        cin >> charData; 
        for(int i = 0; i < 4; i++){
            if(charData[i] > '7' || charData[i] < '0'){
                cout << "Error: Invalid digit entered\n";
                error = true;
                i = 4;
            }
        }
    }while(error);
    
    for(int i = 0; i < 4; i++){
        data[i] = charData[i] - '0';
    }
    delete [] charData;
    
    int temp; 
    temp = data[0];
    data[0] = data[2];
    data[2] = temp;
    temp = data[1];
    data[1] = data[3];
    data[3] = temp; 
    
    if(choice == 1){
        encrypt(data); 
    }
    else{
        decrypt(data);
    }
    
    delete [] data;
    
    return 0;
}

void encrypt(int *data){
    cout << "Encrypted data: ";
    for(int i = 0; i < 4; i++){
        data[i] = (data[i] + 5) % 8;
        cout << data[i];
    }
}

void decrypt(int *data){
    cout << "Decrypted data: ";
    for(int i = 0; i < 4; i++){
        if(data[i] < 5)
            data[i] += 3;
        else
            data[i] -= 5;
        cout << data[i];
    }
}
