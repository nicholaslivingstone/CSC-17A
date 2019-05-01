/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Nicholas
 *
 * Created on April 30, 2019, 3:12 PM
 */

#include <cstdlib>
#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

struct Prime{
	unsigned char prime;
	unsigned char power;
};

struct Primes{
	Prime *prime;
	unsigned char nPrimes;
};

void prntPrm(Primes *);
Primes *factor(int);

int main(int argc, char** argv) {
    
    int input; 
    Primes * primeFactors = nullptr; 
    
    cout << "Enter an integer: "; 
    cin >> input; 
    
    int n = input; 
    
    primeFactors = factor(n);
    cout << n << " = "; 
    prntPrm(primeFactors);
    
    return 0;
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

