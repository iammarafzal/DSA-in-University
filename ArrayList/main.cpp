#include <iostream>
#include "ArrayList.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main(int argc, char** argv) {
	ArrayList lst1(5);
	

	lst1.insert(2);
	lst1.insert(9);
	lst1.insert(1);
	lst1.insert(17);
	lst1.insert(8);
	lst1.insert(3);
	lst1.insert(12);

// Sorted List
//	 lst1.insert(19);
//	 lst1.insert(22);
//	 lst1.insert(35);
//	 lst1.insert(38);
//	 lst1.insert(40);
//	 lst1.insert(48);

	// lst1.display();
//	cout<< lst1.binarySearch(40);
//	lst1.arraySize();

	// lst1.removeAt(1);
	// lst1.removeLast();
	// lst1.removeFirst();
	// lst1.linearSearch(3);
	// cout<< lst1.isFound(3) <<endl;
	// cout<< lst1.binarySearch(39) <<endl;
	lst1.display();
//	lst1.insertionSort(5);
	lst1.bubbleSort();
//	cout<< lst1.largestValue(5);
//	lst1.selectionSort();
	lst1.display();


	// lst1.largestNum();
	
	return 0;
}
