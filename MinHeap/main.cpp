#include <iostream>
#include "MinHeap.h"

int main(){
    MinHeap mh(10);
    mh.insert(20);
    mh.insert(5);
    mh.insert(15);
    mh.insert(10);

    cout << "MinHeap: ";
    mh.display();
    
    return 0;
}