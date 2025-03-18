#include <iostream>
#include "StackArray.h"
#include "StackLinked.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
//	StackArray<int> st;
//	st.push(5);
//	st.push(10);
//	st.push(12);
//	st.display();
//	
//	st.pop();
//	st.display();
//	cout<< st.isEmpty();
//	cout<< st.isFull();	

	StackLinked<int> st;
	st.push(4);
	st.push(10);
	st.push(15);
	st.display();
	cout<< st.isEmpty();
	

	return 0;
}
