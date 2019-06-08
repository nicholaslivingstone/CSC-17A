#pragma once

using namespace std;

template<class T>
class Prob3Table
{
protected:
	int rows;                                 //Number of rows in the table
	int cols;                                 //Number of cols in the table
	T* rowSum;                                //RowSum array
	T* colSum;                                //ColSum array
	T* table;                                 //Table array
	T grandTotal;                             //Grand total
	void calcTable(void);                     //Calculate all the sums
public:
	Prob3Table(string, int, int) {
		T* table = new T[int];
	}
	//Constructor then Destructor
	~Prob3Table() { delete[] table; delete[] rowSum; delete[] colSum; };
	const T* getTable(void) { return table; };
	const T* getRowSum(void) { return rowSum; };
	const T* getColSum(void) { return colSum; };
	T getGrandTotal(void) { return grandTotal; };
};

template<class T>
inline void Prob3Table<T>::calcTable(void)
{
}

