/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: nick
 *
 * Created on March 16, 2019, 12:16 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;


int **getData(int &,int &);        //Return the 2-D array and its size.
void prntDat(const int* const *,int,int);//Print the 2-D Array
void destroy(int **,int,int);       //Deallocate memory
int sum(const int * const *, int,int);    //Return the Sum

int main(int argc, char** argv) {
    int **A = nullptr,
        row, col;

    A = getData(row, col); 
    prntDat(A, row, col);
    cout << sum(A, row, col);
    destroy(A, row, col);

    return 0;
}

int **getData(int &row, int &col){
    cin >> row;
    cin >> col;

    int **arr = new int *[row];

    for(int i = 0; i < row; i++){
        arr[i] = new int [col];
    }

    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            cin >> arr[i][j];
        }
    }
    
    return arr; 
}

void prntDat(const int* const * A, int row,int col){
    for (int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << A[i][j];
            j != col - 1 ? cout << " " : cout << endl; 
        }
    }
}

void destroy(int **A,int row,int col){
    for (int i = 0; i < row; i++){
        delete [] A[i];
    }

    delete [] A; 
}

int sum(const int * const *A, int row,int col){
    int sum = 0;

    for (int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            sum += A[i][j];
        }
    }

    return sum; 
}
