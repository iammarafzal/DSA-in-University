#include <iostream>
#include "Node.h"

using namespace std;
template <class T>

class LinkedList {
	private:
		Node<T> *head; //keeps the address of first Node<T>
		Node<T> *tail; //keeps the address of last Node<T>
		
	public:
		LinkedList() // user should not be allowed to set 
		// start and end of the list
		{
			// at the time of list creation
			// there will be no data
			// data will be added by calling insertion
			// function later on
			// at the moment there is no Node<T>
			head = tail = 0;
		}
		
		void addToTail (T val);
		void addToHead(T val);
		void insertAt(T val, T index);
		void deleteTail();
		void deleteHead();
		void display();
		Node<T>* linearSearch(T val);
		void remove(T element);
};

template <class T>
void LinkedList<T>::addToTail(T val){
	Node<T>* n = new Node<T>(val);
	// new reserve space at run time
	
	if (head==0 && tail==0){
		// list is empty and we are adding first Node<T>
		head = tail = n;
	}
	else { // non empty 1>= Node<T>s already exist
		tail->setNext(n);
		tail = n;
	}
}

template <class T>
void LinkedList<T>::addToHead(T val){
	Node<T>* n = new Node<T>(val);
	if (head == 0){
		head = tail = n;
	}
	else {
		n->setNext(head);
		head = n;
	}
}

template <class T>
void LinkedList<T>::display(){
	Node<T>* i = head;
	
	while (i != 0){
		i->display();
		i = i->getNext();
	}
}

template <class T>
void LinkedList<T>::deleteTail(){
	if (head == 0){
		cerr<< "List is empty! \n";
	}
	else if (head == tail){
		head = tail = 0;
	}
	else {
		Node<T>* temp = head;
		
		while (temp->getNext() != tail){
			temp = temp->getNext();
		}
		temp->setNext(0);
		delete tail;
		tail = temp;
	}
}

template <class T>
void LinkedList<T>::deleteHead(){
	if (head == 0){
		cerr<< "List is empty! \n";
	}
	else if (head == tail){
		head = tail = 0;
	}
	else {
		Node<T>* i = head->getNext();
		delete head;
		head = i;
	}
}

template <class T>
void LinkedList<T>::insertAt(T val, T index){
	if (index < 0){
		cerr<< "Invalid Index! \n";
	}
	else if (index == 0){
		this->addToHead(val);
	}
	else {
		Node<T>* n = new Node<T>(val);
		Node<T>* temp = head;
		
		for (int i=0; i<index-1; i++){
			temp = temp->getNext();
		}
		n->setNext(temp->getNext());
		temp->setNext(n);
	}
}

template <class T>
Node<T>* LinkedList<T>::linearSearch(T val){
	Node<T>* i = head;
	
	while (i != 0){
		if (val == i->getInfo()){
			return i;
		}
		i = i->getNext();
	}
	return i;
}

template<class T>
void LinkedList<T>::remove(T element){
	if ((head == 0 && tail ==0) || linearSearch(val) == 0){
		cerr<< "Element can not be deleted! \n";
		return;
	}
	else if (head->getNext()==0){
		delete head;
		head = tail = 0;
	}
	else if (element == head->getInfo()){
		this->deleteHead();
	}
	else if (element == tail->getInfo()){
		this->deleteTail();
	}
	else {
		
	}
}
