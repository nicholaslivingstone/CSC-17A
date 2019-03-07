/* 
 * File:   main.cpp
 * Author: Nicholas Livingstone
 * Created on March 6th, 2019 3:05
 * Purpose:  Summing, Finding the Max and Min of an integer array
 * Note:  Look at the output for the format for print
 */

//System Libraries Here
#include <iostream>//cin,cout
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables

//Function Prototypes Here
void read(int [],int);
int  stat(const int [],int,int &,int &);
void print(const int [],int,int,int,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;
    int array[SIZE];
    int sizeIn,sum,min,max;
    
    //Input the size of the array you are sorting
    cout<<"Read in a 1 dimensional array of integers find sum/min/max"<<endl;
    cout<<"Input the array size where size <= 20"<<endl;
    cin>>sizeIn;
    
    //Now read in the array of integers
    cout<<"Now read the Array"<<endl;
    read(array,sizeIn);//Read in the array of integers
    
    //Find the sum, max, and min
    sum=stat(array,sizeIn,max,min);//Output the sum, max and min
    
    //Print the results
    print(array,sizeIn,sum,max,min);//print the array, sum, max and min

    //Exit
    return 0;
}

void read(int A[],int SIZE){
    for (int i = 0; i < SIZE; i++){
        cin >> A[i];
    }
}

int  stat(const int A[],int SIZE,int &MAX,int &MIN){
    MAX = A[0];
    MIN = A[0];
    int sum = A[0];
    for(int i = 1; i < SIZE; i++){
        if(A[i] > MAX)
            MAX = A[i];
        if(A[i] < MIN)
            MIN = A[i];
        sum += A[i];
    }
    return sum; 
}

void print(const int A[],int SIZE,int SUM,int MAX,int MIN){
    for (int i = 0; i < SIZE; i++){
        cout << "a[" << i << "] = " << A[i] << endl;
    }
    cout << "Min  = " << MIN << endl; 
    cout << "Max  = " << MAX << endl; 
    cout << "Sum  = " << SUM << endl; 

}
