#ifndef STRINGSTACK_H
#define STRINGSTACK_H

#include <string>
using namespace std;

class StringStack
{
private:
	struct StackNode {
		string value; 
		StackNode* next; 
	};

	StackNode* top; 

public:
	StringStack();

	//stack operations
	void push(string);
	void pop(string&);
	bool isEmpty();
	void printStack();
};
#endif

