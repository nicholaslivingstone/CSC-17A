/* 
 * File:   main.cpp
 * Author: Nicholas Livingstone
 * Created on March 6th, 2019 1:48 PM
 * Purpose:  Histogram
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    char nums[4];
    //Input or initialize values Here
    cout<<"Create a histogram chart."<<endl;
    cout<<"Input 4 digits as characters."<<endl;
    
    cin >> nums[3];
    cin >> nums[2];
    cin >> nums[1];
    cin >> nums[0]; 
    
    for (char c: nums){
        cout << c << " ";
        if(isdigit(c)){
            int n = c - '0';
            for (int i = 0; i < n; i++){
                cout << "*";
            }
            cout << endl;
            
        }
        else
            cout << "?" << endl; 
    }
    
    //Histogram Here

    
    //Exit
    return 0;
}