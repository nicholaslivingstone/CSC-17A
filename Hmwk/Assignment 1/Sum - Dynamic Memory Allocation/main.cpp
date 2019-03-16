/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: nick
 *
 * Created on March 16, 2019, 11:54 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int *getData(int &);//Return the array size and the array from the inputs
int *sumAry(const int *,int);//Return the array with successive sums
void prntAry(const int *,int);//Print the array


int main(int argc, char** argv) {
    int *A = nullptr;
    int *sumA = nullptr;
    int size; 

    A = getData(size);
    sumA = sumAry(A, size);
    prntAry(A, size); 
    cout << endl;
    prntAry(sumA, size);

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

int *sumAry(const int *A,int size){
    int *arr = new int [size];
    int sum = 0;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < i + 1; j++){
            sum += A[j];
        }
        arr[i] = sum;
        sum = 0;
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