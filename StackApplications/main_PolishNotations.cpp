#include <iostream>
#include "F:\Programming\C++\DSA-in-University\Stack\StackArray.h"
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


string infixToPostfix(string infix){
	StackArray <char> st(infix.length());
	string expression = "";
	for (int i=0; i<infix.length(); i++){
		if (isdigit(infix[i]) || isalpha(infix[i])){ // if operand
			expression += infix[i];
		}
		else if (infix[i] == '('){ // if opening brackets
			st.push(infix[i]);
		}
		else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/'){ // if operator
			if (st.isEmpty()){
				st.push(infix[i]);
			}
			else if (!st.isEmpty()){
				while (st.topValue() == '(' && !st.isEmpty() && prec(st.topValue() >= prec(infix[i]))){
					expression += st.pop();
				}
				st.push(infix[i]);
			}
		}
		else if (infix[i] == ')'){ // closing brackets
			while (!st.isEmpty()){
				expression += st.pop();
			}
		}
	} // end of for loop
	if (!st.isEmpty()){
		while (!st.isEmpty()){
			expression += st.pop();
		}
	}
	return expression;
} // end of Infix to Postfix

int main(int argc, char** argv) {
	postfixEvaluation("953/-52*+");
//	cout<< infixToPostfix("9-5/3+5*2");
//	cout<< infixToPostfix("a+b*c+(d*e+f)*g");

	return 0;
}
