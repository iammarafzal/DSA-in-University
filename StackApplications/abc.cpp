#include <iostream>
#include "F:\Programming\C++\DSA-in-University\Stack\StackArray.h"
#include "cctype"
using namespace std;
int prec(char a);
string infixToPostfix(string infix); 
string stringReversal(string ele);
string infix_to_postfix(string infix); 
string infixToPrefix(string infix);
int prec(char a);
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char** argv) {

cout<<"Bscs 3B Evening (40)"<<endl;
cout<<infixToPrefix("(A + B) * (C + D)") ;//
return 0;
};

//Stack Application-(infix-to-postfix conversion)

//1.Create an empty stack of type char
//2.Read input expression char by char till the end of input
//	2.1.Operand: display it
//	2.2.Opening Parenthesis: push
//	2.3.Operator:
//		2.3.1.	If stack is empty then push it
//      2.3.2.	If stack is non-empty then pop characters from stack and display them until we find an operator of lower precedence or an opening parenthesis or stack become empty. When popping is done push the current operator on to the stack.
//  2.4.Closing Parenthesis: Pop operators from stack and display them until we pop an opening parenthesis which will be popped but not displayed.
//3.At the end of input, if stack is non-empty, pop operators from stack and display them until the stack becomes empty.



//string infix_to_postfix(string infix)//"A + B * C + D"    ----   +
//{
//string postfix="";//"ABC*+D+  
//	StackList<char> s1;//1    //  
//	for(int i=0;i<3;i++)//2
//	{
//	if(isalpha(infix[i]))//2.1.Operand: display it
//{	
//	postfix=postfix+infix[i];
//}//2.1.Operand: display it
//else if(infix[i]=='(')//	2.2.Opening Parenthesis: push
//{
//	s1.push(infix[i]);
//}//	2.2.Opening Parenthesis: push
//else if(infix[i]=='+'||infix[i]=='-'||infix[i]=='*'||infix[i]=='^'||infix[i]=='/')	//2.3.Operator:
//{
//	if(s1.isempty())//2.3.1 empty
//	{
//		s1.push(infix[i]);//+
//	}//2.3.1
//	else //2.3.2 non empty
//	{
//		while(!s1.isempty()  && prec(s1.topvalue())>prec(infix[i]) &&s1.topvalue() !='(')
//	
//		{
//			postfix=postfix+s1.pop();
//		}
//		s1.push(infix[i]);
//	}//2.3.2
//}//2.3.Operator:	
//else if(infix[i]==')')//	2.4.Closing Parenthesis:
//{
//	while(s1.topvalue()!='(')
//	{postfix=postfix+s1.pop();
//	}
//	s1.pop();
//}//	2.4.Closing Parenthesis:
//	}//2 for
//	
////3	
//
//	if(!s1.isempty())
//	{
//while(!s1.isempty())
//{
//	postfix=postfix+s1.pop();
//}//while is emppty
//	}
//	
//return postfix;
//}//infix_to_postfix
////
////
//


string infixToPostfix(string infix) //(A + B) * (C + D)
{   
 string postfix="";
		StackArray<char> s2;//1
	for(int i=0;i<infix.length();i++)//2
	{ 
		if(isalpha(infix[i]))//2.1 oprend
		{
			postfix=postfix+infix[i];//is amal ko concatination kehtey hai
		}//2.1 oprend
		else if(infix[i]=='(')//2.2 opening symbol
		{
			s2.push(infix[i]);
		}//2.2 opening symbol
		else if(infix[i]=='+'||infix[i]=='-'||infix[i]=='/'||infix[i]=='*'||infix[i]=='^')//2.3 oprater
		{
			if(s2.isempty())//2.3.1 is Empty
			{
				s2.push(infix[i]);
			}//2.3.1
			else //2.3.2 non empty
			{
			while(!s2.isempty()&& s2.topvalue() != '(' && prec(s2.topvalue())> prec(infix[i]))
			{
				postfix +=s2.pop();
			} //while
			s2.push(infix[i]);				
			}//2.3.2
		}//2.3 oprater
		else if(infix[i]==')')//2.4 closing symbol
		{
			while(s2.topvalue() != '(')
			{
					postfix +=s2.pop();
			}
			
			s2.pop();
		
	
		}//2.4 closing symbol
	
	
	}//for 2
	
	if(!s2.isempty())
	{
		while(!s2.isempty())
		{
			postfix+=s2.pop();
		}
	}
	return postfix;
}
//
//
//



