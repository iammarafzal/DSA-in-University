#include "LinkedList.h"
#include "TWNode.h"

template <class T>
class TWLinkedList : public LinkedList<T> {
public:
    TWLinkedList() : LinkedList<T>() {}

    void addToTail(T val);
};

// Function Definitions
template <class T>
void TWLinkedList<T>::addToTail(T val) {
    TWNode<T>* n = new TWNode<T>(val);

    if (this->head == 0 && this->tail == 0) {
        this->head = this->tail = n;
    } else {
        this->tail->setNext(n);
        n->setPrevious(this->tail);  // Fixed (was setting head instead of tail)
        this->tail = n;
    }
}
