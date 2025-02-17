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
		void removeFirst();
		void removeLast();
		void linearSearch(int target);
		bool isFound(int target);
		bool binarySearch(int target);
		void largestNum();
		void Sort();
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
} // Insert at some index

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
} // remove from some index

void ArrayList::removeLast(){
	currentIndex = currentIndex-1;
} // remove last element

void ArrayList::removeFirst(){
	for (int i=0; i<currentIndex; i++){
		arr[i] = arr[i+1];
	}
	currentIndex--;
} // remove first element

void ArrayList::linearSearch(int target){
	int i = 0;
	while (i<currentIndex && target != arr[i]){
		i++;
	}
	if (i == currentIndex){
		cout<< target <<" not found. \n";
	}
	else {
		cout<< target <<" is at " <<i <<" index. \n";
	} 
} // linear search function

bool ArrayList::isFound(int target){
	int i = 0;
	while (i < currentIndex){
		if (target == arr[i]){
			return true;
		}
		i++;
	}	
	return false;
} // isFound function ---- return 1 if found else 0

bool ArrayList::binarySearch(int target) {
    int b = 0;
    int e = currentIndex - 1;
    int m; 

    while (b <= e) {
        m = (b + e) / 2; 
        if (arr[m] == target) {
            return true;
        }
        else if (target > arr[m]) {
            b = m + 1;
        }
        else {
            e = m - 1;
        }
    }
    return false;
} // Binary Search

void ArrayList::largestNum(){
	int maxNum = INT_MIN;
	int index = -1;

	for (int i=0; i<this->currentIndex; i++){
		if (arr[i] > maxNum){
			maxNum = arr[i];
			index = i;
		}
	}
	if (index >=0){
		cout<< "Largest number " <<maxNum <<" is at " <<index <<" index. \n";
	}
	else {
		cout<< "Array is null. \n";
	}
} // Index of Largest Number in Array

void ArrayList::Sort(){
	int temp;
	for (int i=0; i<this->currentIndex; i++){
		for (int j=0; j<this->currentIndex-i-1; j++){
			if (arr[j] > arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}