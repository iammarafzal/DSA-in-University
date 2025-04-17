#include <iostream>
using namespace std;

template <class T>
class QueueArray {
	private:
		int rear, front;
		int size;
		T* arr;
	
	public:
		QueueArray (int size=5){
			front = rear = -1;
			arr = new T[size];
		}
		void Enqueue(T element);
		T Dequeue();
		void display();
};

template <class T>
void QueueArray<T>::Enqueue(T element) {
    if (rear == size-1) {
        cerr << "Queue is full.\n";
        return;
    }
    if (rear == -1 && front == -1) { // Queue is empty
        front++;
    }
    rear++;
    arr[rear] = element;
}


template <class T>
T QueueArray<T>::Dequeue(){
	if (rear == -1 && front == -1){ // Q is empty
		cerr<< "Queue is empty. \n";
		return;
	}
	if (rear == front){ // last element of Q
		T element = arr[front];
		front = rear = -1;
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
	int i = 0;
	while (i != rear+1){
		cout<< arr[i] <<" ";
		i++;
	}
	cout<< endl;
}
