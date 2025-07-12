#include <iostream>
#include "F:\Programming\C++\DSA-in-University\LinkedList\Node.h"

using namespace std;

template <class T>
class QueueLinked {
	protected:
		Node<T>* rear;
		Node<T>* front;
		
	public:
		QueueLinked (){
			rear = front = 0;
		}
		Node<T>* getFront();
		Node<T>* getRear();
		void Enqueue(T element);
		T Dequeue();
		bool isEmpty();
		T rearValue();
		T frontValue();
		
};

template <class T>
Node<T>* QueueLinked<T>::getFront(){
	return this->front;
}

template <class T>
Node<T>* QueueLinked<T>::getRear(){
	return this->rear;
}

template <class T>
void QueueLinked<T>::Enqueue(T element){
	Node<T>* n = new Node<T>(element);
	if (front == 0 && rear == 0){
		front = rear = n;
	}
	else {
		this->rear->setNext(n);
		rear = n;
	}
}

template <class T>
T QueueLinked<T>::Dequeue(){
	if (rear == 0 && front == 0){
		cerr<< "Queue is empty. \n";
	}
	else if (front == rear){
		T temp = front->getInfo();
		delete front;
		rear = front = 0;
		return temp;
	}
	else {
		Node<T>* i = front->getNext();
		T temp = front->getInfo();
		delete front;
		front = i;
		return temp;
	}
}

template <class T>
bool QueueLinked<T>::isEmpty(){
	if (rear == 0 && front == 0){
		return true;
	}
	return false;
}

template <class T>
T QueueLinked<T>::rearValue(){
	if (rear == 0 && front == 0){
		cerr<< "Queue is empty. \n";
	}
	return rear->getInfo();
}

template <class T>
T QueueLinked<T>::frontValue(){
	if (rear == 0 && front == 0){
		cerr<< "Queue is empty. \n";
	}
	return front->getInfo();
}
