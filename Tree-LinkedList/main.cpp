#include <iostream>
#include "BinarySearchTree.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	BinarySearchTree<int> bst;
	
	bst.insert(70);
	bst.insert(80);
	bst.insert(50);
	bst.insert(55);
	bst.insert(7);
	bst.insert(95);
	
	bst.preOrder(bst.getRoot());
	return 0;
}
