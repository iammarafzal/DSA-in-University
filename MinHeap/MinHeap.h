#include <iostream>

using namespace std;

class MinHeap {
    private:
        int* heap;
        int capacity;
        int size;

        void heapifyDown(int i) {
        int smallest = i;
        int left = (2*i)+1;
        int right = (2*i)+2;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;
        if (right < size && heap[right] < heap[smallest])
            smallest = right;
        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
            }
        }

        void heapifyUp(int i) {
            int parent = (i-1)/2;
            while (i != 0 && heap[parent] > heap[i]) {
                swap(heap[i], heap[parent]);
                i = parent;
                }
            }

    public:
        MinHeap(int cap) {
        capacity = cap;
        heap = new int[capacity];
        size = 0;
        }
        void insert(int val);
        void display();


};

void MinHeap::insert(int val) {
    if (size == capacity) {
        cout << "Heap is full!\n";
        return;
    }
    heap[size] = val;
    heapifyUp(size);
    size++;
}


void MinHeap::display() {
    for (int i = 0; i < size; i++)
        cout << heap[i] << " ";
    cout << endl;
}