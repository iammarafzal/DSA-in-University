#include <iostream>
#include "F:\Programming\C++\DSA-in-University\QueueArray\QueueArray.h"

using namespace std;
template <class T>
class CircularQueue : public QueueArray<T> {
	public:
		CircularQueue(int size=5){
			this->size = size;
		}
		void Enqueue(T element);
		T Dequeue();
		bool isEmpty();
		bool isFull();
};


template <class T>
void CircularQueue<T>::Enqueue(T element) {
    if ((this->rear + 1) % this->size == this->front) {
        cerr << "Queue is full.\n";
        return;
    }
    else if (this->rear == -1 && this->front == -1) {
        this->front = this->rear = 0;
    }
    else {
        this->rear = (this->rear + 1) % this->size;
    }
    this->arr[this->rear] = element;
}

template <class T>
T CircularQueue<T>::Dequeue() {
    if (this->rear == -1 && this->front == -1) {
        cerr << "Queue is empty.\n";
        return T(); // Return default value
    }
    T element = this->arr[this->front];
    if (this->rear == this->front) {
        this->front = this->rear = -1;
    }
    else {
        this->front = (this->front + 1) % this->size;
    }
    return element;
}

template <class T>
bool CircularQueue<T>::isEmpty() {
    return this->rear == -1 && this->front == -1;
}

template <class T>
bool CircularQueue<T>::isFull() {
    return (this->rear + 1) % this->size == this->front;
}


