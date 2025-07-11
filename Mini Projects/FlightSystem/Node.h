#include <iostream>
using namespace std;

class Node {
	private:
		int id;
		int distance;
		Node* next;
		
	public:
		Node(int id, int distance){
			this->id = id;
			this->distance = distance;
			this->next = 0;
			
		}
		void setCityID(int id);
		int getCityID();
		void setDistance(int distance);
		int getDistance();
		void setNext(Node* next);
		Node* getNext();
		void display();
};

void Node::setCityID(int id){
	this->id = id;
}

void Node::setDistance(int distance){
	this->distance = distance;
}

int Node::getCityID(){
	return this->id;
}

int Node::getDistance(){
	return this->distance;
}

void Node::setNext(Node* next){
	this->next = next;
}

Node* Node::getNext(){
	return this->next;
}

void Node::display(){
	cout<< "-> " <<this->getCityID() <<" (" <<this->getDistance() <<" km)";
}
