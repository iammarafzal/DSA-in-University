#include <iostream>
#include "Node.h"

template <class T>
class TWNode : public Node<T> {
private:
    Node<T>* prev;

public:
    TWNode(T info, Node<T>* next = 0, Node<T>* prev = 0){
    	this->info = info;
    	this->next = next;
    	this->prev = prev;
	}

    void setPrevious(Node<T>* prev);
    Node<T>* getPrevious();
};

// Function Definitions
template <class T>
void TWNode<T>::setPrevious(Node<T>* prev) {
    this->prev = prev;
}

template <class T>
Node<T>* TWNode<T>::getPrevious() {
    return prev;
}

