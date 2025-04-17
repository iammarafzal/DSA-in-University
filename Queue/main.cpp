#include <iostream>
#include "QueueArray.h"
#include "QueueLinked.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	QueueLinked<int> q;
	
	q.Enqueue(5);
	q.Enqueue(9);

	cout<< q.isEmpty() <<endl;
	
//	cout<< q.Dequeue();
	
//	
	q.display();
	return 0;
}
