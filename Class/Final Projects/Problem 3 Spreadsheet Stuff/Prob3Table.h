/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Prob3Table.h
 * Author: Nicholas
 *
 * Created on June 7, 2019, 1:53 AM
 */
#include <fstream>

#ifndef PROB3TABLE_H
#define PROB3TABLE_H\

using namespace std;

template<class T>
class Prob3Table
{
	protected:
		int rows;                                 //Number of rows in the table
		int cols;                                 //Number of cols in the table
		T *rowSum;                                //RowSum array
		T *colSum;                                //ColSum array
		T *table;                                 //Table array
		T grandTotal;                             //Grand total
		void calcTable(void);                     //Calculate all the sums
	public:
		Prob3Table(string ,int,int);               //Constructor then Destructor
		~Prob3Table(){delete [] table;delete [] rowSum;delete [] colSum;};
		const T *getTable(void){return table;};
		const T *getRowSum(void){return rowSum;};
		const T *getColSum(void){return colSum;};
		T getGrandTotal(void){return grandTotal;};
};

template<class T>
Prob3Table<T>::Prob3Table(string _file,int _rows,int _cols){
    ifstream input(_file);
    
    int x = 0, y = 0;
    this->rows = _rows;
    this->cols = _cols;
    table = new T[rows * cols];
    while(input >> table[x * cols + y]){
        if(table[x * cols + y] == '\n'){
            x++;
            y = 0;
        }
        else
            y++;
    }
    rowSum = new T[rows];
    colSum = new T[cols];
}

template<class T>
void Prob3Table<T>::calcTable(void){
    int j, i;
    for(i = 0; i < rows; i++){
        rowSum[i] = table[i * cols];
        for(j = 1; j < cols; j++){
            rowSum[i] += table[i * cols + j];
        }
    }
    
    for(int i = 0; i < cols; i++){
        colSum[i] = table[i];
        for(int j = 1; j < rows; j++){
            colSum[i] += table[j * cols + i];
        }
    }
    
    grandTotal = rowSum[0];
    for(int i = 1; i < rows; i++){
        grandTotal += rowSum[i];
    }
}

#endif /* PROB3TABLE_H */

