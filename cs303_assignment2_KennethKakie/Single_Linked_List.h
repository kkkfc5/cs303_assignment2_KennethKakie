#pragma once
#include "node.h"
#include <iostream>
/*
Q1. (15 points) Build a Single_Linked_List class. Your class should have the data members:
head, tail, and num_items. Write the following member functions, which perform the same
operations as the corresponding functions in the standard list class:
• push_front,
• push_back,
• pop_front,
• pop_back,
• front, back,
• empty,
• void insert(size_t index, const Item_Type& item): Insert item at position index (starting at 0). Insert at the end if index is beyond the end of the list
• bool remove(size_t index):
• size_t find(const Item_Type& item): 
*/


class Single_Linked_List {
private:
	node* head;
	node* tail;
	int list_size = 0;
public:
	Single_Linked_List();

	void push_front(string data);
	void push_back(string data);
	void pop_front();
	void pop_back();
	void front();
	void back();
	bool empty(); // BOOL, CHECKS IF LIST IS EMPTY

	void insert(int index, string data);
	bool remove(int index);
	int find(string data); // Return the position of the first occurrence of item if it is found. Return the size of the list if it is not found.


	void print();
};