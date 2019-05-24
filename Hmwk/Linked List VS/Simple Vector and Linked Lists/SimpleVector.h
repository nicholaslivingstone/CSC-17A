// SimpleVector class template
#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H
#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function
#include <random>
#include <ctime>
using namespace std;

template <class T>
class SimpleVector
{



private:
	T* aptr;          // To point to the allocated array
	int arraySize;    // Number of elements in the array
	void memError();  // Handles memory allocation errors
	void subError();  // Handles subscripts out of range

public:
	// Default constructor
	SimpleVector()
	{
		aptr = 0; arraySize = 0;
	}

	// Constructor declaration
	SimpleVector(int);

	// Copy constructor declaration
	SimpleVector(const SimpleVector&);

	// Destructor declaration
	~SimpleVector();

	// Accessor to return the array size
	int size() const
	{
		return arraySize;
	}

	// Accessor to return a specific element
	T getElementAt(int position);

	// Overloaded [] operator declaration
	T& operator[](const int&);

	void put(T, int); 
	void addRand(int);
	void print();
	void push(T); 
	T getRand(); 
	T pull(); 

};

//***********************************************************
// Constructor for SimpleVector class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************

template <class T>
SimpleVector<T>::SimpleVector(int s)
{
	arraySize = s;
	// Allocate memory for the array.
	try
	{
		aptr = new T[s];
	}
	catch (bad_alloc)
	{
		memError();
	}

	// Initialize the array.
	for (int count = 0; count < arraySize; count++)
		* (aptr + count) = 0;
}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector & obj)
{
	// Copy the array size.
	arraySize = obj.arraySize;

	// Allocate memory for the array.
	aptr = new T[arraySize];
	if (aptr == 0)
		memError();

	// Copy the elements of obj's array.
	for (int count = 0; count < arraySize; count++)
		* (aptr + count) = *(obj.aptr + count);
}

//**************************************
// Destructor for SimpleVector class.  *
//**************************************

template <class T>
SimpleVector<T>::~SimpleVector()
{
	if (arraySize > 0)
		delete[] aptr;
}

//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void SimpleVector<T>::memError()
{
	cout << "ERROR:Cannot allocate memory.\n";
	exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void SimpleVector<T>::subError()
{
	cout << "ERROR: Subscript out of range.\n";
	exit(EXIT_FAILURE);
}

//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the sub-   *
// cript in the array.                                  *
//*******************************************************

template <class T>
T SimpleVector<T>::getElementAt(int sub)
{
	if (sub < 0 || sub >= arraySize)
		subError();
	return aptr[sub];
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

template <class T>
T& SimpleVector<T>::operator[](const int& sub)
{
	if (sub < 0 || sub >= arraySize)
		subError();
	return aptr[sub];
}
#endif

//Push an element onto the vector at a specific index
template <class T>
void SimpleVector<T>::put(T element, int sub) {
	* (aptr + sub) = element;
}

//add a random element to the vector; 
template <class T>
void SimpleVector<T>::addRand(int sub) {
	
	put(getRand(), sub);
}

template <class T>
void SimpleVector<T>::print() {
	for (int i = 0; i < arraySize; i++) {
		cout << this->getElementAt(i) << endl; 
	}
}

//adds element to end of list
template<class T>
inline void SimpleVector<T>::push(T element) 
{
	T* tmpPtr = new T[arraySize + 1];
	for(int i = 0; i < arraySize; i++) {
		tmpPtr[i] = aptr[i];
	}
	aptr = tmpPtr;
	aptr[arraySize] = element; 
	arraySize++;
}


template<class T>
inline T SimpleVector<T>::getRand()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<float> range(0, 100);
	return (T) range(gen);
}

//remove/return last element
template<class T>
inline T SimpleVector<T>::pull()
{
	if (arraySize == 0) {
		cout << "Array has no elements, cannot pull" << endl; 
		return NULL; 
	}
	T* tmpPtr = new T[arraySize - 1];
	for (int i = 0; i < arraySize - 1; i++) {
		tmpPtr[i] = aptr[i];
	}
	T element = aptr[arraySize - 1]; 
	aptr = tmpPtr;
	arraySize--;
	return element;
}


