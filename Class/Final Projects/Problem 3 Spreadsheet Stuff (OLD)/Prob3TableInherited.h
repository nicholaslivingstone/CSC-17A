/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Prob3TableInherited.h
 * Author: Nicholas
 *
 * Created on June 7, 2019, 1:12 AM
 */
using namespace std;

#include "Prob3Table.h"

#ifndef PROB3TABLEINHERITED_H
#define PROB3TABLEINHERITED_H

template<class T>
class Prob3TableInherited:public Prob3Table<T>
{
	protected:
		T *augTable;                                  //Augmented Table with sums
	public:
		Prob3TableInherited(string _file,int _rows,int _cols) : Prob3Table(_file, _rows, _cols){
                    augTable = new T*[rows + 1];
                    for(int i = 0; i < rows + 1; i++){
                        table[i] = new T[cols + 1];
                    }
                    
                    T rowTot = 0, colTot = 0;
                    
                    for(int i = 0; i < rows; i++){
                        for(int j = 0; j < cols; j++){
                            rowTot += table[i][j]; 
                        }
                    }
                };          
		~Prob3TableInherited(){delete [] augTable;};  //Destructor
		const T *getAugTable(void){return augTable;}; 
};

#endif /* PROB3TABLEINHERITED_H */
