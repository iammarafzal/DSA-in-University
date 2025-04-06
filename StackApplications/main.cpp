#include <iostream>
#include "F:\Programming\C++\DSA-in-University\Stack\StackLinked.h"
#include "F:\Programming\C++\DSA-in-University\Stack\StackArray.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int decimalToBinary (int decimal){
	StackLinked<int> st;
	int temp;
	while (decimal != 0){
		temp = decimal%2;
		st.push(temp);
		decimal = decimal/2;

	}
	while (!st.isEmpty()){
		cout<< st.pop();
	}
	cout<< endl;
}

void stringReversal(string text){
	StackLinked<char> st;
	for (int i=0; i<text.length(); i++){
		st.push(text[i]);
	}
	while (!st.isEmpty()){
		cout<< st.pop();
	}
	cout<< endl;
}

string stringReverse(string text){
	StackLinked<char> st;
	string rString = "";
	for (int i=0; i<text.length(); i++){
		st.push(text[i]);
	}
	while (!st.isEmpty()){
		char c = st.pop();
		rString += c;
	}
	return rString;
}

bool symbolBalancing(string text){
		StackArray<char> st(text.length());
		for (int i=0; i<text.length(); i++){
			if ((text[i]=='(') || (text[i]=='{') || (text[i]=='[')) { // opening symbol
				st.push(text[i]);
			}
			else { // closing symbol
				if (st.isEmpty()){ // if stack empty
					cerr<< "Opening symbol missing.\n";
					return false;
				}
				else { // if stack is not empty
					char p = st.pop();
					if ((text[i] == '}' && p!='{') ||
						(text[i] == ']' && p!='[') ||
						(text[i] == ')' && p!='(')){
							cerr<<"symbol missed match.\n";
							return false;
						}
					}
				}
		}
		if (!st.isEmpty()){
			cerr<<"Closing Symbol missing.\n";
			return false;
		}
		return true;
}
int main(int argc, char** argv) {
	
	decimalToBinary(25);
//	stringReversal("Ammar");
//	cout<< symbolBalancing("}}}");
//	cout<< stringReverse("Ammar Afzal");
//	symbolBalancing
	return 0;
}
