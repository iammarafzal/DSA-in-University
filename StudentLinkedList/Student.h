#include <iostream>

using namespace std;

class Student {
	private:
		int rollNo;
		string name;
		double gpa;
		
	public:
		Student(int rollNo, string name, double gpa){
			this->rollNo = rollNo;
			this->name = name;
			this->gpa = gpa;			
		}
		
		void setRollNo(int rollNo);
		void setName(string name);
		void setGpa(double gpa);
		int getRollNo();
		string getName();
		double getGpa();
		void display();
};

void Student::setRollNo(int rollNo){
	this->rollNo = rollNo;
}

void Student::setName(string name){
	this->name = name;
}

void Student::setGpa(double gpa){
	this->gpa = gpa;
}

int Student::getRollNo(){
	return rollNo;
}

string Student::getName(){
	return name;
}

double Student::getGpa(){
	return gpa;
}

void Student::display(){
	cout<< "Student Details\n";
	cout<< "Roll No: " <<this->rollNo <<endl;
	cout<< "Name: " <<this->name <<endl;
	cout<< "GPA: " <<this->gpa <<endl;
	cout<< endl;
}
