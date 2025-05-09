#include <iostream>
#include "Node.h"
using namespace std;

class HeaderLL {
	private:
		Node* head;
		
	public:
		HeaderLL (){
			this->head = 0;
		}
		void insert(int vertexinfo); // to add a neighbour of specific vertex
		Node* getHead();
		void print();
};

void HeaderLL::insert(int vertexinfo){
	Node* vertex = new Node(vertexinfo);
	
	vertex->setNext(this->head);
	head = vertex;
}

Node* HeaderLL::getHead(){
	return this->head;
}

void HeaderLL::print(){
	Node* i = this->head;
	while (i != 0){
		i->display();
		i = i->getNext();
	}
}
