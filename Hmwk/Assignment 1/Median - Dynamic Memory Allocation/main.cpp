/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: nick
 *
 * Created on March 13, 2019, 1:28 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

int *getData(int &);         //Return the array size and the array
void prntDat(int*,int);    //Print the integer array
float *median(int*,int);  //Fill the median Array with the Float array size, the median, and the integer array data
void prntMed(float*);     //Print the median Array

/*
 * 
 */
int main(int argc, char** argv) {

    int size, *array;
    float *fArray;
    
    array = getData(size); 
    fArray = new float [size + 2];
    
    
    
    prntDat(array, size); 
    
    fArray = median(array, size);
    
    prntMed(fArray);
    
    delete [] array;
    delete [] fArray;
    
    return 0;
}

int *getData(int &size){
    int *A = nullptr; 
    cin >> size; 

    A = new int [size];

    for(int i = 0; i < size; i++){
        cin >> A[i];
    }

    return A; 
}

void prntDat(int *A,int size){
    for (int i = 0; i < size; i++){
        cout << A[i];
        i == size - 1 ? cout << endl : cout << " ";
    }
}

float *median(int *A,int size){
    float *arr = new float [size + 2];
    float *sortA= new float [size];
    float median; 
    
    //copy contents of int *A to float sortA
    for(int i = 0; i < size; i++){
        sortA[i] = A[i];
    }
    
    
    //sort the sort array
    int start, minI, min; 
    
    for(start = 0; start < (size - 1); start++){
        minI = start;
        min = sortA[start];
        for(int i = start + 1; i < size; i++){
            if (sortA[i] < min){
                min = sortA[i];
                minI = i;
            }
        }
        sortA[minI] = sortA[start];
        sortA[start] = min; 
    }
    
    //calculate the median
    if (size % 2 == 0){
        median = (sortA[size/2] + sortA[size/2 - 1]) / 2.00;
    }
    else{
        median = sortA[size/2];
    }
    
    delete [] sortA; 
    
    //set size and median to first two elements of new array
    *arr = size + 2;
    *(arr + 1) = median;
    
    for(int i = 0; i < size; i++){
        arr[i + 2] = A[i];
    }

    return arr;
}

void prntMed(float *A){
    cout << A[0] << " "; 
    for (int i = 1; i < A[0]; i++){
        cout << setprecision(2) << fixed << A[i];
        if(i != A[0] - 1)
            cout << " ";
    }
}