#include "stack.h"




void stack::printStack() {
	cout << "\n\n";

	printEmptyStatus();

	for (int i = vectStack.size() - 1; i >= 0; i--) {
		cout << " " << vectStack[i];
	}

	cout << "\n\n";
}

bool stack::isEmpty() { // 2) Check the stack is empty or not.
	
	if (vectStack.size() == 0) { return true; }

	return false;
	
}


void stack::printEmptyStatus() {
	if (vectStack.size() == 0) { cout << "\nStack is empty.\n"; return; }
	else { cout << "\nStack has " << vectStack.size() << " elements.\n"; return; }
}


void stack::insert() { // 3) Insert some integer values onto the stack.
	string inp; 
	int numToAdd;
	bool good, done = false; 

	do { // WHILE NOT DONE
		good = false;


		// -------------------------------------------------
		// -------- prompting user for number to add -------
		// -------------------------------------------------

		do { // WHILE NOT GOOD
			try {
				cout << "\nWhat integer would you like to add to the stack? [Q to Quit]\n";
				cin >> inp;

				numToAdd = stoi(inp); // will throw error if can't stoi

				good = true;
			}
			catch (...) { 
				if (toupper(inp[0]) == 'Q') { return; }
				cout << "Poor input. Try again.\n"; 
			}
		} while (!good);

		vectStack.push_back(numToAdd); // adds to the stack

	} while (!done);
}


void stack::remove() { // 4) Remove an element from the stack.
	string inp;
	bool done = false;


		// ------------------------------------------------------------------------------------
		// ------- ASKING THE USER IF THEY WOULD LIKE TO remove An ITEM FOR THE STACK -------
		// ------------------------------------------------------------------------------------

	do { // WHILE NOT done
		try {
			cout << "\nWould you like to remove an item to the stack? [Y/N]\n";
			cin >> inp;

			if (toupper(inp[0]) == 'N') { return; } // if user doesnt want to remove another item, end function and return
			else if (toupper(inp[0]) == 'Y') { 
				if (isEmpty()) { cout << "List is empty.\n\n"; return; }
				else { vectStack.pop_back(); peek(); }
			} 
			else { throw "user didnt input a y or n"; } // if user input is bad, throw error
		}
		catch (...) { cout << "Poor input. Try again.\n"; }
		printStack();
	} while (!done);
}


void stack::peek() { // 4) Find the Top of the stack.
	if (!isEmpty()) {
		cout << "\nTop of the stack: " << vectStack[vectStack.size() - 1] << "\n";
	}
}


void stack::average() { // 6) Find average value of the stack elements.

	double avg = 0; 

	for (int i = 0; i < vectStack.size(); i++) { avg += vectStack[i]; }
	avg /= vectStack.size();

	cout << "\nAverage is : " << avg << "\n\n";

}