#include <iostream>

using namespace std;

class Student {
	private:
		int rollno;
		string name;
		
	public:
		Student (int rollno, string name){
			this->rollno = rollno;
			this->name = name;
		}
		void setRollno(int rollno);
		int getRollno();
		void setName(string name);
		string getName();
};

void Student::setName(string name){
	this->name = name;
}

string Student::getName(){
	return this->name;
}

int Student::getRollno(){
	return this->rollno;
}

void Student::setRollno(int  rollno){
	this->rollno = rollno;
}

