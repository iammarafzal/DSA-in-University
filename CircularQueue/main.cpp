#include <iostream>
#include "CircularQueue.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	CircularQueue<int> cq(4);
	cout<< cq.isEmpty() <<endl;
	cout<< cq.isFull() <<endl;

	cq.Enqueue(90);
	cq.Enqueue(100);
	cq.Enqueue(50);
	cq.Enqueue(6);
	cq.Enqueue(7);
	cq.Enqueue(8);	
	cout<< cq.isFull() <<endl;	
	
	cout<< cq.frontValue() <<endl;
	cout<< cq.rearValue() <<endl;
	
	while (!cq.isEmpty()){
		cout<< cq.Dequeue() <<" ";
	}
	return 0;
}
