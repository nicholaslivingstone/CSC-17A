/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Nicholas
 *
 * Created on April 29, 2019, 3:18 PM
 */

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class NumArr{
private:
    float *arr = nullptr; 
    int elements = 0; 
public:
    
    NumArr(int i){
        elements = i; 
        arr = new float[i];
    }
    
    ~NumArr(){
        cout << "Destructor of object running\n";
        elements = 0;
        delete [] arr;
    }
    
    void setNum(int i, float num){
        if (elements == 0){
            cout << "Error array not initialized\n";
            return; 
        }
        else{
            arr[i] = num; 
        }
    }
    
    float getNum(int i){
        if (elements == 0){
            cout << "Error array not initialized\n";
            return NULL; 
        }
        else{
            return arr[i];
        }
    }
    
    float getMax(){
        if (elements == 0){
            cout << "Error array not initialized\n";
            return NULL; 
        }
        else{
            return *max_element(arr, arr + elements);
        }
    }
    
    float getMin(){
        if (elements == 0){
            cout << "Error array not initialized\n";
            return NULL; 
        }
        else{
            return *min_element(arr, arr + elements);
        }
    }
    
    float getAvg(){
        if (elements == 0){
            cout << "Error array not initialized\n";
            return NULL; 
        }
        else{
            float total; 
            for(int i = 0; i < elements; i++){
                total += arr[i];
            }
            
            return total / elements; 
        }
    }
};

int main(int argc, char** argv) {
    
    NumArr myArray(5);
    
    myArray.setNum(0, 30.0);
    myArray.setNum(1, 4.34);
    myArray.setNum(2, 423023);
    myArray.setNum(3, -55.3);
    myArray.setNum(4, 1.0);
    
    for(int i = 0; i < 5; i++){
        cout << "myArray[" << i << "] = " << myArray.getNum(i) << endl;
    }
    
    cout << "Max: " << myArray.getMax() << endl;
    cout << "Min: " << myArray.getMin() << endl;
    cout << "Avg: " << myArray.getAvg() << endl; 
    
    return 0;
}

