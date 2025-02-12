#include <iostream>
#include "ArrayList.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main(int argc, char** argv) {
	ArrayList lst1(5);
	
	lst1.insert(0);
	lst1.insert(7);
	lst1.insert(9);
	lst1.insert(3);
	lst1.insert(17);

	lst1.display();
//	lst1.arraySize();

	lst1.removeAt(1);
	lst1.display();
	
	return 0;
}
