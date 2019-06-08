/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Prob1Random.h
 * Author: Nicholas
 *
 * Created on June 7, 2019, 10:16 PM
 */

#ifndef PROB1RANDOM_H
#define PROB1RANDOM_H

class Prob1Random
{
private:
	char* set;      //The set of numbers to draw random numbers from
	int  nset;     //The number of variables in the sequence
	int* freq;     //Frequency of all the random numbers returned
	int   numRand;  //The total number of times the random number function is called
public:
	Prob1Random(const int, char*);     //Constructor
	~Prob1Random(void);                       //Destructor
	char randFromSet(void);                   //Returns a random number from the set
	int* getFreq(void) const;                 //Returns the frequency histogram
	char* getSet(void) const;                 //Returns the set used
	int getNumRand(void) const;               //Gets the number of times randFromSet has been called
};

#endif /* PROB1RANDOM_H */

