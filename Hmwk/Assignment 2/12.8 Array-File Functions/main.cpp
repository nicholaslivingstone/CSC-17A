/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: nick
 *
 * Created on March 29, 2019, 3:44 PM
 */

#include <cstdlib>
#include <cctype>
#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

void arrayToFile(fstream &, int [], int);
void fileToArray(fstream &, int [], int);

int main(int argc, char** argv) {
    int * inArr = nullptr;
    int * outArr = nullptr; 
    int size; 
    srand(time(NULL));
    do{
        cout << "Enter number of array elements to be written and read from file(<10):";
        cin >> size; 
        if(size > 10){
            cout << "Error: enter value < 10\n";
        }
    }while(size > 10);
    inArr = new int[size];
    outArr = new int [size];
    
    cout << "Opening file..." << endl;
    fstream file;
    //create a random array for testing
    cout << "Array to be stored:\n"; 
    for (int i = 0; i < size; i++){
        inArr[i] = rand() % 100 + 1;
        cout << inArr[i] << " ";
    }
    cout << endl; 
    
    
    arrayToFile(file, inArr, size);
    fileToArray(file, outArr, size);
    
    cout << "Array contents:\n";
    for (int i = 0; i < size; i++){
        cout << outArr[i] << " ";
    }
    cout << endl;
    
    //cleanup
    cout << "Cleaning up...\n"; 
    delete [] inArr;
    delete [] outArr;
    return 0;
}

void arrayToFile(fstream &file,int * arr, int size){
    file.open("output.txt", ios::out|ios::binary); 
    cout << "Writing array to file..." << endl;
    file.write(reinterpret_cast<char *>(arr), sizeof(arr) * size);
    file.close(); 
    
}

void fileToArray(fstream &file,int * arr, int size){
    file.open("output.txt", ios::in|ios::binary);
    cout << "Reading array from file..." << endl;
    file.read(reinterpret_cast<char *>(arr), sizeof(arr) * size);
    file.close(); 
}