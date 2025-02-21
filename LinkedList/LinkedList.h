#include <iostream>
#include "Node.h"
using namespace std;

class LinkedList {
	private:
		Node *head; //keeps the address of first node
		Node *tail; //keeps the address of last node
		
	public:
		LinkedList() // user should not be allowed to set 
		// start and end of the list
		{
			// at the time of list creation
			// there will be no data
			// data will be added by calling insertion
			// function later on
			// at the moment there is no node
			head = tail = 0;
		}
		
		void addToTail (int element);
};

void LinkedList::addToTail(int element){
	Node* n = new Node(element);
	// new reserve space at run time
	
	if (head==0 && tail==0){
		// list is empty and we are adding first node
		head = tail = n;
	}
	else { // non empty 1>= nodes already exist
		tail->setNext(n);
		tail = n;
	}
}
