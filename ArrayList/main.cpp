#include <iostream>
#include "ArrayList.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main(int argc, char** argv) {
	ArrayList lst1(5);
	


	lst1.insert(2);
	lst1.insert(4);
	lst1.insert(6);
	lst1.insert(8);
	lst1.insert(10, 1);
	lst1.insert(3);
//	lst1.insert(4);
//	lst1.insert(5);
//	lst1.insert(6);
//	lst1.insert(7);

	lst1.display();
//	lst1.arraySize();
	lst1.CI();
	
	return 0;
}
