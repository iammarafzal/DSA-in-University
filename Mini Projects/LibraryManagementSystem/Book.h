#include <iostream>
using namespace std;

class Book {
	private:
		int bookId;
		string title;
		string author;
		double price;
		
	public:
		Book(int id, string title, string author, double price){
			this->bookId = id;
			this->title = title;
			this->author = author;
			this->price = price;
		}
		
		void setBookId(int bookId);
		void setTitle(string title);
		void setAuthor(string author);
		void setPrice(double price);
		int getBookId();
		string getTitle();
		string getAuthor();
		double getPrice();
		void display();
};

void Book::setBookId(int bookId){
	this->bookId = bookId;
}

void Book::setTitle(string title){
	this->title = title;
}

void Book::setAuthor(string author){
	this->author = author;
}

void Book::setPrice(double price){
	this->price = price;
}

int Book::getBookId(){
	return bookId;
}

string Book::getTitle(){
	return title;
}

string Book::getAuthor(){
	return author;
}

double Book::getPrice(){
	return price;
}

void Book::display(){
	cout << "Book ID: " << bookId << "\nTitle: " << title << "\nAuthor: " << author << "\nPrice: " << price << "\n";
	cout<< endl;
}
