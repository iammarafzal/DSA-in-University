#include <iostream>
#include "StudentLinkedList.h"
#include "Student.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	StudentLinkedList<Student*> list;
	
	Student* s1 = new Student(12, "Ammar Afzal", 3.69);
	Student* s2 = new Student(15, "Umair Afzal", 3.80);
	
	list.addToHead(s1);
	list.addToHead(s2);
	
	list.display();
	return 0;
	
}
