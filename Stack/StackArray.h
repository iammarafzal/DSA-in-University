#include <iostream>

using namespace std;

template <class T>
class StackArray {
	private:
		int top;
		T* arr;
		int size;
		
	public:
		StackArray(T size=5) {
			top = -1;
			arr = new T(size);
		}
		void push(T element);
		T pop();
		bool isEmpty();
		bool isFull();
		void display();
		T topValue();
};

template <class T>
void StackArray<T>::push(T element){
	if (top == size-1){
		cerr<< "Stack overflow.\n";
	}
	else {
		top++;
		arr[top] = element;
	}
}

template <class T>
T StackArray<T>::pop(){
	if (top == size-1){
		cerr<< "Stack underflow.\n";
	}
	else {
		T temp = arr[top];
		top--;
		return temp;
	}
}

template <class T>
bool StackArray<T>::isEmpty(){
	if (top == -1){
		return true;
	}
	return false;
}	


template <class T>
bool StackArray<T>::isFull(){
	if (top == size-1){
		return true;
	}
	return false;
}	
	
	
template <class T>
void StackArray<T>::display(){
	T i = top;
	while (i != 0){
		cout<< arr[i] <<" ";
		i--;
	}
	cout<< endl;
}

template <class T>
T StackArray<T>::topValue(){
	if (top == -1){
		cerr<< "Stack underflow.\n";
	}
	else {
		return arr[top];
	}
}

