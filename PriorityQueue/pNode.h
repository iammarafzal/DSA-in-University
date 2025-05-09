#include <iostream>
#include "F:\Programming\C++\DSA-in-University\LinkedList\Node.h"

using namespace std;

template <class T>
class pNode : public Node<T> {
	private:
		int priority;
		
	public:
		pNode (T info, int priority){
			this->setInfo(info);
			this->priority = priority;
		}
		void setPriority(int priority);
		int getPriority();
		
};

template <class T>
void pNode<T>:: setPriority(int priority){
	this->priority = priority;
}

template <class T>
int pNode<T>:: getPriority(){
	return this->priority;
}
