/* 
 * File:   main.cpp
 * Author Nicholas Livingstone
 * Created on March 6th, 2019 3:21 PM
 * Purpose:  Sum Rows, Sum Columns, Grand Sum of an integer array
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <iomanip> //setw(10)
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;  //Max Columns much larger than needed.

//Function Prototypes Here
void read(int [][COLMAX],int &,int &);//Prompt for size then table
void sum(const int [][COLMAX],int,int,int[][COLMAX]);//Sum rows,col,grand total
void print(const int [][COLMAX],int,int,int);//Either table can be printed

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=80;           //Max Rows much larger than needed
    int array[ROW][COLMAX]={};  //Declare original array
    int augAry[ROW][COLMAX]={}; //Actual augmented table row+1, col+1
    int row,col;                
    cout << "Input a table and output the Augment row,col and total sums.\n";
    cout << "First input the number of rows and cols. <20 for each\n";
    cout << "Now input the table.\n";
    
    //Input the original table
    read(array,row,col);
    
    //Augment the original table by the sums
    sum(array,row,col,augAry);
    
    //Output the original array
    cout<<endl<<"The Original Array"<<endl;
    print(array,row,col,10);//setw(10)
    
    //Output the augmented array
    cout<<endl<<"The Augmented Array"<<endl;
    print(augAry,row+1,col+1,10);//setw(10)
    
    //Exit
    return 0;
}

void read(int A[][COLMAX],int &ROW,int &COL){
    cin >> ROW;
    cin >> COL; 
    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++){
            cin >> A[i][j];
        }
    }
}

void sum(const int A[][COLMAX],int ROW,int COL,int Aaug[][COLMAX]){
    int sum = 0,
            gsum = 0; 
            
    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++){
            Aaug[i][j] = A[i][j];
            sum += A[i][j];
        }
        Aaug[i][COL] = sum;
        gsum += sum; 
        sum = 0; 
    }
    
    for (int i = 0; i < COL; i++){
        for (int j = 0; j < ROW; j++){
            sum += A[j][i];
        }
        Aaug[ROW][i] = sum;
        sum = 0; 
    }
    Aaug[ROW][COL] = gsum; 
}

void print(const int A[][COLMAX],int ROW,int COL,int W){
    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++){
            cout << setw(W) << A[i][j];
        }
        cout << endl; 
    }
}

