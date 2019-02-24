/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: nick
 *
 * Created on February 23, 2019, 2:32 PM
 */

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int bubbleSort(int [], int);
int selectionSort(int [], int);


int main(int argc, char** argv) {
    
    
    
    srand(time(0));
    
    int A[20];
    int B[20];
    

    for (int i = 0; i < 20; i++){
        A[i] = rand() % 1000;
        B[i] = A[i];
    }
    
    cout << "Array to be sorted: " << endl; 
    for (int i = 0; i < 20; i++){
        cout << A[i] << endl;
    }
    
    
    
    cout << "Bubble sort swap count: " << bubbleSort(A, 20) << endl;
    cout << "Selection sort swap count: " << selectionSort(B, 20) << endl; 
    
    for (int i = 0; i < 20; i++){
        cout << A[i] << endl;
    }
    
    
    return 0;
}

int bubbleSort(int array[], int size){
    
    bool swap = false; 
    int temp, swapCount = 0;
    do{
        swap = false;
        for (int i = 0; i < (size - 1); i ++){
            if (array[i] > array[i+1]){
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swap = true;
                swapCount++;
            }
        }
    }while(swap);
    
    return swapCount; 
}

 int selectionSort(int array[], int size){
    int start, index, value, swapCount = 0; 
    
    for (start = 0; start < size - 1; start++){
        index = start;
        value = array[start];
        for (int i = start + 1; i < size; i++){
            if(array[i] < value){
                value = array[i];
                index = i;
                swapCount++; 
            }
        }
        array[index] = array[start];
        array[start] = value; 
    }
    
    return swapCount; 
}



