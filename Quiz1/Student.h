#include <iostream>

using namespace std;

template <class T>
class Student {
	protected:
		int rollno;
		string name;
		
	public:
		Student(int rollno, string name){
			this->name = name;
			this->rollno = rollno;
		}
		void setRollno(int rollno);
		int getRollno();
		void setName(string name);
		string getName();
};

template <class T>
void Student<T>::setName(string name){
	this->name = name;
}

template <class T>
string Student<T>::getName(){
	return this->name;
}

template <class T>
int Student<T>::getRollno(){
	return this->rollno;
}

template <class T>
void Student<T>::setRollno(int  rollno){
	this->rollno = rollno;
}
