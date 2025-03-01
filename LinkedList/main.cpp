#include <iostream>
#include "LinkedList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	LinkedList<int> lst; // will reserve space for object and calls constructor
	
	lst.addToTail(7);
	lst.addToTail(10);
	lst.addToHead(8);
	
	lst.display();
	
	cout<< endl;
//	lst.deleteHead();
	lst.insertAt(4, 2);
	cout<< lst.linearSearch(10) <<endl;
	cout<< lst.linearSearch(20) <<endl;
	
	lst.display();
	
	
	return 0;
}
