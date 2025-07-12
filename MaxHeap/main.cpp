#include <iostream>
#include "MaxHeap.h"

int main(){
    MaxHeap mh(10);
    mh.insert(10);
    mh.insert(25);
    mh.insert(15);
    mh.insert(40);
    mh.insert(5);

    cout << "Max Heap: ";
    mh.display();

    
    return 0;
}