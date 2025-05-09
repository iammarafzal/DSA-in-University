#include <iostream>
#include "Node.h"
//#include "Student.h"

using namespace std;

template <class T>
class pNode : public Node<T>{
	private:
		int rollno;
		string name;
	public:
		pNode (int roll, string name){
			this->name = name;
			this->rollno = roll;
		}	
};


