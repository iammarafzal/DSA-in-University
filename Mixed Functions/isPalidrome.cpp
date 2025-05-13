#include <iostream>
#include "F:\Programming\C++\DSA-in-University\Stack\StackLinked.h"
using namespace std;

bool isPalindrome(string word){
	StackLinked<char> s;
	int size = word.length()/2, i = 0;
	
	while (i != size){
		s.push(word[i]);
		i++;
	}
	
	for (int i=size+1; i<word.length(); i++){
		if (s.topValue() != word[i]){
			return false;
		}
		s.pop();
	}
	return s.isEmpty();	
}

int main(){
    cout<< isPalindrome("blulb");
    return 0;
}
