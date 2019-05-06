#include <iostream>
#include "StringStack.h"
using namespace std;

//************************************************
// Constructor to generate an empty stack.       *
//************************************************
StringStack::StringStack()
{
	top = NULL;
}

//************************************************
// Member function push pushes the argument onto *
// the stack.                                    *
//************************************************
void StringStack::push(string val)
{
	StackNode* newNode;

	// Allocate a new node & store Num
	newNode = new StackNode;
	newNode->value = val;

	// If there are no nodes in the list
	// make newNode the first node
	if (isEmpty())
	{
		top = newNode;
		newNode->next = NULL;
	}
	else	// Otherwise, insert NewNode before top
	{
		newNode->next = top;
		top = newNode;
	}
}

//****************************************************
// Member function pop pops the value at the top     *
// of the stack off, and copies it into the variable *
// passed as an argument.                            *
//****************************************************
void StringStack::pop(string& val)
{
	StackNode* temp;

	if (isEmpty())
	{
		cout << "The stack is empty.\n";
	}
	else	// pop value off top of stack
	{
		val = top->value;
		temp = top->next;
		delete top;
		top = temp;
	}
}

//****************************************************
// Member funciton isEmpty returns true if the stack *
// is empty, or false otherwise.                     *
//****************************************************
bool StringStack::isEmpty(void)
{
	bool status;

	if (top == NULL)
		status = true;
	else
		status = false;

	return status;
}

void StringStack::printStack()
{
	if (isEmpty()) {
		cout << "Stack is empty" << endl; 
	}
	else {
		StackNode current;
		current.next = top->next;
		current.value = top->value;
		StackNode temp; 

		do {
			cout << current.value;
			temp = current; 
			current.next = temp.next->next;
			current.value = temp.next->value;
		} while (current.value == "");
		cout << endl; 
	}
}
