#pragma once

#include <vector>
#include <iostream>
#include <string>

using namespace std;

/*
Q2 (10 points) Write a C++ program to implement a stack of integers using a vector with
push and pop operations.
Perform the following operations:
1) Create a stack object.
2) Check the stack is empty or not.
3) Insert some integer values onto the stack.
4) Remove an element from the stack.
4) Find the Top of the stack.
6) Find average value of the stack elements.
*/


struct stack {


public:
	vector<int> vectStack;


	void printEmptyStatus(); // 2) Check the stack is empty or not.
	void insert(); // 3) Insert some integer values onto the stack.
	void remove(); // 4) Remove an element from the stack.
	void peek(); // 4) Find the Top of the stack.
	void average(); // 6) Find average value of the stack elements.


	bool isEmpty();
	void printStack();

};