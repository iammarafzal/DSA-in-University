#include <iostream>
#include "F:\Programming\C++\DSA-in-University\LinkedList\LinkedList.h"
using namespace std;

template <class T>
class StackLinked {
	private:
		Node<T>* top;
		
	public:
		StackLinked(){
			top = 0;
		}
	void push(T element);
	T pop();
	void display();
	bool isEmpty();
	T topValue();
	
};

template <class T>
bool StackLinked<T>::isEmpty(){
	if (top == 0){
		return true;
	}
	return false;
}

template <class T>
void StackLinked<T>::push(T element){
	Node<T>* n = new Node<T>(element);
	
	if (top == 0){
		top = n;
	}
	else {
		n->setNext(top);
		top = n;
	}
}

template <class T>
T StackLinked<T>::pop(){
	T temp = top->getInfo();
	
	top = top->getNext();
	return temp;
}

template <class T>
void StackLinked<T>::display(){
	Node<T>* i = top;
	while (i != 0){
		cout<< i->getInfo() <<" ";
		i = i->getNext();
	}
	cout<< endl;
}

template <class T>
T StackLinked<T>::topValue(){
	return top->getInfo();
}


