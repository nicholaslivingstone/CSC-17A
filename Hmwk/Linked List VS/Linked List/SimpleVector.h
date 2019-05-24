#pragma once
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
		T data; 
		Node* next; 
	};
	int size; 
	Node* head; 
	Node* tail; 
	T getRand(); 
public:
	SimpleVector() { size = 0; head = tail = NULL; }
	SimpleVector(int);

	bool isEmpty(); 
	void addLast(); 
	void addLast(T); 
	void addFront();
	void addFront(T); 
	void removeLast(); 
	void removeFront(); 

	void print(); 
};

template<class T>
inline SimpleVector<T>::SimpleVector(int _s)
{
	if (_s == 0) {
		SimpleVector(); 
	}
	else if (_s == 1) {
		head = tail = new Node; 
		head->next = NULL; 
	}
	else {
		for(int i = 0; i < _s; i++){
			addLast(); 
		}
	}
}

template<class T>
inline bool SimpleVector<T>::isEmpty()
{
	if (head == NULL) {
		return true;
	}
	else
		return false; 
}

template<class T>
inline void SimpleVector<T>::addLast()
{
	addLast(getRand());
}

template<class T>
inline void SimpleVector<T>::addLast(T _element)
{
	size++; 
	Node* tmp = new Node;
	tmp->data = _element;
	tmp->next = NULL;
	if (head == NULL) {
		head = tmp;
		tail = tmp;
		tmp = NULL;
	}
	else {
		tail->next = tmp;
		tail = tmp;
	}
}

template<class T>
inline void SimpleVector<T>::addFront()
{
	addFront(getRand());
}

template<class T>
inline void SimpleVector<T>::addFront(T _element)
{
	size++; 
	Node* tmp = new Node;
	tmp->data = _element;
	tmp->next = NULL;
	if (head == NULL) {
		head = tmp;
		tail = tmp;
		tmp = NULL;
	}
	else {
		tmp->next = head;
		head = tmp; 
	}
}

template<class T>
inline void SimpleVector<T>::removeLast()
{
	if (head == NULL) {
		cout << "Cannot delete, list is empty...\n"; 
		return; 
	}
	if (head->next == NULL) {
		head = NULL; 
		size--; 
		return; 
	}
	Node* tmp = head; 
	
	while (tmp->next->next != NULL) {
		tmp = tmp->next; 
	}
	delete (tmp->next);
	tmp->next = NULL; 
	tail = tmp; 
	size--;
}

template<class T>
inline void SimpleVector<T>::removeFront()
{
	if (head == NULL) {
		cout << "Cannot delete, list is empty...\n";
		return;
	}
	if (head->next == NULL) {
		head = NULL;
		size--; 
		return;
	}
	
	Node* tmp = head;
	head = tmp->next;
	size--; 
}




template<class T>
inline void SimpleVector<T>::print()
{
	if (isEmpty()) {
		cout << "Cannot print. List is empty\n";
	}
	else {
		Node* tmp = new Node;
		tmp = head;
		while (tmp != NULL) {
			cout << tmp->data << " ";
			tmp = tmp->next;
		}
		cout << endl;
	}
}



template<class T>
inline T SimpleVector<T>::getRand(){
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<float> range(0, 100);
	return (T)range(gen);
}