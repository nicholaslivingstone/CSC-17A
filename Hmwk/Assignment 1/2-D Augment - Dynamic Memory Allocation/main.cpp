/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: nick
 *
 * Created on March 16, 2019, 1:15 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

//function prototypes
int **getData(int &,int &);//Get the Matrix Data
void printDat(const int * const *,int,int);//Print the Matrix
int **augment(const int * const *,int,int);//Augment the original array
void destroy(int **,int);//Destroy the Matrix, i.e., reallocate memory


int main(int argc, char** argv) {
    int row,
        col,
        **A = nullptr,
        **Aaug= nullptr; 

    A = getData(row, col);
    Aaug = augment(A, row, col);
    printDat(A, row, col);
    cout << endl; 
    printDat(Aaug, row + 1, col + 1);
    
    destroy(A, row);

    return 0;
}

int **getData(int &row,int &col){
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

void printDat(const int * const *A,int row,int col){
    for (int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << A[i][j];
            if (j != col - 1)
                cout << " ";
        }
        if (i != row - 1)
            cout << endl; 
    }
}

int **augment(const int * const *A,int row,int col){
    int **arr = new int *[row] + 1;

    for(int i = 0; i < row + 1; i++){
        arr[i] = new int [col + 1];
    }

    for(int i = 0; i < row + 1; i++){
        for(int j = 0; j < col + 1; j++){
            (j == 0 || i == 0 ) ? arr[i][j] = 0 : arr[i][j] = A[i -1][j-1];
        }
    }

    return arr; 
}

void destroy(int **A,int row){
    for (int i = 0; i < row; i++){
        delete [] A[i];
    }

    delete [] A; 
}