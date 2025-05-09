#include <iostream>
#include "StudentQueue.h"
#include "Student.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	StudentQueue <Student> st;
	st.addNewStudent(12, "Ammar");
	return 0;
}
