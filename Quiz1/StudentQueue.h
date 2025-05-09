#include <iostream>
//#include "Student.h"
#include "pNode.h"

using namespace std;

template <class T>
class StudentQueue{
	private:
		pNode<T>* rear;
		pNode<T>* front;
	public:
		StudentQueue (){
		}
		void addNewStudent(int rollno, string name);
		int deleteStudent(int roll);
		pNode<T>* searchByRollNo(int rollno);
};

template <class T>
void StudentQueue<T>::addNewStudent(int rollno, string name){
	pNode<T>* n = pNode<T>(rollno, name);
	
	if (this->front == 0 && this->rear == 0){ // first node
		this->front = this->rear = n;
	}
	
	else if (n->getRollno() < this->front->getRollno()){ // before front 
		n->setNext(this->front);
		this->front = n;
	}

	else { // between the queue
		pNode<T>* temp = this->front;
		
		while (temp->getNext() != 0 && ((Node<T>*)temp->getNext())->getRollno() <= n->getRollno()) {
    		temp = (pNode<T>*)temp->getNext();
		}

		n->setNext(temp->getNext());
		temp->setNext(n);
		
		if (n->getNext() == 0){
			this->rear = n;
		}
	}
	
}
	
template <class Student>
int StudentQueue<Student>::deleteStudent(int rollno){
	pNode<Student>* temp = this->searchByRollNo(rollno);
	
   	if (temp == 0){
	   cerr << "Student with Roll No " << rollno << " not found.\n";
	   return;
	}
	else {
			
		pNode<Student>* temp = this->front;
		int data = temp->getInfo()->getRollno();
		
		this->front = (pNode<Student>*)this->front->getNext();
		if (this->front == 0){
			this->rear = 0;
		}
		
		delete temp;
		return data;
		
	}
}



template <class Student>
pNode<Student>* StudentQueue<Student>::searchByRollNo(int rollno){
	Node<Student>* i = this->getHead();
	
	while (i != 0){
		if (i->getInfo()->getRollno() == rollno){
			return i;
		}
		else {
			i = i->getNext();
		}
	}
	return 0;
} // 
