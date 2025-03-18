#include <iostream>
#include "TWLinkedList.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	TWLinkedList<int> lst;
//	lst.addToHead(2);
	lst.addToTail(10);
	lst.addToTail(20);
	lst.addToTail(30);
	lst.addToTail(50);
	
	lst.display();
	
//	lst.deleteTail();
//	lst.deleteHead();
//	lst.remove(10);
//	lst.insertBefore(12, 20);
//	lst.changeHeadTail();
	cout<< endl;
	lst.insertBefore(30, 25);
	lst.display();
	return 0;
}
