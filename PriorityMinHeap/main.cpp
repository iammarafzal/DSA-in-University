#include <iostream>
#include "PriorityMinHeap.h"

int main() {
    PriorityMinHeap ph(10);
    ph.insert(100, 2);
    ph.insert(200, 5);
    ph.insert(300, 1);
    ph.insert(400, 4);

    cout << "Priority Min Heap: ";
    ph.display();

    cout << "Deleting value 200...\n";
    ph.deleteValue(200);
    ph.display();

    return 0;
}
