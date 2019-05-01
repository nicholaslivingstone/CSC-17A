/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Nicholas
 *
 * Created on April 30, 2019, 5:26 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

#include "Array.h"
#include "Stats.h"

struct Customer{
    string name,
        address;
    int accountNum; 
    double balance,
        checkTotal,
        depositTotal;
};

struct EmployeeInfo{
    string name;
    double hrsWrkd,
        payRate,
        grossPay;
};

struct Prime{
	unsigned char prime;
	unsigned char power;
};

struct Primes{
	Prime *prime;
	unsigned char nPrimes;
};

const vector<std::string> EnglishWords[3] = 
{
    {
        "zero", 
        "one", 
        "two", 
        "three", 
        "four", 
        "five", 
        "six", 
        "seven", 
        "eight", 
        "nine",
        "ten",
        "eleven",
        "twelve", 
        "thirteen", 
        "fourteen", 
        "fifteen", 
        "sixteen", 
        "seventeen", 
        "eighteen", 
        "nineteen" 
    },
    {
         "", 
         "", 
         "twenty",
         "thirty",
         "forty", 
         "fifty", 
         "sixty", 
         "seventy", 
         "eighty", 
         "ninety",
         "hundred"
    },
    {
        "", 
        " thousand", 
        " million", 
        " billion", 
        " trillion"
    },
};

void menu();
void prblm1();
void prblm2();
void prblm3();
void prblm4();
void prblm5();
void prblm6();
void prblm7();
void calcBalance(Customer *);
void printPayCheck(EmployeeInfo);
void calcGrossPay(EmployeeInfo &);
string convertEnglish(size_t);
string toEnglish(size_t);
Array *fillAry(int,int);        //Fill an array and put into a structure
void prntAry(const Array *,int);//Print the array 
int *copy(const int *,int);     //Copy the array
void mrkSort(int *,int);        //Sort an array
void prtStat(const Stats *);    //Print the structure
void rcvrMem(Array *);          //Recover memory from the Array Structure
void rcvrMem(Stats *);          //Recover memory from Statistics Structure
Stats *stat(const Array *);
void encrypt(int *);
void decrypt(int *);
void prntPrm(Primes *);
Primes *factor(int);


//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    char choice;
    
    //Loop and Display menu
    do{
        menu();
        cin>>choice;

        //Process/Map inputs to outputs
        switch(choice){
            case '1':{prblm1();break;}
            case '2':{prblm2();break;}
            case '3':{prblm3();break;}
            case '4':{prblm4();break;}
            case '5':{prblm5();break;}
            case '6':{prblm6();break;}
            case '7':{prblm7();break;}
            default: cout<<"Exiting Menu"<<endl;
        }
    }while(choice>='1'&&choice<='7');
    
    //Exit stage right!
    return 0;
}


void menu(){
    cout<<endl<<"Choose from the following Menu"<<endl;
    cout<<"Type 1 Problem 1"<<endl;
    cout<<"Type 2 Problem 2"<<endl;
    cout<<"Type 3 Problem 3"<<endl;
    cout<<"Type 4 Problem 4"<<endl;
    cout<<"Type 5 Problem 5"<<endl; 
    cout<<"Type 6 Problem 6"<<endl;
    cout<<"Type 7 Problem 7"<<endl;
    cout<<"Enter anything else to exit"<<endl<<endl;
    
}


void prblm1(){
    Customer *cust = nullptr;
    cust = new Customer; 
    
    //get name
    cin.ignore();
    cout << "Enter name: ";
    getline(cin, cust->name);
    //get Address
    cout << "Enter Address: ";
    getline(cin, cust->address);
    //get Account number
    bool error = false; 
    do{
        error = false;
        cout << "Enter account number: ";
        cin >> cust->accountNum;
        //validate the length of the number
        int n =0; 
        int num = cust->accountNum;
        while(num){
            num /= 10;
            n++;
        }
        if (n != 5){
            cout << "Error. Invalid account number entered";
            error = true;
        }
    }while(error);
    //get Balance
    cout << "Enter balance from the beginning of the month: $";
    cin >> cust->balance;
    //get checks written
    cust->checkTotal = 0; 
    double check;
    int num = 0; 
    cout << "Enter value of all checks written, when finished enter 0\n";
    do{
        num++;
        cout << "Check #" << num << ": $";
        cin >> check;
        cust->checkTotal += check; 
    }while(check);
    //get Deposits
    cust->depositTotal = 0; 
    double deposit;
    num = 0; 
    cout << "Enter value of all deposits, when finished enter 0\n";
    do{
        num++;
        cout << "Deposit #" << num << ": $";
        cin >> deposit;
        cust->depositTotal += deposit; 
    }while(deposit);
    //display new balance
    calcBalance(cust);
    cout << cust->name << ", Your new balance is $" << fixed << setprecision(2) << cust->balance << endl;
    cout << "Address: " << cust->address << endl;
    cout << "Account Number: " << cust->accountNum;
}

