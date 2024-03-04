#include "functions.h"


void partOneMenu(Single_Linked_List list) {

	string inp;
	bool done = false;


	do { // while !done
		cout << "What would you like to do to the linked list?\n";
		cout << "(P)ush(F)ront.\n(P)ush(B)ack.\n(R)emove(F)ront.\n(R)emove(B)ack.\n(R)emove(I)ndex.\nPeek(F)ront.\nPeek(B)ack.\n(E)mptyStatus.\n(I)nsert.\n(S)earch.\n(C)out.\n(Q)uit.\n";
		cin >> inp;

		switch (toupper(inp[0])) {
		case 'P':
		{
			if (toupper(inp[1]) == 'F') { // if yser inputted "PF"
				cout << "What would you like to add to the FRONT of the list?   ";
				cin >> inp;
				list.push_front(inp);
			}
			else if (toupper(inp[1]) == 'B') { // if yser inputted "PB"
				cout << "What would you like to add to the BACK of the list?   ";
				cin >> inp;
				list.push_back(inp);
			}
			else { cout << "Bad input. Input command all at once. [ex. \"FB\"]\n\n"; }
			break;
		}
		case 'R':
		{
			if (toupper(inp[1]) == 'F') { list.pop_front(); } // if user inputted "RF"
			else if (toupper(inp[1]) == 'B') { list.pop_back(); } // if user inputted "RB"
			else { cout << "Bad input. Input command all at once. [ex. \"FB\"]\n\n"; }
			break;
		}
		case 'F':
		{
			list.front();
			break;
		}
		case 'B':
		{
			list.back();
			break;
		}
		case 'E':
		{
			if (list.empty()) { cout << "\nList is empty.\n\n"; }
			else { cout << "\nList is not empty.\n\n"; }
			break;
		}
		case 'I':
		{
			string tempData;
			cout << "What would you like to add to the list?   ";
			cin >> tempData;
			cout << "What is the index you'd like to input the data into?   ";
			try {
				cin >> inp;
				int tempInt = stoi(inp);

				list.insert(tempInt, tempData);
			}
			catch (...) { cout << "Bad input. Input an integer.\n\n"; }
			break;
		}
		case 'S':
		{
			cout << "What is the data you'd like to search for?   ";
			cin >> inp;

			cout << "It is found at index: " << list.find(inp) << "\n";
			break;
		}
		case 'C':
		{
			list.print();
			break;
		}
		case 'Q':
		{ return; }
		default:
		{ cout << "Bad input. Try again.\n\n\n"; }
		}
		
	} while (!done);

	cout << "\n\n\n";
}




void partTwoMenu(stack stack) {

	string inp;
	bool done = false;


	do { // while !done
		cout << "What would you like to do to the stack?\n";
		cout << "\n(C)heck the stack is empty or not.\n(I)nsert some integer values onto the stack.\n(R)emove an element from the stack.\n(F)ind the Top of the stack.\n(P)rint the stack.\n(A)verage the values of the stack.\n(Q)uit.\n";
		cin >> inp;

		switch (toupper(inp[0])) {
		case 'C':
			stack.printEmptyStatus();
			break;
		case 'I':
			stack.insert();
			break;
		case 'R':
			stack.remove();
			break;
		case 'F':
			stack.peek();
			break;
		case 'P':
			stack.printStack();
			break;
		case 'A':
			stack.average();
			break;
		case 'Q':
			return;
		default:
			cout << "Bad input. Try again.\n\n\n";
		}
	} while (!done);
	

}