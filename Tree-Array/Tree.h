#include <iostream>
using namespace std;

class TreeArray {
    private:
        int* tree;
        int capacity;

    public:
        TreeArray(int cap) {
            capacity = cap;
            tree = new int[capacity];
            for (int i = 0; i < capacity; i++)
                tree[i] = -1;  // -1 means empty
        }

        void insertRoot(int value);
        void insertLeft(int parentIndex, int value);
        void insertRight(int parentIndex, int value);
        void display();
        void preorder(int index);
        void inorder(int index);
        void postorder(int index);
};

void TreeArray::insertRoot(int value) {
    if (tree[0] != -1) {
        cout << "Root already exists!\n";
        return;
    }
    tree[0] = value;
}

void TreeArray::insertLeft(int parentIndex, int value) {
    int leftIndex = 2 * parentIndex + 1;
    if (parentIndex >= capacity || tree[parentIndex] == -1) {
        cout << "Invalid parent index.\n";
        return;
    }
    if (leftIndex >= capacity) {
        cout << "Left child index out of bounds.\n";
        return;
    }
    tree[leftIndex] = value;
}

void TreeArray::insertRight(int parentIndex, int value) {
    int rightIndex = 2 * parentIndex + 2;
    if (parentIndex >= capacity || tree[parentIndex] == -1) {
        cout << "Invalid parent index.\n";
        return;
    }
    if (rightIndex >= capacity) {
        cout << "Right child index out of bounds.\n";
        return;
    }
    tree[rightIndex] = value;
}

void TreeArray::display() {
    cout << "Tree Array Representation:\n";
    for (int i = 0; i < capacity; i++) {
        if (tree[i] != -1)
            cout << "Index " << i << " --> " << tree[i] << endl;
        else
            cout << "Index " << i << " --> EMPTY\n";
    }
}

void TreeArray::preorder(int index) {
    if (index >= capacity || tree[index] == -1)
        return;
    cout << tree[index] << " ";
    preorder(2 * index + 1);
    preorder(2 * index + 2);
}

void TreeArray::inorder(int index) {
    if (index >= capacity || tree[index] == -1)
        return;
    inorder(2 * index + 1);
    cout << tree[index] << " ";
    inorder(2 * index + 2);
}

void TreeArray::postorder(int index) {
    if (index >= capacity || tree[index] == -1)
        return;
    postorder(2 * index + 1);
    postorder(2 * index + 2);
    cout << tree[index] << " ";
}
