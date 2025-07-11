#include <iostream>
#include "F:\Programming\C++\DSA-in-University\Stack\StackLinked.h"
#include "F:\Programming\C++\DSA-in-University\Stack\StackArray.h"
#include <ctype.h>

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

double postfixEvalution2(string exp){
	StackArray <double> st(exp.length());
	double num = 0;
	bool inNumber = false;
	
	for (int i=0; i<exp.length(); i++){
		char c = exp[i];
		
		if (isdigit(c)){
			num = num * 10 + (c-'0');
			inNumber = true;
		}
		else if (c == ' ' && inNumber){
			st.push(num);
			num = 0;
			inNumber = false;
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
	}
	return st.pop();
}


string infixToPostfix(string exp){
	StackLinked<char> st;
	string input = "";
	for (int i=0; i<exp.length(); i++){
		if (isalpha(exp[i]) || isdigit(exp[i])){
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
	string output = "";
	infix = stringReverse(infix);
	
	for (int i=0; i<infix.length(); i++){
		if (isalpha(infix[i]) || isdigit(infix[i])){
			output += infix[i];
		}
		else if (infix[i] == ')'){
			st.push(infix[i]);
		}
		else if(infix[i] == '+' || infix[i] == '-' || infix[i] == '*'  || infix[i] == '/' ){
			if (st.isEmpty()){
				st.push(infix[i]);
			}
			else {
				while (!st.isEmpty() && prec(st.topValue()) <= prec(infix[i]) && infix[i]== ')'){
					output += st.pop();
				}
				st.push(infix[i]);
			}
		}
		else if (infix[i] == '('){
			while (st.topValue() != ')'){
				output += st.pop();
			}
			st.pop();
		}
	}
	if (!st.isEmpty()){
		while (!st.isEmpty()){
			output += st.pop();
		}
	}
	return stringReverse(output);
}

string prefixToInfix(string prefix) {
    StackArray<string> st(prefix.length());
    prefix = stringReverse(prefix);
    
    for (int i = 0; i < prefix.length(); i++) {
        if (isalpha(prefix[i])) {
            st.push(string(1, prefix[i]));  // Convert char to string
        } 
        else if (prefix[i] == '+' || prefix[i] == '-' || prefix[i] == '*' || prefix[i] == '/') {
            string a1 = st.pop();
            string a2 = st.pop();
            string exp = "(" + a1 + prefix[i] + a2 + ")";
            st.push(exp);
        }
    }
    return st.pop();
}

string postfixToInfix(string postfix){
	StackArray<string> st(postfix.length());
	
	for (int i=0; i<postfix.length(); i++){
		if (isalpha(postfix[i])){
			st.push(string(1, postfix[i]));
		}
		else  if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/') {
			string a1 = st.pop();
			string a2 = st.pop();
			string exp = "(" + a2 + a1 + ")";
			st.push(exp);
		}
	}
	return st.pop();
}

int main(int argc, char** argv) {
	cout<< postfixEvalution2("19 53 / - 5 2 *");

//	cout<< infixToPostfix("a * ( b + c ) / d - e + f * ( g - h )");
//	cout<< infixToPostfix("a+b*c+(d*e+f)*g");
//	cout<< infixToPrefix("a+b*c+(d*e+f)*g");
//	cout<< prefixToInfix("+-+A*BC/DFE");
//	cout<< postfixToInfix("ABC*+DF/-E+");
//	decimalToBinary(25);
//	stringReversal("Ammar");
//	cout<< symbolBalancing("}}}");
//	cout<< stringReverse("Ammar Afzal");
//	symbolBalancing
	return 0;
}
