#include <iostream>
#include "LinkedList.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	LinkedList<int> lst; // will reserve space for object and calls constructor
	
	LinkedList<char> lst1;
	lst.addSorted(3);
	lst.addSorted(4);
	lst.addSorted(2);
	lst.addSorted(8);
	lst.addSorted(7);
//	lst.addToTail(7);
//	lst.addToTail(10);
//	lst.addToHead(8);
//	lst.deleteHead();
//	lst.insertAt(4, 2);
//	lst.addToHead(12);
//	cout<< lst.Search(10) <<endl;
//	cout<< lst.linearSearch(20) <<endl;
//	lst.remove()
	lst.display();
//	lst.replaceHeadToTail();
//	lst.replaceTailToHead();
//	lst.replaceHandT();
	cout<< endl;
//	lst.remove(11);
//	lst.display();
	
	
	return 0;
}
