#include <iostream>
#include "TreeNode.h"
using namespace std;

template <class T>
class BinarySearchTree {
	private:
		TreeNode<T>* root;
		
	public:
		BinarySearchTree (){
			this->root = 0;
		}
		void insert(T info);
		void preOrder(TreeNode<T>* t_root);
		void postOrder(TreeNode<T>* t_root);
		void inOrder(TreeNode<T>* t_root);
		TreeNode<T>* getRoot();
		TreeNode<T>* search(T value);

};

template <class T>
TreeNode<T>* BinarySearchTree<T>::getRoot(){
	return this->root;
}

template <class T>
void BinarySearchTree<T>::insert(T info){
	TreeNode<T>* n = new TreeNode<T>(info);
	
	if (this->root == 0){ // first node of bst
		this->root = n;
	}
	else { // 
		TreeNode<T>* temp = this->root;
		
		while (true){
			if (info < temp->getInfo()){ // process LST
				if (temp->getLeft() == 0){
					temp->setLeft(n);
					return;
				}
				else {
					temp = temp->getLeft();
				}
			}
			else if (info > temp->getInfo()){
				if (temp->getRight() == 0){
					temp->setRight(n);
					return;
				}
				else {
					temp = temp->getRight();
				}
			}
			else {
				cerr<< "Duplicate values not allowed. \n";
				return;
			}
			
		}
	}
}

template <class T>
void BinarySearchTree<T>::preOrder(TreeNode<T>* t_root){
	if (t_root != 0){
		cout<< t_root->getInfo() <<"\t";
		this->preOrder(t_root->getLeft());
		this->preOrder(t_root->getRight());
	}
}

template <class T>
void BinarySearchTree<T>::inOrder(TreeNode<T>* t_root){
	if (t_root != 0){
		this->preOrder(t_root->getLeft());
		cout<< t_root->getInfo() <<"\t";
		this->preOrder(t_root->getRight());
	}
}

template <class T>
void BinarySearchTree<T>::postOrder(TreeNode<T>* t_root){
	if (t_root != 0){
		this->preOrder(t_root->getLeft());
		this->preOrder(t_root->getRight());
		cout<< t_root->getInfo() <<"\t";
	}
}
