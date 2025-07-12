#include <iostream>
using namespace std;

class HashTable {
    private:
        int* table;
        int capacity;
        int size;
        int EMPTY;

        int hash(int key) {
            return key % capacity;
        }

    public:
        HashTable(int cap) {
            capacity = cap;
            table = new int[capacity];
            EMPTY = -1;
            size = 0;
            for (int i = 0; i < capacity; i++)
                table[i] = EMPTY;
        }
        
        void insert(int key);
        void remove(int key);
        bool search(int key);
        void display();
};

void HashTable::insert(int key) {
    if (size == capacity) {
        cout << "Hash Table is full!\n";
        return;
    }

    int index = hash(key);
    int startIndex = index;

    while (table[index] != EMPTY) {
        if (table[index] == key) {
            cout << "Duplicate key! Not inserted.\n";
            return;
        }
        index = (index + 1) % capacity;
        if (index == startIndex) {
            cout << "No empty slot found.\n";
            return;
        }
    }

    table[index] = key;
    size++;
}

void HashTable::remove(int key) {
    int index = hash(key);
    int startIndex = index;

    while (table[index] != EMPTY) {
        if (table[index] == key) {
            table[index] = EMPTY;
            size--;
            cout << "Key " << key << " removed.\n";
            return;
        }
        index = (index + 1) % capacity;
        if (index == startIndex) break;
    }

    cout << "Key not found.\n";
}

bool HashTable::search(int key) {
    int index = hash(key);
    int startIndex = index;

    while (table[index] != EMPTY) {
        if (table[index] == key)
            return true;
        index = (index + 1) % capacity;
        if (index == startIndex) break;
    }

    return false;
}

void HashTable::display() {
    cout << "Hash Table:\n";
    for (int i = 0; i < capacity; i++) {
        if (table[i] == EMPTY)
            cout << i << " --> EMPTY\n";
        else
            cout << i << " --> " << table[i] << endl;
    }
}
