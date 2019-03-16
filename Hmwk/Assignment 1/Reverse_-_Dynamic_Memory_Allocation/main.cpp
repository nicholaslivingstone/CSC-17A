/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: nick
 *
 * Created on March 16, 2019, 2:22 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int *getData(int &);               //Fill the array
int *sort(const int *,int);         //Sort smallest to largest
int *reverse(const int *,int);  //Sort in reverse order
void prntDat(const int *,int); //Print the array

int main(int argc, char** argv) {
    int size,
            *A = nullptr,
            *sortA = nullptr,
            *revA = nullptr;
    
    
    A = getData(size);
    sortA = sort(A, size);
    revA = reverse(sortA, size);
    
    //output data
    prntDat(sortA, size);
    cout << endl; 
    prntDat(revA, size);
    
    delete [] A;
    
    
    return 0;
}

int *getData(int &size){
    cin >> size;
    
    int *A = new int [size];
    
    for(int i = 0; i < size; i++){
        cin >> A[i];
    }
    
    return A; 
}

int *sort(const int *A,int size){
    int *arr = new int [size];
    
    for (int i = 0; i < size; i++){
        arr[i] = A[i];
    }
    
    int start, mini, min; 
    
    for(start = 0; start < size -1; start++){
        mini = start;
        min = arr[start];
        for(int i = start + 1; i < size; i++){
            if(arr[i] < min){
                min = arr[i];
                mini = i;
            }
        }
        arr[mini] = arr[start];
        arr[start] = min;
    }
    
    return arr;
}

int *reverse(const int *A,int size){
   int *arr = new int [size],
           temp; 
    
    for (int i = 0; i < size; i++){
        arr[i] = A[i];
    }
   
   for(int i = 0; i < size/2; i++){
       temp = arr[i];
       arr[i] = arr[size - 1 - i];
       arr[size - 1 - i] = temp;
   }
   
   return arr; 
}

void prntDat(const int *A,int size){
    for(int i = 0; i < size; i++){
        cout << A[i];
        if(i != (size - 1))
            cout << " "; 
    }
}