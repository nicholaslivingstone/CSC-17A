// Problem 1 Random.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Prob1Random.h"

using namespace std;

int main()
{
	int n = 5;
	char rndseq[] = { 18,33,56,79,125 };
	int ntimes = 100000;
	Prob1Random a(n, rndseq);
	for (int i = 1; i <= ntimes; i++)
	{
		a.randFromSet();
	}
	int* x = a.getFreq();
	char* y = a.getSet();
	for (int i = 0; i < n; i++)
	{
		cout << int(y[i]) << " occured " << x[i] << " times" << endl;
	}
	cout << "The total number of random numbers is " << a.getNumRand() << endl;
}
