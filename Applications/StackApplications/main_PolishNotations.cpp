#include <iostream>
#include "F:\Programming\C++\DSA-in-University\Stack\StackArray.h"
#include "F:\Programming\C++\DSA-in-University\Stack\StackLinked.h"
//#include "F:\Programming\C++\DSA-in-University\StackApplications\StackApplications.dev"
#include <ctype.h>

int prec(char opr){
	if (opr == '^'){
		return 3;
	}
	else if (opr == '*' || opr == '/'){
		return 2;
	}
	else if (opr == '+' || opr == '-'){
		return 1;
	}
} 

void postfixEvaluation(string exp){
	StackArray<double> st(exp.length());
	
	for (int i=0; i<exp.length(); i++){
		if (isdigit(exp[i])){
			char c = exp[i];
			double temp = c-'0';
			st.push(temp);
		}
		else if (exp[i] == '+' || exp[i] == '-' || 
				exp[i] == '*' || exp[i] == '/'){
					double p1, p2;
					p1 = st.pop();
					p2 = st.pop();
					switch (exp[i]){
						case '+':
							st.push(p2+p1);
							break;
						case '-':
							st.push(p2-p1);
							break;
						case '*':
							st.push(p2*p1);
							break;
						case '/':
							st.push(p2/p1);
							break;
					}	// switch									
				}
	} // end of for loop
	cout<< st.pop() <<endl;
} // end of postfix evaluation

string infixToPostfix(string exp){
	StackLinked<char> st;
	string input = "";
	for (int i=0; i<exp.length(); i++){
		if (isalpha(exp[i])){
			input += exp[i];
		}
		else if (exp[i] == '('){
			st.push(exp[i]);
		}
		else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '/' || exp[i] == '*'){
			if (st.isEmpty()){
				st.push(exp[i]);
			}
			else {
				while (!st.isEmpty() && st.topValue() != '(' && prec(st.topValue()) >= prec(exp[i])){
					input += st.pop();
				}
				st.push(exp[i]);
			}
		}
		else if (exp[i] == ')'){
			while (st.topValue() != '('){
				input += st.pop();
			}
			st.pop();
		}
	}
	if (!st.isEmpty()){
		while (!st.isEmpty()){
			input += st.pop();
		}
	}
	return input;
} // infix to postfix

string infixToPrefix(string infix){
	StackArray<char> st(infix.length());
	string input = "";
	input = 
}


int main(int argc, char** argv) {
//	postfixEvaluation("953/-52*+");
//	cout<< infixToPostfix("9-5/3+5*2");
	cout<< infixToPostfix("a+b*c+(d*e+f)*g");
//	cout<< infixToPostfix("a+b*c+(d*e+f)*g");

	return 0;
}
