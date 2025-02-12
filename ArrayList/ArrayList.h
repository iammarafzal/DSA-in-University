#include <iostream>
using namespace std;

class ArrayList {
	private:
		int size;
		int *arr;
		int currentIndex;
	
	public:
		ArrayList (int size){
			this->size = size;
			this->currentIndex = 0;
			
			arr = new int[this->size];
		} // parametric constructor
		
		void insert(int val);
		void display();
		void resize();
		void arraySize();
		void insert(int val, int index);
		void CI();
		void removeAt(int index);
};

void ArrayList::insert(int val){
	if (currentIndex >= size){	
		resize();
	}
	arr[this->currentIndex] = val;
	currentIndex++;	
	
} // insert function

void ArrayList::display(){
	for (int i=0; i<currentIndex; i++){
		cout<< arr[i] <<" ";
	}
	cout<< endl;
} // display function

void ArrayList::resize(){
	int updateCapacity = this->size*2;
	int *temp = new int[updateCapacity];
	for (int i=0; i<currentIndex; i++){
		temp[i] = arr[i];
	}
	
	delete[] arr;
	arr = temp;
	size = updateCapacity;
} // resize function

void ArrayList::arraySize(){
	cout<< "Size of array: " <<size <<endl;
} // Array size function

void ArrayList::insert(int val, int index) {
	if (index < 0 || index > currentIndex){
		cerr<< "Invalid Index! \n";
	}
	if (currentIndex == size){
		resize();
	}
	for (int i=currentIndex; i>index; i--){
		arr[i] = arr[i-1];
	}
	arr[index] = val;
	currentIndex++;
}

void ArrayList::CI(){
	cout<< this->currentIndex <<endl;
}

void ArrayList::removeAt(int index){
	if (index < 0 || index >= currentIndex){
		cerr<< "Invalid Index \n";
		return;
	}
	for (int i=index; i<currentIndex-1; i++){
		arr[i] = arr[i+1];
	}
	currentIndex--;
}