#include <iostream>
#include "PriorityQueue.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	PriorityQueue<int> pq;
	
	pq.addSorted(5, 2);
	pq.addSorted(12, 2);
	pq.addSorted(15, 4);
	pq.addSorted(3, 1);
	pq.addSorted(9, 9);
	
	while (!pq.isEmpty()){
		cout<< pq.dequeue() << " ";
	}
	return 0;
}

