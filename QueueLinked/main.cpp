#include <iostream>
#include "QueueLinked.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	QueueLinked<int> q;
	
	q.Enqueue(10);
	q.Enqueue(15);
	q.Enqueue(20);
	
	cout<< q.rearValue() <<endl;
	cout<< q.frontValue() <<endl;
	
	while (!q.isEmpty()){
		cout<< q.Dequeue() <<" " ;
	}
	
	return 0;
}
