/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: nick
 *
 * Created on March 16, 2019, 12:39 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;


int *getData(int &);//Read the array
int *augment(const int *,int);//Augment and copy the original array
void prntAry(const int *,int);//Print the array

int main(int argc, char** argv) {
    int size;
    int *A = nullptr;
    int *Aaug = nullptr;

    A = getData(size);
    Aaug = augment(A, size);
    
    //output the data
    prntAry(A, size);
    cout << endl;
    prntAry(Aaug, size + 1);
    
    delete [] A; 
    delete [] Aaug;

    return 0;
}


int *getData(int &size){
    cin >> size;
    int *arr = new int [size];

    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }
    
    return arr; 
}

int *augment(const int *A,int size){
    int *arr = new int [size + 1];

    *arr = 0;

    for(int i = 1; i <= size; i++){
        arr[i] = A[i - 1];
    }
    
    return arr; 
}

void prntAry(const int *A,int size){
    for(int i = 0; i < size; i++){
        cout << A[i];
        if (i != size - 1)
            cout << " "; 
    }
}