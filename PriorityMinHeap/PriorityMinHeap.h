#include <iostream>
using namespace std;

class PriorityMinHeap {
    private:
        int* values;
        int* priorities;
        int capacity;
        int size;

        void heapifyUp(int i) {
            int parent = (i - 1) / 2;
            while (i > 0 && priorities[parent] > priorities[i]) {
                swap(priorities[i], priorities[parent]);
                swap(values[i], values[parent]);
                i = parent;
                parent = (i - 1) / 2;
            }
        }

        void heapifyDown(int i) {
            int smallest = i;
            int left = (2 * i) + 1;
            int right = (2 * i) + 2;

            if (left < size && priorities[left] < priorities[smallest])
                smallest = left;
            if (right < size && priorities[right] < priorities[smallest])
                smallest = right;

            if (smallest != i) {
                swap(priorities[i], priorities[smallest]);
                swap(values[i], values[smallest]);
                heapifyDown(smallest);
            }
        }

        int findIndex(int val) {
            for (int i = 0; i < size; i++) {
                if (values[i] == val)
                    return i;
            }
            return -1;
        }

    public:
        PriorityMinHeap(int cap) {
            capacity = cap;
            values = new int[capacity];
            priorities = new int[capacity];
            size = 0;
        }

        void insert(int val, int priority);
        void deleteValue(int val);
        void display();
};

void PriorityMinHeap::insert(int val, int priority) {
    if (size == capacity) {
        cout << "Heap is full!\n";
        return;
    }
    values[size] = val;
    priorities[size] = priority;
    heapifyUp(size);
    size++;
}

void PriorityMinHeap::deleteValue(int val) {
    int index = findIndex(val);
    if (index == -1) {
        cout << "Value not found!\n";
        return;
    }

    // Replace with last element
    values[index] = values[size - 1];
    priorities[index] = priorities[size - 1];
    size--;

    // Fix the heap
    heapifyDown(index);
    heapifyUp(index);
}

void PriorityMinHeap::display() {
    if (size == 0) {
        cout << "Heap is empty!\n";
        return;
    }

    cout << "Value(Priority): ";
    for (int i = 0; i < size; i++)
        cout << values[i] << "(" << priorities[i] << ") ";
    cout << endl;
}
