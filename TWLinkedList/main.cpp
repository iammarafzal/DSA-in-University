#include <iostream>
#include "TWLinkedList.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	TWLinkedList<int> lst;
//	lst.addToHead(2);
	lst.addToTail(51);
	lst.addToTail(10);
	lst.addToHead(12);
	lst.addToTail(30);
	
	lst.display();
	
//	lst.deleteTail();
//	lst.deleteHead();
//	lst.remove(10);
	lst.insertBefore(12, 20);
	cout<< endl;
	lst.display();
	return 0;
}
