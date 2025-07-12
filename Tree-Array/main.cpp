#include <iostream>
#include "Tree.h"

int main() {
    TreeArray tree(15);

    tree.insertRoot(10);
    tree.insertLeft(0, 20);
    tree.insertRight(0, 30);
    tree.insertLeft(1, 40);
    tree.insertRight(1, 50);

    tree.display();

    cout << "\nPreorder: ";
    tree.preorder(0);

    cout << "\nInorder: ";
    tree.inorder(0);

    cout << "\nPostorder: ";
    tree.postorder(0);

    return 0;
}
