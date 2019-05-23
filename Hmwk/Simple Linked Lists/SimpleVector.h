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
	struct Node {
		T value;
		Node* next;
	};

	int size; 
	Node* head; 
	Node* tail; 
	
	T getRand();
public:
	// Constructor
	SimpleVector() { size = 0; head = tail = NULL; }	//default
	SimpleVector(int);	//specifies the size

	
	SimpleVector(const SimpleVector&);// Copy constructor declaration
	~SimpleVector();	//destructor

	// Accessor to return the array size
	int getSize() const { return size; }

	// Accessor to return a specific element
	T getElementAt(int position);

	// Overloaded [] operator declaration
	T& operator[](const int&);

	/*void put(T, int); 
	void addRand(int);
	void print();
	void push(T);
	bool isEmpty(); */
	
	//append functions
	void addFirst();	//overloaded blank parameter adds a random element
	void addFirst(T);	
	void addLast();
	void addLast(T); 

	//remove functions
	void removeFirst(); 
	void removeLast();
};

//get random number/element
template<class T>
inline T SimpleVector<T>::getRand()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<float> range(0, 100);
	return (T) range(gen);
}

template<class T>
inline SimpleVector<T>::SimpleVector(int _s){
	if (_s == 1) {
		head = tail = new Node;
		head->value = getRand(); 
		head->next = NULL;
	}
}

#endif