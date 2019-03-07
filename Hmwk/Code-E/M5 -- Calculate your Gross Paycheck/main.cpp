/* 
 * File:   main.cpp
 * Author: Nicholas Livingstone
 * Created on March 6th, 2:07 PM
 * Purpose:  Overtime
 */

//System Libraries Here
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    float payRate;
    unsigned short hrsWrkd, tempHrs; 
    float check = 0; 
    
    //Input or initialize values Here
    cout<<"Paycheck Calculation."<<endl;
    cout<<"Input payRate in $'s/hour and hours worked"<<endl;
    cin>>payRate>>hrsWrkd;
    
    //Calculate Paycheck
    if (hrsWrkd > 40){
        tempHrs = hrsWrkd - 40;
        check += (tempHrs) * 2 * payRate;
        hrsWrkd = 40; 
    }
    if (hrsWrkd > 20){
        tempHrs = hrsWrkd - 20;
        check += (tempHrs) * 1.5 * payRate;
        hrsWrkd = 20;
    }
    check += hrsWrkd * payRate;
    
    //Output the check
    cout << "$" << setprecision(2) << fixed << check << endl; 
    
    //Exit
    return 0;
}