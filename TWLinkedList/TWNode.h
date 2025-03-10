#include <iostream>
using namespace std;

template <class T>
class TWNode {
	protected:
    	T info;
    	TWNode<T>* next;
    	TWNode<T>* prev;

public:
    TWNode(T info = 0, TWNode<T>* next = 0, TWNode<T>* prev=0) {
        this->info = info;
        this->next = next;
        this->prev = prev;
    }

    void setInfo(T info);
    void setNext(TWNode<T>* next);
    void setPrevious(TWNode<T>* prev);
    TWNode<T>* getPrevious();
    T getInfo();
    TWNode<T>* getNext();
    void display();
};

template <class T>
void TWNode<T>::setInfo(T info) {
    this->info = info;
}

template <class T>
void TWNode<T>::setNext(TWNode<T>* next) {
    this->next = next;
}

template <class T>
T TWNode<T>::getInfo() {
    return this->info;
}

template <class T>
TWNode<T>* TWNode<T>::getNext() {
    return this->next;
}

template <class T>
void TWNode<T>::setPrevious(TWNode<T>* prev) {
    this->prev = prev;
}

template <class T>
TWNode<T>* TWNode<T>::getPrevious(){
	return this->prev;
}

template <class T>
void TWNode<T>::display() {
    cout << "| (" << this << ") | " << this->getInfo() << " | " << this->getNext() << " | " << this->getPrevious() <<" | " << endl;
}


