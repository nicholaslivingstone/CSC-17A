#pragma once
#include "Prob3Table.h"
template<class T>
class Prob3TableInherited :public Prob3Table<T>
{
protected:
	T* augTable;                                  //Augmented Table with sums
public:
	Prob3TableInherited(string, int, int);          //Constructor
	~Prob3TableInherited() { delete[] augTable; };  //Destructor
	const T* getAugTable(void) { return augTable; };
};