void calcBalance(Customer *cust){
    cust->balance = cust->balance + cust->depositTotal - cust->checkTotal;
    if (cust->balance < 0){
        cout << "You've overdrawn your account, your account will be debited $20\n";
        cust->balance -= 20.0; 
    }
}

void prblm2(){
    EmployeeInfo *employee = nullptr; 
    int numEmployees;
    
    cout << "How many employees?:";
    cin >> numEmployees;
    employee = new EmployeeInfo[numEmployees];
    
    for(int i = 0; i < numEmployees; i++){
        //getName
        cin.ignore();
        cout << "Employee name:";
        getline(cin, employee[i].name);
        
        //get hours worked
        cout << "Hours worked:";
        cin >> employee[i].hrsWrkd;
        if(employee[i].hrsWrkd < 0){
            cout << "Error invalid number of hours entered, exiting program...";
            delete [] employee; 
            return;
        }
        
        //get Pay rate
        cout << "Pay Rate:$";
        cin >> employee[i].payRate;
        if(employee[i].payRate < 0){
            cout << "Error invalid pay rate entered, exiting program...";
            delete [] employee; 
            return;
        }
        
        //
        calcGrossPay(employee[i]);
        printPayCheck(employee[i]);
    }
    
    delete [] employee;
}

void calcGrossPay(EmployeeInfo &emp){
    emp.grossPay = 0; 
    double tempHrs = emp.hrsWrkd; 
    if(tempHrs > 50){
        emp.grossPay += ((tempHrs - 50) * emp.payRate * 3);
        tempHrs = 50; 
    }
    if(tempHrs > 40){
        emp.grossPay += ((tempHrs - 40) * emp.payRate * 2);
        tempHrs = 40; 
    }
    emp.grossPay +=(tempHrs * emp.payRate);
}

void printPayCheck(EmployeeInfo emp){
    cout << "Company\n";
    cout << "Address\n";
    cout << "Name: " << left << setw(20) << emp.name << "Amount: $" << setprecision(2) << fixed << emp.grossPay << endl;
    cout << "Amount: " << toEnglish(emp.grossPay) << " and " << toEnglish(fmod(emp.grossPay, 1L) * 100L) << " cents" << endl;
    cout << "Signature line: ___________________________\n\n";
}

string convertEnglish(size_t number){
    if (number == 0)
        return "";
    int hundreds = number / 100;
    number %= 100;   // just keep last two digits
    std::string words;

    if (hundreds) {
        words = EnglishWords[0][hundreds] 
            + " " + EnglishWords[1][10] 
            + (number ? " " : "");
    }
    if (number == 0) {
        return words;
    }
    if (number < 20) {
        return words + EnglishWords[0][number];
    }
    int tens = number / 10;
    int units = number % 10;
    if (tens) {
        words += EnglishWords[1][tens];
    }
    if (units) {
        words += (tens ? " " : "") + EnglishWords[0][units];
    }
    return words;
}

string toEnglish(size_t number){
    
    if (number == 0) 
    {
        return EnglishWords[0][number];
    }
    string words;
    for (int thousands = 0; number; ++thousands, number /= 1000)
    {
        int chunk = number % 1000;
        if (chunk) {
            words = convertEnglish(chunk) 
                + EnglishWords[2][thousands] 
                + (words.size() ? " " : "") 
                + words;
        }
    }
    return words;
}


void prblm3(){
    //Declare variables and fill
    int arySize=31;//Array Size
    int modNum=10; //Number to control the modes (digits 0 to 9 allowed)
    Array *array=fillAry(arySize,modNum);
    
    //Print the initial array
    cout<<"Original Array"<<endl;
    prntAry(array,10);
    
    //Calculate some of the statistics
    Stats *stats=stat(array);
    
    //Print the statistics
    prtStat(stats);
    
    //Recover allocated memory
    rcvrMem(array);
    rcvrMem(stats);
}

int *copy(const int *a,int n){
    //Declare and allocate an array
    //that is a c
    int *b=new int[n];
    //Fill
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    //Return the copy
    return b;
}

