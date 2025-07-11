#include <iostream>
#include <fstream>
#include "BookLinkedList.h"

using namespace std;

void showMenu() {
    cout << "\nLibrary Management System:\n";
    cout << "1. Add Book to Collection\n";
    cout << "2. Remove Book from Collection\n";
    cout << "3. Show Available Books\n";
    cout << "0. Generate Summary Report\n";
    cout << "4. Exit\n";
    cout << "Enter choice: ";
}

void loadBooksFromFile(BookLinkedList<Book*> & inventory) {
    string filename = "Book_Inventory.txt"; // txt file address
    ifstream file(filename.c_str());
    if (!file) {
        cerr << "Unable to open file!\n";
        return;
    }

    int id;
    string title, author;
    double price;

    while (file >> id) {
        file.ignore();  // ignore space and newline 

        getline(file, title, ',');  // read until the , found
        getline(file, author, ',');
        file >> price; 
        file.ignore(); 

        // create a Book object
        Book* book = new Book(id, title, author, price);

        // add book node to inventory 
        inventory.addToTail(book);
    }
    file.close();
}

int main() {
	int choice, id;
    BookLinkedList<Book*> inventory;
    BookLinkedList<Book*> userCollection;

    loadBooksFromFile(inventory);
    inventory.display();
    
    do {
        showMenu();
    	cin>> choice;
    	
    	switch(choice){
    		case 1:
    			cout<< "Enter Book ID: ";
    			cin>> id;
    			if (inventory.searchByID(id) == 0) {
	    			cerr << "Book with ID " << id << " not found in inventory.\n\n";
	    		}
	    		else {
	    			if (userCollection.searchByID(id) != 0){
	    				cerr<< "Book already exists in the collection.\n\n";
	    				break;
					}
					else {
						userCollection.addToHead(inventory.searchByID(id)->getInfo());
					}
	    			cout<< "Book Added Successfully. \n\n";
				}
				break;
				
			case 2:
			    cout << "Enter Book ID: ";
			    cin >> id;
				userCollection.removeBook(id);
			    break;
			    
			case 3:
				inventory.display();
				break;

			case 0:
				userCollection.showSummary();
				break;
		}
	} while(choice != 4);

    return 0;
}

