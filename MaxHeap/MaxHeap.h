#include <iostream>

using namespace std;

class MaxHeap {
    private:
        int* heap;
        int capacity;
        int size;

        void heapifyDown(int i) {
            int largest = i;
            int left = (2 * i) + 1;
            int right = (2 * i) + 2;

            if (left < size && heap[left] > heap[largest])
                largest = left;
            if (right < size && heap[right] > heap[largest])
                largest = right;
            if (largest != i) {
                swap(heap[i], heap[largest]);
                heapifyDown(largest);
            }
        }

        void heapifyUp(int i) {
            int parent = (i - 1) / 2;
            while (i != 0 && heap[parent] < heap[i]) {
                swap(heap[i], heap[parent]);
                i = parent;
                parent = (i - 1) / 2;
            }
        }

    public:
        MaxHeap(int cap) {
            capacity = cap;
            heap = new int[capacity];
            size = 0;
        }

        ~MaxHeap() {
            delete[] heap;
        }

        void insert(int val);
        void display();
};

void MaxHeap::insert(int val) {
    if (size == capacity) {
        cout << "Heap is full!\n";
        return;
    }
    heap[size] = val;
    heapifyUp(size);
    size++;
}

void MaxHeap::display() {
    if (size == 0) {
        cout << "Heap is empty!\n";
        return;
    }
    for (int i = 0; i < size; i++)
        cout << heap[i] << " ";
    cout << endl;
}