//1.Create an empty stack of type char
//2.Create an output string
//3.Reverse the input expression
//4.Read the reversed input expression char by char till the end of input
//	4.1.Operand: add to a output string
//	4.2.Closing Parenthesis: push
//	4.3.Operator:
//	           4.3.1.If stack is empty then push it
//            4.3.2.If stack is non-empty then pop characters from stack and add them to output string until 
//            we find an operator with lower or equal precedence or an closing parenthesis or 
//             //stack become empty. When popping is done push the current operator on to the stack.
//  4.4.Opening Parenthesis: Pop operators from stack and add them to output string until we pop a 
//   closing parenthesis which will be popped but not be added to output string.
//
//5. At the end of input, if stack is non-empty, pop operators from stack and add them  to output string until the stack becomes empty.
//6. Reverse the output string and display it.


string infixToPrefix(string infix)//(A + B) * (C + D )
{
	string postfix="";//1 // D ,C,+ , B, A, + 
	StackList<char> s1;//2  ; // *  
	string reinfix=stringReversal(infix);// 3
	for(int i=0;i<reinfix.length();i++)//      
	{
	//cout<<"for loop \n";

	if(isalpha(reinfix[i])) //4.1 oprand 
	{
	 postfix=postfix+reinfix[i];
	}//4.1 oprand //
	else if(reinfix[i]==')') //4.2 closing paranthics 
	{
		s1.push(reinfix[i]);
	}//4.2 closing paranthics 
	else if(reinfix[i]=='+'||reinfix[i]=='-'||reinfix[i]=='/'||reinfix[i]=='*'||reinfix[i]=='^')//4.3 operater
	{
		if(s1.isempty())//4.3.1 is Empty
			{
				s1.push(reinfix[i]);
			}//4.3.1//
			else //4.3.1 non empty
			{
			while(!s1.isempty() && s1.topvalue() != ')' &&(( prec(s1.topvalue()) > prec(reinfix[i]) )&&(prec(s1.topvalue())!= prec(reinfix[i]) ) ) )
			{
				postfix =postfix+s1.pop();
			} //while
			s1.push(reinfix[i]);				
			}//4.3.1
	}
	
	else if(reinfix[i]=='(')//4.4 //opening paranthices
	{
		while(s1.topvalue()!=')')
			{
				postfix +=s1.pop();
				//cout<<"whil loop reinfix[i]!=')' \n";
			} //while
			//cout<<"whil loop reinfix[i]!=')' end up \n";
			if(s1.topvalue()==')')
			{
				s1.pop();
			}
	}

	
		}// 4 for // D ,C,+ , B, A, + 
		
	

		 if(!s1.isempty())//5
	{
			postfix +=s1.pop();
//	while(!s1.isempty())
//	{
//		postfix +=s1.pop();	
//	
//	}
	
	}
	string reverseoutput= stringReversal(postfix);
	return reverseoutput;
}



















////>>>>>>>>>>>>>>>>>>>>>>>>>>>
// string postfix="";
//	StackList<char> s2;//1
//	for(int i=0;i<infix.length();i++)//2
//	{ 
//		if(isalpha(infix[i]))//2.1 oprend
//		{
//			postfix=postfix+infix[i];//is amal ko concatination kehtey hai
//		}//2.1 oprend
//		else if(infix[i]=='(')//2.2 opening symbol
//		{
//			s2.push(infix[i]);
//		}//2.2 opening symbol
//		else if(infix[i]=='+'||infix[i]=='-'||infix[i]=='/'||infix[i]=='*'||infix[i]=='^')//2.3 oprater
//		{
//			if(s2.isempty())//2.3.1 is empty
//			{
//				s2.push(infix[i]);
//			}//2.3.1
//			else //2.3.2 non empty
//			{
//			while(!s2.isempty()&& s2.topvalue() != '(' && prec(s2.topvalue())> prec(infix[i]))
//			{
//				postfix +=s2.pop();
//			} //while
//			s2.push(infix[i]);				
//			}//2.3.2
//		}//2.3 oprater
//		else if(infix[i]==')')//2.4 closing symbol
//		{
//			while(s2.topvalue() != '(')
//			{
//					postfix +=s2.pop();
//			}
//			
//			s2.pop();
//		
//	
//		}//2.4 closing symbol
//	
//		
//	}//for 2
//	
//	if(!s2.isempty())
//	{
//		while(!s2.isempty())
//		{
//			postfix+=s2.pop();
//		}
//	}
//	return postfix;
//
//}///infix -> postfix
//
int prec(char a)
{
	if(a=='^')
	return  3;
	if(a=='*'||a=='/')
    return 2;
	if(a=='+'||a=='-')
    return 1;
    else
    return 1;
}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
string stringReversal(string ele)
{
	string output="";
	StackList<char> s1;
 	for(int i=0;i<ele.length();i++)
	{
		s1.push(ele[i]);
	}
int j=0;
	while(j<ele.length())
	{
		output=output+s1.pop();
		j++;
	}
	return output;
	
	
}
