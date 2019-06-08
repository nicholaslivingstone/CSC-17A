/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Prob2TableInherited.h
 * Author: Nicholas
 *
 * Created on June 7, 2019, 10:25 PM
 */
#include <string>

#ifndef PROB2TABLEINHERITED_H
#define PROB2TABLEINHERITED_H

using namespace std;

template<class T>
class Prob3TableInherited:public Prob3Table<T>
{
	protected:
		T *augTable;                                  //Augmented Table with sums
	public:
                Prob3TableInherited(){ augTable = nullptr;};
		Prob3TableInherited(string,int,int);          //Constructor
		~Prob3TableInherited(){delete [] augTable;};  //Destructor
		const T *getAugTable(void){return augTable;}; 
};

template<class T>
Prob3TableInherited<T>::Prob3TableInherited(string _file,int _rows,int _cols) : Prob3Table<T>::Prob3Table(_file, _rows, _cols){
    this->calcTable();
    augTable = new T[(this->rows+1) * (this->cols + 1)];
    
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            augTable[i * (this->cols + 1) + j] = this->table[i * this->cols + j];
        }
    }
    
    for(int i = 0; i < this->rows; i++){
        augTable[i * (this->cols + 1) + (this->cols)] = this->rowSum[i];
    }
   
    for(int i = 0; i < this->cols; i++){
       augTable[(this->rows) * (this->cols + 1) + i] = this->colSum[i];
    }
    augTable[this->rows * (this->cols + 1) + this->cols] = this->grandTotal;
}

#endif /* PROB2TABLEINHERITED_H */

