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
    
    switch(shape){
        case 'x':
            if ( x % 2 == 0){
                for(int i = 0; i < (x / 2); i++){
                    cout << setw(i + 1) << i + 1 << setw(x - (2 * (i + 1)) + 1) << x - i<< endl;
                    
                }
                for(int i = 0; i < (x / 2); i++){
                    cout << setw((x/2) - i) << (x / 2) - i << setw(((i + 1) * 2) - 1) << (x/2) + i + 1<< endl; 
                }
            }
            else{
                for(int i = 0; i < x/2; i++){
                    cout << setw(i + 1) << x - i << setw(x - 1 - (2*i)) << i + 1<< endl; 
                }
                
                cout << setw(x/2 + 1) << x/2 + 1 << endl;
                
                for(int i = 0; i < x/2; i++){
                    cout << setw(x/2 - i) << (x/2) + 2 + i << setw(2*(i+1)) << (x/2 - i) << endl; 
                }
            }
            
            break;
        case 'b':
            for(int i = 1; i <= x; i++){
                cout << setw(x-i) << x - i << endl;
            }
            break;
        case 'f':
            for(int i = 0; i < x; i++){
                cout << setw(x - i) << x - i << endl;
            }
    }

    
    //Exit
    return 0;
}