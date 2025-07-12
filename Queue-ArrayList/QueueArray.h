#include <iostream>
using namespace std;

template <class T>
class QueueArray {
	protected:
		int rear, front;
		int size;
		T* arr;
	
	public:
		QueueArray (int size=5){
			front = rear = -1;
			this->size=size;
			arr = new T[size];
		}
		void Enqueue(T element);
		T Dequeue();
		bool isEmpty();
		bool isFull();
		T rearValue();
		T frontValue();
		void display();
};

template <class T>
void QueueArray<T>::Enqueue(T element) {
	if (rear == size-1){
		cerr<< "Queue is full. \n";
		return;
	}
	else if (rear == -1 && front == -1){
		front++;
	}
	rear++;
	arr[rear] = element;
}


template <class T>
T QueueArray<T>::Dequeue(){
	if (rear == -1 && front == -1){
		cerr<< "Queue is empty. \n";
	}
	else if (front == rear){
		T element = arr[front];
		rear = front = -1;
		return element;
	}
	else {
		T element = arr[front];
		front++;
		return element;
	}
}

template <class T>
void QueueArray<T>::display(){
	int i = front;
	while (i != rear+1){
		cout<< arr[i] <<" ";
		i++;
	}
	cout<< endl;
}

template <class T>
bool QueueArray<T>::isEmpty(){
	if (rear == -1 && front == -1){
		return true;
	}
	return false;
}

template <class T>
bool QueueArray<T>::isFull(){
	if (rear == size-1){
		return true;
	}
	return false;
}

template <class T>
T QueueArray<T>::rearValue(){
	if (rear == -1 && front == -1){
		cerr<< "Queue is empty. \n";
	}
	return arr[rear];
}

template <class T>
T QueueArray<T>::frontValue(){
	if (rear == -1 && front == -1){
		cerr<< "Queue is empty. \n";
	}
	return arr[front];
}
