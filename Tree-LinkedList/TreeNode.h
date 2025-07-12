#include <iostream>

using namespace std;

template <class T>
class TreeNode {
	private:
		TreeNode<T>* left;
		TreeNode<T>* right;
		T info;
		
	public:
		TreeNode (T info, TreeNode<T>* right=0, TreeNode<T>* left=0){
			this->info = info;
			this->left = left;
			this->right = right;
		}
		void setRight(TreeNode<T>* right);
		void setLeft(TreeNode<T> *left);
		TreeNode<T>* getRight();
		TreeNode<T>* getLeft();
		void setInfo(T info);
		T getInfo();		
};

template <class T>
void TreeNode<T>::setInfo(T info){
	this->info = info;
}

template <class T>
T TreeNode<T>::getInfo(){
	return this->info;
}

template <class T>
void TreeNode<T>::setRight(TreeNode<T>* right){
	this->right = right;
}

template <class T>
TreeNode<T>* TreeNode<T>::getRight(){
	return this->right;
}

template <class T>
void TreeNode<T>::setLeft(TreeNode<T>* left){
	this->left = left;
}

template <class T>
TreeNode<T>* TreeNode<T>::getLeft(){
	return this->left;
}
