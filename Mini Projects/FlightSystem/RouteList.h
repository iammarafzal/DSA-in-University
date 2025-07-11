#include <iostream>
#include "Node.h"
using namespace std;

class RouteList {
    private:
        Node* head;
    public:
        RouteList(){
            head = 0;
        }
        Node* getHead();
        void setHead(Node* head);
        void insert(int id, int distance);
        void displayVertices();
};

Node* RouteList::getHead(){
    return this->head;
}

void RouteList::setHead(Node* head){
    this->head = head;
}

void RouteList::insert(int id, int distance){
    Node* newCity = new Node(id, distance);

    newCity->setNext(head);
    head = newCity;
}

void RouteList::displayVertices(){
    Node* i = head;
    while (i != 0){
        i->display();
        i = i->getNext();
    }
    cout<< endl;
}