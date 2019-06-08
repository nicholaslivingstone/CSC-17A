/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Prob3Table.h
 * Author: Nicholas
 *
 * Created on June 7, 2019, 1:12 AM
 */
using namespace std;

#ifndef PROB3TABLE_H
#define PROB3TABLE_H

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
		Prob3Table(string _file,int _rows, int _cols){
                    rows = _rows;
                    cols = _cols;
                    table = new T*[rows];
                    for(int i = 0; i < rows; i++){
                        table[i] = new T[cols];
                    }
                }               
		~Prob3Table(){delete [] table;delete [] rowSum;delete [] colSum;};
		const T *getTable(void){return table;};
		const T *getRowSum(void){return rowSum;};
		const T *getColSum(void){return colSum;};
		T getGrandTotal(void){return grandTotal;};
};



#endif /* PROB3TABLE_H */
