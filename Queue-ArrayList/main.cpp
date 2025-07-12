#include <iostream>
#include "Queue.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	QueueArray<int> q;
	q.Enqueue(5);
	q.Enqueue(6);
	q.Enqueue(7);
	q.Enqueue(8);
	q.Enqueue(9);
//	q.Enqueue(10);
//	q.Enqueue(11);
	cout<< q.Dequeue() <<endl;
	cout<< q.Dequeue() <<endl;
	cout<< "Is Empty: " <<q.isEmpty() <<endl;
	cout<< "Is Full: " <<q.isFull() <<endl;
	q.display();
	return 0;
}
