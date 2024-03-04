#include "Single_Linked_List.h"

Single_Linked_List::Single_Linked_List() {
	head = nullptr;
	tail = nullptr;
}


//	NOTE :: I put the functions in regions because they are practically the same things, just with minor differences.
//             It helps quite a bit with readibility.
//             I learned how to do this while practicing C# for Unity



#pragma region - pushes -

void Single_Linked_List::push_front(string data) {
	node* tempNode = new node;
	tempNode->data = data;

	if (empty()) {
		head = tempNode;
		tail = tempNode;
	}
	else {
		tempNode->next_node = head;
		head = tempNode;
	}
	list_size++;
}

void Single_Linked_List::push_back(string data) {
	node* tempNode = new node;
	tempNode->data = data;

	if (empty()) { //if the list is empty, set head & tail pointers to node being added
		head = tempNode;
		tail = tempNode;
	}
	else { //else add node to the end
		tail->next_node = tempNode;
		tail = tempNode;
	}
	list_size++;
}

#pragma endregion

// ------------------------------------------------------------------------------

#pragma region - pops -

void  Single_Linked_List::pop_front() {
	if (empty()) { cout << "\nList is empty.\n"; return; }

	node* deletionNode = head;

	if (head == tail) { head = nullptr;  tail = nullptr; } // checks if the list only has one element, if so set both head&tail to be null.
	else { head = head->next_node; }

	delete deletionNode;
}


void  Single_Linked_List::pop_back() {
	if (empty()) { cout << "\nList is empty.\n"; return; }

	node* deletionNode = tail; // set the node to delete to be the final node

	if (head == tail) { head = nullptr;  tail = nullptr; } // checks if the list only has one element, if so set both head&tail to be null.
	else { 
		node* temp = head; // temp selects the first node

		while (temp->next_node->next_node != nullptr) { temp = temp->next_node; } // get the selector to be at the second to last item in the list
		tail = temp; // tail = second to last item in the list
		tail->next_node = nullptr;
		temp->next_node = nullptr;

	}
	
	delete deletionNode; // delete end item in list
}

#pragma endregion

// ------------------------------------------------------------------------------

#pragma region - front/back -

void Single_Linked_List::front() { if (empty()) return; cout << "\nFront: " << head->data << "\n"; }

void Single_Linked_List::back(){ if (empty()) return; cout << "\nBack: " << tail->data << "\n"; }

#pragma endregion

// ------------------------------------------------------------------------------

bool Single_Linked_List::empty() { return (head == nullptr && tail == nullptr); } // if head and tail are both null, then list is empty

// ------------------------------------------------------------------------------

#pragma region - index functions -

void Single_Linked_List::insert(int indexToAdd, string data) { 
	if (empty() || indexToAdd >= list_size) { push_back(data); return; } // if empty, just add it
	if (indexToAdd == 0) { push_front(data); return; } // if adding to the front, add it to the front

	int currentIndex = 0;

	node* insertAfter = head; // insertAfter selects the first node

	while (currentIndex + 1 < indexToAdd) { // gets insertAfter to be one less than intended index
		insertAfter->next_node; 
		currentIndex++;
	}

	node* temp = new node; // create new node
	temp->data = data; // give new node its data

	temp->next_node = insertAfter->next_node; // new node's next node is the one we're inserting it after
	insertAfter->next_node = temp; // makes insertAfter point towards our new node
}

bool Single_Linked_List::remove(int indexToDel) {
	if (indexToDel > list_size) { return false; }
	if (indexToDel == 0) { // if deleting the front of the list
		node* deletion = head;
		head = head->next_node;
		delete deletion;
		return true;
	}


	node* deleteAfter = head;

	int currentIndex = 0;

	while (currentIndex + 1 < indexToDel) { // gets insertAfter to be one less than intended index
		deleteAfter->next_node;
		currentIndex++;
	}
	
	node* deletion = deleteAfter->next_node;
	deleteAfter->next_node = deletion->next_node;
	delete deletion;
	
	return true;
}

int Single_Linked_List::find(string data) {
	if (empty()) { cout << "List is empty\n"; return 0; }
	
	node* temp = head;
	int index = 0;

	while (temp != nullptr) {
		if (temp->data == data) { return index; } //Return the position of the first occurrence of item if it is found.
		temp = temp->next_node;
		index++;
	}

	return index++; //Return the size of the list if [data] is not found.
}

#pragma endregion

// ------------------------------------------------------------------------------

void Single_Linked_List::print() {
	
		
		if (head == nullptr) {
			cout << "\nEmpty list.\n"; return;
		}
		else {

			node* temp = head;

			while (temp != nullptr) {
				cout << temp->data << " : ";
				temp = temp->next_node;
			}
		}

	cout << "\n\n";
}