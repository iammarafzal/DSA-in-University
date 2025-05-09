#include <iostream>
#include "F:\Programming\C++\DSA-in-University\LinkedList\LinkedList.h"
#include "Student.h"

using namespace std;

template <class T>
class StudentLinked : public LinkedList<T> {
public:
    StudentLinked() {}

    void addStudent(int rollno, string name);
    void removeStudent(int rollno);
    Node<T>* search(int rollno);
};

template <class T>
void StudentLinked<T>::addStudent(int rollno, string name) {
    T student(rollno, name);
    Node<T>* st = new Node<T>(student);

    if (this->head == 0 && this->tail == 0) {
        this->head = this->tail = st;
    }
    else if (student.getRollno() >= this->tail->getData().getRollno()) {
        this->addToTail(st);
    }
}

