/* 
 * File:   main.cpp
 * Author: YOUR NAME HERE
 * Created on January DATE AND TIME HERE
 * Purpose:  Cross one-side or the other
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
    unsigned short x;
    char shape;       //f-> forward b->backward x->cross
    
    //Input or initialize values Here
    cout<<"Create a numbered shape that can be sized."<<endl;
    cout<<"Input an integer number [1,50] and a character [x,b,f]."<<endl;
    cin>>x>>shape;
    
    //Draw the shape
    
    for (int i = 1; i <= x; i++){
        for (int j = 1; j <= x; j++){
            if(((shape == 'x' || shape == 'b') && j == i) || ((shape == 'x' || shape == 'f') && j == x - i + 1)){
                if (x % 2 == 0)
                    cout << j;
                else
                    cout << x - j + 1;
            }
            else
                cout << " ";
        }
        cout << endl;
    }
    
    //Exit
    return 0;
}