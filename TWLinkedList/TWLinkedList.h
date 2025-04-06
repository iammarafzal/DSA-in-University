#include <iostream>
#include "TWNode.h"

using namespace std;

template <class T>
class TWLinkedList {
	protected:
		TWNode<T>* head; //keeps the address of first TWNode<T>
		TWNode<T>* tail; //keeps the address of last TWNode<T>
		
	public:
		TWLinkedList() // user should not be allowed to set 
		// start and end of the list
		{
			// at the time of list creation
			// there will be no data
			// data will be added by calling insertion
			// function later on
			// at the moment there is no TWNode<T>
			head = tail = 0;
		}
		void addToTail (T val);
		void addToHead(T val);
		void insertAt(T val, T index);
		void deleteTail();
		void deleteHead();
		void display();
		TWNode<T>* linearSearch(T val);
		void remove(T element);
		void insertAfter(T existingV, T newV);
		void insertBefore(T existingV, T newV);
		void changeHeadTail();
};

template <class T>
void TWLinkedList<T>::addToTail(T val){
	TWNode<T>* n = new TWNode<T>(val);
	// new reserve space at run time
	
	if (head==0 && tail==0){
		// list is empty and we are adding first TWNode<T>
		head = tail = n;
	}
	else { // non empty 1>= TWNode<T>s already exist
		tail->setNext(n);
		n->setPrevious(tail);
		tail = n;
	}
}

template <class T>
void TWLinkedList<T>::addToHead(T val){
	TWNode<T>* n = new TWNode<T>(val);
	if (head == 0){
		head = tail = n;
	}
	else {
		n->setNext(head);
		head->setPrevious(n);
		head = n;
	}
}

template <class T>
void TWLinkedList<T>::display(){
	TWNode<T>* i = head;
	
//	cout<< "| (Current) | Info | Next | Previous | " << endl;
	while (i != 0){
		i->display();
		i = i->getNext();
	}
}

template <class T>
void TWLinkedList<T>::deleteTail(){
	if (head == 0){
		cerr<< "List is empty! \n";
	}
	else if (head == tail){
		head = tail = 0;
	}
	else {
		TWNode<T>* temp = tail->getPrevious();
		temp->setNext(0);
		delete tail;
		tail = temp;	
	}
}

template <class T>
void TWLinkedList<T>::deleteHead(){
	if (head == 0){
		cerr<< "List is empty! \n";
	}
	else if (head == tail){
		head = tail = 0;
	}
	else {
		TWNode<T>* i = head->getNext();
		i->setPrevious(0);
		delete head;
		head = i;
	}
}

template <class T>
void TWLinkedList<T>::insertAt(T val, T index){
	if (index < 0){
		cerr<< "Invalid Index! \n";
	}
	else if (index == 0){
		this->addToHead(val);
	}
	else {
		TWNode<T>* n = new TWNode<T>(val);
		TWNode<T>* temp = head;
		
		for (int i=0; i<index-1; i++){
			temp = temp->getNext();
		}
		n->setNext(temp->getNext());
		temp->setNext(n);
	}
}

template <class T>
TWNode<T>* TWLinkedList<T>::linearSearch(T val){
	TWNode<T>* i = head;
	
	while (i != 0){
		if (val == i->getInfo()){
			return i;
		}
		i = i->getNext();
	}
	return i;
}

template<class T>
void TWLinkedList<T>::remove(T element){
	if ((head == 0 && tail ==0) || linearSearch(element) == 0){ // if list is empty or element not found
		cerr<< "Element can not be deleted! \n";
		return;
	}
	else if (head->getNext()==0){ // if 1 TWNode exists
		delete head;
		head = tail = 0;
	}
	else if (element == head->getInfo()){ // if element is at head
		this->deleteHead();
	}
	else if (element == tail->getInfo()){ // if element is at tail
		this->deleteTail();
	}
	else {
		TWNode<T>* temp = linearSearch(element);
		TWNode<T>* prev = temp->getPrevious();
		TWNode<T>* next = temp->getNext();
		prev->setNext(temp->getNext());
		next->setPrevious(prev);
		
	}
}

template<class T>
void TWLinkedList<T>::insertAfter(T existingV, T newV){
	if (head == 0 || linearSearch(existingV) == 0){
		cerr<< "Element can not be deleted! \n";
		return;
	}
	TWNode<T>* temp = linearSearch(existingV);
	
	if (temp == tail) { // If inserting after the tail
	        this->addToTail(newV);
	        return;
	    }
	else {
		TWNode<T>* n = new TWNode<T>(newV);
		TWNode<T>* temp = linearSearch(existingV);
		TWNode<T>* next = temp->getNext();
		newV->setNext(next);
		temp->setNext(n);
		newV->setPrevious(temp);
		next->setPrevious(newV);
	}
}

template<class T>
void TWLinkedList<T>::insertBefore(T existingV, T newV) {
    if (head == 0 || linearSearch(existingV) == 0) {
        cerr << "Element not found! Cannot insert.\n";
        return;
    }

    TWNode<T>* temp = linearSearch(existingV); // Find the node with existingV

    if (temp == head) { // If inserting before the head
        this->addToHead(newV);
        return;
    }

    // Create a new node with newV
    TWNode<T>* n = new TWNode<T>(newV);
    TWNode<T>* prev = temp->getPrevious();

    // Correctly update pointers
    n->setNext(temp);
    n->setPrevious(prev);
    prev->setNext(n);
    temp->setPrevious(n);
}

template<class T>
void TWLinkedList<T>::changeHeadTail() {
    if (head == 0) {
        cerr << "List is empty! \n";
        return;
    }
    if (head == tail) {
        cerr << "List has only one node. \n";
        return;
    }

    // Store references to important nodes
    TWNode<T>* oldHead = head;
    TWNode<T>* oldTail = tail;
    TWNode<T>* beforeTail = tail->getPrevious();
    TWNode<T>* afterHead = head->getNext();

	head = oldTail;
	tail = oldHead;
	
	head->setPrevious(0);
	head->setNext(afterHead);
	
	tail->setNext(0);
	tail->setPrevious(beforeTail);
	
	if (afterHead != 0){
		afterHead->setPrevious(head);
	}
	if (afterHead != 0){
		beforeTail->setNext(tail);
	}
	
}



