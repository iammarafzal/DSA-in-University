#include <iostream>
#include "F:\Programming\C++\DSA-in-University\LinkedList\LinkedList.h"
#include "Book.h"

using namespace std;

template <class Book>
class BookLinkedList : public LinkedList<Book> {
	public:
		void display();
		Node<Book>* searchByID(int id);
		void removeBook(int id);
		double calTotalPrice();
		void loadBooksFromFile();
		void showSummary();
};

template <class Book>
void BookLinkedList<Book>::display(){
	Node<Book>* i = this->getHead();
	
	if (i == 0){
		cerr<< "Collection is empty! \n";
	}
	while (i != 0){
		i->getInfo()->display();
		i = i->getNext();
	}
} // 

template <class Book>
void BookLinkedList<Book>::showSummary(){
	if (this->getHead() == 0){
		cerr<< "Collection is empty! \n";
		return;
	}
	else {
		cout<< "------------- Summary Report -------------\n";
		this->display();
		cout<< ">>> Total Cost: " <<this->calTotalPrice();
		cout<< endl;
	}
} // 

template <class Book>
Node<Book>* BookLinkedList<Book>::searchByID(int id){
	Node<Book>* i = this->getHead();
	
	while (i != 0){
		if (i->getInfo()->getBookId() == id){
			return i;
		}
		else {
			i = i->getNext();
		}
	}
	return 0;
} // 

template <class Book>
double BookLinkedList<Book>::calTotalPrice(){
	double totalCost = 0.00;
	Node<Book>* i = this->getHead();
	
	while (i != 0){
		totalCost += i->getInfo()->getPrice();
		i = i->getNext();
	}
	return totalCost;
} // 

template <class Book>
void BookLinkedList<Book>::removeBook(int id){
	Node<Book>* temp = this->searchByID(id);
   	if (temp == 0){
	   cerr << "Book with ID " << id << " not found in collection.\n";
	   return;
	}
	else {
		this->remove(temp->getInfo());  // Correctly removing by ID
		cout << "Book Removed Successfully. \n";
	}
} // 


