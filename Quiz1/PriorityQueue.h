#include <iostream>
#include "pNode.h"
using namespace std;

template <class T>
class PriorityQueue {
	protected:
		pNode<T>* rear;
		pNode<T>* front;
		
	public:
		PriorityQueue(){
			this->rear = 0;
			this->front = 0;
		}

		void addSorted(int priority , string element);
		T dequeue();
		bool isEmpty();
};

template <class T>
bool PriorityQueue<T>::isEmpty(){
	if (rear == 0 && front == 0){
		return true;
	}
	return false;
}

template <class T>
void PriorityQueue<T>::addSorted(int priority , T element){
	pNode<T>* n = new pNode<T>(info, priority);
	
	if (this->front == 0 && this->rear == 0){ // first node
		this->front = this->rear = n;
	}
	
	else if (n->getPriority() < this->front->getPriority()){ // before front 
		n->setNext(this->front);
		this->front = n;
	}
	else { // between the queue
		pNode<T>* temp = this->front;
		
		while (temp->getNext() != 0 && ((pNode<T>*)temp->getNext())->getPriority() <= n->getPriority()) {
    		temp = (pNode<T>*)temp->getNext();
		}

		
		n->setNext(temp->getNext());
		temp->setNext(n);
		
		if (n->getNext() == 0){
			this->rear = n;
		}
	}
}

template <class T>
T PriorityQueue<T>::dequeue(){
	if (this->front == 0){
		cerr<< "Queue is empty. \n";
		return T();
	}
	
	pNode<T>* temp = this->front;
	T data = temp->getInfo();
	
	this->front = (pNode<T>*)this->front->getNext();
	
	if (this->front == 0){
		this->rear = 0;
	}
	
	delete temp;
	return data;
}
