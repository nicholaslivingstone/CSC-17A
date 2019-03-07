/* 
 * File:   main.cpp
 * Author: Nicholas Livingstone
 * Created on March 6th, 2019 3:02 PM
 * Purpose:  Sorting an array of characters if specified correctly
 */

//System Libraries Here
#include <iostream>//cout,cin
#include <cstring> //strlen()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int  read(char []);
void sort(char [],int);
void print(const char [],int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;//Larger than needed
    char array[SIZE]; //Character array larger than needed
    int sizeIn,sizeDet;//Number of characters to be read, check against length
    
    //Input the size of the array you are sorting
    cout<<"Read in a 1 dimensional array of characters and sort"<<endl;
    cout<<"Input the array size where size <= 20"<<endl;
    cin>>sizeIn;
    
    //Now read in the array of characters and determine it's size
    cout<<"Now read the Array"<<endl;
    sizeDet=read(array);//Determine it's size
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size to sort
    if(sizeDet==sizeIn){
        sort(array,sizeIn); //Sort the array
        print(array,sizeIn);//Print the array
    }else{
        cout<<(sizeDet<sizeIn?"Input size less than specified.":
            "Input size greater than specified.")<<endl;
    }
    
    //Exit
    return 0;
}

int read(char A[]){
    //first input as a temporary string
    string temp;
    cin >> temp;
    strcpy(A, temp.c_str());  
    return strlen(temp.c_str()); 
}

//selection sort
void sort(char A[],int SIZE){
    int start, minI, minV;
    
    for (start = 0; start < (SIZE - 1); start++){
        minI = start;
        minV = A[start];
        for(int I = start + 1; I < SIZE; I++){
            if (A[I] < minV){
                minV = A[I];
                minI = I;
            }
        }
        A[minI] = A[start];
        A[start] = minV; 
    }
}

void print(const char A[],int size){
    for (int i = 0; i < size; i++){
        cout << A[i];
    }
    cout << endl; 
}