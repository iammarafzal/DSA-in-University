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
		void insertAt(int val, int index);
		void CI();
		void removeAt(int index);
		void removeFirst();
		void removeLast();
		void linearSearch(int target);
		bool isFound(int target);
		bool binarySearch(int target);
		void largestNum();
		int largestValueEND(int end);  // return max values index
		int largestValueST(int start);
		void selectionSortA();
		void selectionSortD();
		void bubbleSort();
		void insertionSort(int n);
		int LV();
		void mergeSort(int low, int high);
		void merge(int low, int mid, int high);
};

int ArrayList::LV(){
	int index = -1;
	int i =1;
	int maxVal = arr[0];
	while (i<this->currentIndex){
		if (maxVal < arr[i]){
			maxVal = arr[i];
			index = i;
		}
		i++;
	}
	return index;
}
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

void ArrayList::insertAt(int value, int index) {
	if (index < 0 || index > currentIndex){
		cerr<< "Invalid Index! \n";
	}
	if (currentIndex == size){
		resize();
	}
	for (int i=currentIndex; i>index; i--){
		arr[i] = arr[i-1];
	}
	arr[index] = value;
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
} // end of Binary Search

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

int ArrayList::largestValueEND(int end){
	int index = 0;
	for (int i=1; i<=end; i++){
		if (arr[index] < arr[i]){
			index = i;
		}
	}
	return index;
} // end of Largest Value --- returns index

int ArrayList::largestValueST(int start){
	int maxIndex = start;
	int maxNum = arr[start];
	for (int i=start+1; i<this->currentIndex; i++){
		if (arr[i] > maxNum){
			maxNum = arr[i];
			maxIndex = i;
		}
	}
	return maxIndex;
}

void ArrayList::bubbleSort(){
	bool isSorted = true;
	for (int i=0; i<currentIndex-1; i++){
		for (int j=0; j<currentIndex-i-1; j++){
			if (arr[j] > arr[j+1]){
				isSorted = false;
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
		if (isSorted == true){
			return;
		}
	}
} // end of Bubble Sort 

void ArrayList::selectionSortA(){
	for (int i=currentIndex-1; i>0; i--){
		int max_index = largestValueEND(i);
		int temp = arr[i];
		arr[i] = arr[max_index];
		arr[max_index] = temp;
	}
	
} // end of selection Sort

void ArrayList::selectionSortD(){
	for (int i=0; i<currentIndex-1; i++){
		int max_index = largestValueST(i);
		int temp = arr[i];
		arr[i] = arr[max_index];
		arr[max_index] = temp;
	}
	
} // end of selection Sort]

void ArrayList::insertionSort(int n){
	for (int k=1; k<n; k++){
		int key = arr[k];
		int j= k-1;
		
		while (j>=0 && arr[j]>key){
			arr[j+1] = arr[j];
			j = j-1;
		}
		arr[j+1] = key;
	}
} // end of Insertion Sort

void ArrayList::merge(int low, int mid, int high){
	int n = high - low +1;
	int* temp = new int[n];
	int left = low, right = mid + 1;
	int k = 0;
	
	while (left <= mid && right <= high){
		if (arr[left] <= arr[right]){
			temp[k++] = arr[left++];
		}
		else {
			temp[k++] = arr[right++];
		}
	}
	
	while (left <= mid){
		temp[k++] = arr[left++];
	}
	
	while (right <= high){
		temp[k++] = arr[right++];
	}
	
	for (int i=0; i<n; i++){
		arr[low + i] = temp[i];
	}
	
	delete[] temp;
}
void ArrayList::mergeSort(int low, int high){
//	int low = 0, high = this->size-1;
	int mid = (low + high) / 2;
	if (low == high){
		return;
	}
	this->mergeSort(low, mid);
	this->mergeSort(mid+1, high);
	this->merge(low, mid, high);
}
