#include <random>
#include "Prob1Random.h"

using namespace std; 

Prob1Random::Prob1Random(const int  _nset , char* _set)
{
	this->nset = _nset; 
	this->set = _set;
	this->freq = new int[nset];
	for (int i = 0; i < nset; i++) {
		freq[i] = 0;
	}
	numRand = 0;
}

Prob1Random::~Prob1Random(void)
{
	delete[] freq;
}

char Prob1Random::randFromSet(void)
{
	numRand++;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, nset- 1);
	int n = dis(gen);
	freq[n]++;
	return set[n];
}

int* Prob1Random::getFreq(void) const
{
	return freq;
}

char* Prob1Random::getSet(void) const
{
	return set;
}

int Prob1Random::getNumRand(void) const
{
	return numRand;
}