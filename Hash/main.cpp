#include <iostream>
#include "Hash.h"

int main() {
    HashTable ht(7);

    ht.insert(10);
    ht.insert(20);
    ht.insert(5);
    ht.insert(15);

    ht.display();

    cout << "\nSearching for 15: " << (ht.search(15) ? "Found" : "Not Found") << endl;

    ht.remove(20);
    ht.display();

    ht.remove(99);  // Not present

    return 0;
}