void prtStat(const Stats *ary){
    cout<<endl;
    cout<<"The average of the array = "<<ary->avg<<endl;
    cout<<"The median of the array  = "<<ary->median<<endl;
    cout<<"The number of modes      = "<<
            ary->mode->size<<endl;
    cout<<"The max Frequency        = "<<
            ary->modFreq<<endl;
    if(ary->mode->size==0){
        cout<<"The mode set             = {null}"<<endl;
        return;
    }
    cout<<"The mode set             = {";
    for(int i=0;i<ary->mode->size-1;i++){
        cout<<ary->mode->data[i]<<",";
    }
    cout<<ary->mode->data[ary->mode->size-1]<<"}"<<endl;
}

void mrkSort(int *array,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(array[j]<array[i]){
                int temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
}

void rcvrMem(Stats *stats){
    rcvrMem(stats->mode);
    delete stats;
}

void rcvrMem(Array *array){
    delete []array->data;
    delete array;
}

void prntAry(const Array *array,int perLine){
    //Output the array
    for(int i=0;i<array->size;i++){
        cout<<array->data[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

Array *fillAry(int n, int modNum){
    //Allocate memory
    Array *array=new Array;
    array->size=n;
    array->data=new int[array->size];
    
    //Fill the array with mod numbers
    for(int i=0;i<n;i++){
        array->data[i]=i%modNum;
    }
    
    //Exit function
    return array;
}

Stats *stat(const Array *array){
    //Non-working stub to be completed by the student
    cout<<endl<<"stat function to be completed by the student"<<endl;
    Stats *stats=new Stats;
    stats->mode=new Array;
    
    
    if(array->size <=10){
        stats->modFreq = 1; 
        stats->mode->size = 0;
        stats->mode->data = nullptr; 
        if(array->size % 2 == 0){
            stats->median = (array->data[(array->size - 1)/2] + array->data[array->size / 2]) / 2.0;
        }
        else{
            stats->median = array->data[array->size / 2];
        }
    }
    else{
        stats->modFreq = array->size / 10 + 1;
        stats->mode->size = array->size % 10;
        stats->mode->data=new int[stats->mode->size];
        for(int i = 0; i < stats->mode->size; i++){
            stats->mode->data[i] = i;
        }
        int sortedArray[array->size];
        int k = 0, n; 
        for(int i = 0; i < 10; i++){
            if (i < array->size % 10)
                n = (array->size / 10) + 1;
            else
                n = array->size / 10;
            for(int j = 0; j < n; j++){
                sortedArray[k] = i;
                k++;
            }
        }
        if(array->size % 2 == 0){
            stats->median = (sortedArray[(array->size - 1)/2] + sortedArray[array->size / 2]) / 2.0;
        }
        else{
            stats->median = sortedArray[array->size / 2];
        }
    }
    
    //calculate average
    float total = 0;
    for(int i = 0; i < array->size; i++){
        total += array->data[i];
    }
    stats->avg = total / array->size;
    
    return stats;
}


void prblm4(){
    int choice;
    
    cout << "Options\n";
    cout << "-------\n";
    cout << "1.Encrypt\n";
    cout << "2.Decrypt\n";
    do{
        cout << "Enter 1 or 2: "; 
        cin >> choice; 
        if (choice != 1 && choice != 2){
            cout << "Error invalid option selected\n";
        }
    }while(choice != 1 && choice != 2);
    
    char * charData = new char[4];
    int * data = new int[4];
    bool error = false; 
    
    
    do{
        error = false; 
        cout << "Enter 4 digit data: ";
        cin >> charData; 
        for(int i = 0; i < 4; i++){
            if(charData[i] > '7' || charData[i] < '0'){
                cout << "Error: Invalid digit entered\n";
                error = true;
                i = 4;
            }
        }
    }while(error);
    
    for(int i = 0; i < 4; i++){
        data[i] = charData[i] - '0';
    }
    delete [] charData;
    
    int temp; 
    temp = data[0];
    data[0] = data[2];
    data[2] = temp;
    temp = data[1];
    data[1] = data[3];
    data[3] = temp; 
    
    if(choice == 1){
        encrypt(data); 
    }
    else{
        decrypt(data);
    }
    
    delete [] data;
}

void encrypt(int *data){
    cout << "Encrypted data: ";
    for(int i = 0; i < 4; i++){
        data[i] = (data[i] + 5) % 8;
        cout << data[i];
    }
}

void decrypt(int *data){
    cout << "Decrypted data: ";
    for(int i = 0; i < 4; i++){
        if(data[i] < 5)
            data[i] += 3;
        else
            data[i] -= 5;
        cout << data[i];
    }
}

void prblm5(){
    short SHORT = 7 * 6 * 5 * 4 * 3 * 2 * 1;
    unsigned short unSHORT = 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1;
    int INT = 12 * 11 * 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1;
    unsigned int unINT = 12 * 11 * 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1;
    long LONG = 12 * 11 * 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1;
    unsigned long unLONG = 12 * 11 * 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1;
    float FLOAT = 12 * 11 * 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1;
    double DOUBLE =  12 * 11 * 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1;
    long double longDOUBLE = 12 * 11 * 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1;
    
    
    
    cout << "Byte: 5! = 120" << endl;
    cout << "Short: 7! = " << SHORT << endl;
    cout << "Unsigned Short: 8! = " << unSHORT<< endl;
    cout << "Integer: 12! = " << INT << endl;
    cout << "Unsigned Integer: 12! = " << unINT << endl;
    cout << "Long: 12! = " << LONG << endl;
    cout << "Unsigned Long: 12! = " << unLONG << endl;
    cout << "Float: 12! = " << FLOAT << endl;
    cout << "Double: 12! = " << DOUBLE << endl;
    cout << "Long Double: 12! = " << longDOUBLE;
}

void prblm6(){
    cout << left << setw(13) << "Number"  << setw(13) << "Binary"  << setw(13) << "Octal" << setw(13) << "Hex" << setw(13) << "Floating" << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << setw(13) << 2.875 << setw(13) << 10.111 << setw(13) << 2.7 << setw(13) << "2.E" << setw(13) << 40000007 << endl;
    cout << setw(13) << 0.1796875 << setw(13) << 0.0010111 << setw(13) << 0.134 << setw(13) << "0.2E" << setw(13) << "00000017" << endl;
    cout << setw(13) << "-2.875" << setw(13) << "-10.111" << setw(13) << "-2.7" << setw(13) << "-2.E" << setw(13) << "C0000007" << endl;
    cout << setw(13) << "-0.1796875" << setw(13) << "-0.0010111" << setw(13) << "-0.134" << setw(13) << "-0.2E" << setw(13) << "80000017" << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << setw(13) << "Floating"  << setw(35) << "Binary" << setw(13) << "Number" << endl;
    cout << setw(13) << "59999901"  << setw(35) << "01011001100110011001100100000001" << setw(13) << "5.404237626343424e15" << endl;
    cout << setw(13) << "59999902"  << setw(35) << "01011001100110011001100100000010" << setw(13) << "5.404238163214336e15" << endl;
    cout << setw(13) << "A66667FE"  << setw(35) << "10100110011001100110011111111110" << setw(13) << "-7.99382155894444012406152566541e-16" << endl;
}

void prblm7(){
    int input; 
    Primes * primeFactors = nullptr; 
    
    cout << "Enter an integer: "; 
    cin >> input; 
    
    int n = input; 
    
    primeFactors = factor(n);
    cout << n << " = "; 
    prntPrm(primeFactors);
}

void prntPrm(Primes * prms){
    for(int i = 0; i < prms->nPrimes - '0'; i++){
        cout << prms->prime[i].prime << '^' << prms->prime[i].power;
        if(i != prms->nPrimes - '1'){
            cout << " * ";
        }
    }
}

Primes *factor(int n){
    Primes * primeFactors;
    primeFactors->prime = new Prime[50]; //more than enough
    primeFactors->nPrimes = '0';
    int primeCount = 0; 
    queue<int> ints;   
    queue<int> primes; 
    int p, first;
    
    for(int i = 2; i < n; i++){
        ints.push(i);
    }
    
    do{
        p = ints.front();
        ints.pop();
        primes.push(p);
        first = ints.front();
        do{
            if(ints.front() % p == 0){
                ints.pop();
            }
            else{
                ints.push(ints.front());
                ints.pop(); 
            }
        }while(ints.front() != first);
    }while(p < sqrt(n));
    
    bool newNum = true; 
    int count;
    do{
        if(n % primes.front() == 0){
            n /= primes.front();
            if(newNum){
                primeFactors->prime[primeFactors->nPrimes - '0'].prime = primes.front() + '0';  //add prime number to list of primes
                count = 1;
                primeFactors->nPrimes++;    //increase number of primes
                newNum = false;             //change it to no longer a new number
            }
            else{
                primeFactors->prime[primeFactors->nPrimes - '0'].power + '1'; 
                count++;
                
            }
            primeFactors->prime[primeFactors->nPrimes - '1'].power = count + '0';
        }else{
            newNum = true; 
            primes.pop();
        }
    }while(n != 1);
    
    return primeFactors;
}