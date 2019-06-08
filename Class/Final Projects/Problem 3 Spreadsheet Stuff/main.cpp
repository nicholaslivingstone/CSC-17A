/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Nicholas
 *
 * Created on June 7, 2019, 1:53 AM
 */

#include <cstdlib>
#include <iostream>
#include "Prob3Table.h"
#include "Prob3TableInherited.h"


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    cout<<"Entering problem number 3"<<endl;
    int rows=5;
    int cols=6;
    Prob3TableInherited<int> tab("Problem3.txt",rows,cols);
    const int *naugT=tab.getTable();
    for(int i=0;i<rows;i++)
    {
            for(int j=0;j<cols;j++)
            {
                    cout<<naugT[i*cols+j]<<" ";
            }
            cout<<endl;
    }
    cout<<endl;
    const int *augT=tab.getAugTable();
    for(int i=0;i<=rows;i++)
    {
            for(int j=0;j<=cols;j++)
            {
                    cout<<augT[i*(cols+1)+j]<<" ";
            }
            cout<<endl;
    }
    return 0;
}

