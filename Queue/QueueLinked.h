#include <iostream>
#include "F:\Programming\C++\DSA-in-University\LinkedList\LinkedList.h"
using namespace std;

template <class T>
class QueueLinked{
	private:
		Node<T>* rear;
		Node<T>* front;
		
	public:
		QueueLinked(){
			front = rear = 0;
		}
		void Enqueue(T element);
		bool isEmpty();
		void display();
};

template <class T>
void QueueLinked<T>::Enqueue(T element){
	Node<T>* n = new Node<T>(element);
	
	if (rear == 0 && front == 0){ // first node
		rear = front = n;
	}
	else {
		rear->setNext(n);
		rear = n;
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
void QueueLinked<T>::display() {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return;
    }

    Node<T>* temp = front;
    while (temp != 0) {
        cout << temp->getInfo() << " ";
        temp = temp->getNext();
    }
    cout << endl;
}

