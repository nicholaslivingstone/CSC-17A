/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StringStack.h
 * Author: Nicholas
 *
 * Created on May 5, 2019, 10:35 PM
 */

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


