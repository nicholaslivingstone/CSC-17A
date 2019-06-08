/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Nicholas
 *
 * Created on June 7, 2019, 10:13 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <random>
#include "Prob1Random.h"
#include "Prob2Sort.h"
#include "Prob3Table.h"
#include "Prob3TableInherited.h"
#include "SavingsAccount.h"
#include "Employee.h"

using namespace std;

string convert(float , int );
/*
 * 
 */
int main(int argc, char** argv) {
    int choice; 
    do{
        cout << "1. Problem #1 Random Sequence" << endl;
        cout << "2. Problem #2  (All Kinds of Sorting)" << endl;
        cout << "3. Problem #3  (Spreadsheet Stuff)" << endl;
        cout << "4. Problem #4  (Savings Account Class)" << endl;
        cout << "5. Problem #5  (Employee Class)" << endl;
        cout << "6. Problem #5 Problem #6(Conversions)" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice:";
        cin >> choice; 
        switch(choice){
            case 1:{
                int n = 5;
                char rndseq[] = { 18,33,56,79,125 };
                int ntimes = 100000;
                Prob1Random a(n, rndseq);
                for (int i = 1; i <= ntimes; i++)
                {
                        a.randFromSet();
                }
                int* x = a.getFreq();
                char* y = a.getSet();
                for (int i = 0; i < n; i++)
                {
                        cout << int(y[i]) << " occured " << x[i] << " times" << endl;
                }
                cout << "The total number of random numbers is " << a.getNumRand() << endl;
                break;}
            case 2:{
                cout << "The start of Problem 2, the sorting problem" << endl;
                Prob2Sort<char> rc;
                bool ascending = true;
                ifstream infile;
                infile.open("Problem2.txt", ios::in);
                char* ch2 = new char[10 * 16];
                char* ch2p = ch2;
                while (infile.get(*ch2)) { cout << *ch2; ch2++; }
                infile.close();
                cout << endl;
                cout << "Sorting on which column" << endl;
                int column;
                cin >> column;
                char* zc = rc.sortArray(ch2p, 10, 16, column, ascending);
                for (int i = 0; i < 10; i++)
                {
                        for (int j = 0; j < 16; j++)
                        {
                                cout << zc[i * 16 + j];
                        }
                }
                delete[]zc;
                cout << endl;
                break;}
            case 3:{
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
                break;}
            case 4:{
                random_device dev; 
                mt19937 gen(dev());
                uniform_real_distribution<> dis(-500, 500);

                SavingsAccount sa(-300);
                for(int i = 0; i < 10; i++){
                    sa.Transaction(dis(gen));
                }
                sa.toString();
                cout << "Balance after 7 years at 10% Interest = " << sa.Total(0.10f, 7) << endl;
                cout << "Balance after 7 years at 10% Interest = " << sa.TotalRecursive(0.10f, 7) << " Recursive Calculation" << endl;
                break;}
            case 5:{
                Employee Mark("Mark","Boss",215.50);
                Mark.setHoursWorked(-3);
                Mark.toString();
                Mark.CalculatePay(Mark.setHourlyRate(20.0),
                        Mark.setHoursWorked(25));
                Mark.toString();
                Mark.CalculatePay(Mark.setHourlyRate(40.0),
                        Mark.setHoursWorked(25));
                Mark.toString();
                Mark.CalculatePay(Mark.setHourlyRate(60.0),
                        Mark.setHoursWorked(25));
                Mark.toString();

                Employee Mary("Mary","VP",50.0);
                Mary.toString();
                Mary.CalculatePay(Mary.setHourlyRate(50.0),
                        Mary.setHoursWorked(40));
                Mary.toString();
                Mary.CalculatePay(Mary.setHourlyRate(50.0),
                        Mary.setHoursWorked(50));
                Mary.toString();
                Mary.CalculatePay(Mary.setHourlyRate(50.0),
                        Mary.setHoursWorked(60));
                Mary.toString();
                break;}
            case 6:{
                cout << "Binary" << endl; 
                cout << 3.75 << "  " << convert(3.75, 2) << endl;
                cout << 0.7 << "   " << convert(0.7, 2) << endl;
                cout << 89.9 << "  " << convert(89.9, 2) << endl;

                cout << "Octal" << endl; 
                cout << 3.75 << "  " << convert(3.75, 8) << endl;
                cout << 0.7 << "   " << convert(0.7, 8) << endl;
                cout << 89.9 << "  " << convert(89.9, 8) << endl;

                cout << "Hexadecimal" << endl; 
                cout << 3.75 << "  " << convert(3.75, 16) << endl;
                cout << 0.7 << "   " << convert(0.7, 16) << endl;
                cout << 89.9 << "  " << convert(89.9, 16) << endl;

                cout << "Float Point" << endl;
                printf("%a\n", 3.75);
                printf("%a\n", 0.7);
                printf("%a\n", 89.9);
                break;}
        }
    }while(choice);
    return 0;
}

string convert(float _num, int _base){
    char hex[] = {'0', '1', '2', '3', '4', '5', '6', '7' , '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    string bin = "";
    int intNum = _num; 
    float fract = _num - intNum; 
    while(intNum){
        if(_base == 16)
            bin = hex[(intNum % _base)] + bin;
        else
            bin += (intNum % _base) + '0';
        intNum /= _base;
    }
    
    if(fract != 0){
        bin += '.';
        while(fract){
            fract *= _base;
            int intPart = fract; 
            if(_base == 16)
                bin += hex[intPart];
            else
                bin += intPart + '0';
            fract -= intPart;
        }
    }
    
    return bin;
}

