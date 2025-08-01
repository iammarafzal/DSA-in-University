#include <iostream>
#include "PriorityMaxHeap.h"

int main() {
    PriorityMaxHeap ph(10);
    ph.insert(100, 2);
    ph.insert(200, 5);
    ph.insert(300, 1);
    ph.insert(400, 7);

    cout << "Priority Max Heap: ";
    ph.display();

    cout << "Deleting value 200...\n";
    ph.deleteValue(200);
    ph.display();

    return 0;
}
