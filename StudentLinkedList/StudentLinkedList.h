#include <iostream>
#include "F:\Programming\C++\DSA-in-University\LinkedList\LinkedList.h"
using namespace std;
template <class T>
class StudentLinkedList: public LinkedList<T> {
	public:
		void display();
};

template <class T>
void StudentLinkedList<T>::display(){
	Node<T>* i = this->getHead();
	while (i != 0){
		i->getInfo()->display();
		i = i->getNext();
	}
}

