#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//final exam : Thrusday 11;40 am - 3:00 pm dec11
//sorting: bubble sort

template<typename T>
void bubbleSort(vector<T> &a) {
	size_t n = a.size();

	if (n < 2) return;

	bool swapped;

	for (size_t i = 0; i < n - 1; i++) {
		swapped = false;

		for (size_t j = 0; j < n - 1; j++) {
			if (a[j] < a[j+1]) {
				swap(a[j], a[j + 1]);
				swapped = true;
			}
		}
		if (!swapped) break;
	}
}


template<typename T>
void insertionSort(vector<T> &a) {
	size_t n = a.size();
	for (int i = 1; i < n; i++) {
		T key = a[i];
		size_t j = i;
		while (j > 0 && a[j-1] > key) {
			a[j] = a[j - 1];
			--j;
		}
		a[j] = key;
	}
}

template<typename T>
void selectionSort(vector<T> &a) {
	size_t n = a.size();
	for (int i = 0; i < n; i++) {
		size_t minindex = i;
		for (size_t j = i + 1; j < n; j++) {
			if (a[j] < a[minindex]) {
				minindex = j;
			}
		}
		if (minindex != i) {
			swap(a[i], a[minindex]);
		}
	}
}

template <typename T>
void merge(vector<T>& a, int left, int mid, int right) {
	int n1 = mid - left + 1; //size of the left part
	int n2 = right - mid; //size of the right part

	vector<T> L(n1);
	vector<T> R(n2);

	for (int i = 0; i < n1; i++) L[i] = a[left + i];
	for (int j = 0; j < n2; j++) R[j] = a[mid + j + 1];

	int i = 0,j = 0, k = left;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			//a[k++] = L[i++];
			a[k] = L[i]; k++; i++;
		}
		else {
			a[k] = R[j]; k++; j++;
		}
	}

	//copy the remaining elements
	while (i < n1) {
		a[k++] = L[i++];
	}
	while (j < n2) {
		a[k++] = R[j++];
	}
}

template <typename T>
void mergesortrecursion(vector<T>& a, int left, int right) {
	
	if (left >= right) return;

	int mid = left + (right - left) / 2;

	mergesortrecursion(a, left, mid);
	mergesortrecursion(a, mid + 1, right);
	merge(a, left, mid, right);

}

template <typename T>
void mergeSort(vector<T>& a) {
	if (!a.empty()) {
		mergesortrecursion(a, 0, static_cast<int>(a.size())-1);
	}
}


template<typename T>
int partition(vector<T> &a, int lo, int hi) {
	int pivot = a[hi];

	int i = lo;

	for (int j = lo; j < hi; j++) {
		if (a[j] <= pivot){
			swap(a[i], a[j]);
			i++;
		}
	}

	swap(a[i], a[hi]);
	return i;
}

template<typename T>
void quickSort(vector<T>& a, int lo, int hi) {
	if (lo >= hi || lo < 0) return;
	int p = partition(a, lo, hi);

	quickSort(a, lo, p - 1);
	quickSort(a, p + 1, hi);
}

template<typename T>
void heapify(vector<T> &a, int n, int i) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	//if left is larger than root then reset the largest
	if (left < n && a[left] > a[largest]) {
		largest = left;
	}
	//if right is larger than root then reset the largest
	if (right <  n && a[right] > a[largest]) {
		largest = right;
	}
	//if the largest is not the root
	if (largest != i) {
		swap(a[i], a[largest]);
		heapify(a, n, largest);
	}
}

//heap-sort
//transform array from left to right into a tree  
//swap any values in the trees where the parent node < child node (heapify)
//transform back the tree into the array //bfs
//swap the first index and the last index in the array
//leave the last index untouched, repeat the process on the array from index 0 to the index before the untouched index

template<typename T>
void heapSort(vector<T> &a) {
	size_t n = a.size();

	//max heap: the parent is always greater than child (we're using this)
	//min heap: the parent is always less than the child
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(a, n, i);
	}
	//move the max element to the end
	
	for (int i = n - 1; i > 0; --i) {
		swap(a[0], a[i]);
		heapify(a, i, 0);
	} 
}

template<typename T>
void sortdigits(vector<T> &a, int exp) {
	int n = a.size();
	vector<T> output(n);

	int count[10] = { 0 };

	//count digits
	for (int i = 0; i < n; i++) {
		int digit = (a[i] / exp) % 10;
		count[digit]++;
	}

	//turn the counts into prefix sums
	for (int i = 1; i < 10; ++i) {
		count[i] += count[i - 1];
	}

	//build the array
	for (int i = n - 1; i >= 0; --i) {
		int digit = (a[i] / exp) % 10;
		output[count[digit] - 1] = a[i];
		count[digit]--;
	}

	//copy back the output to a 
	for (int i = 0; i < n; i++) {
		a[i] = output[i];
	}
}

//radix-sort: good for arrays with variations in digits
template<typename T>
void radixSort(vector<T> &a) {
	if (a.empty()) return;

	//find the max to know the number of digits
	int maxval = *max_element(a.begin(), a.end());

	//sort all the digits
	//exp = 1 (units), exp = 10 (tens), exp = 100 (hundereds)
	for (int exp = 1; maxval / exp > 0; exp *= 10) {
		sortdigits(a, exp);
	}

}

int main() {

	vector<int> data = {6, 5, 3, 1, 8, 7, 2, 4};

	//insertionSort(data);
	//bubbleSort(data);
	//selectionSort(data);
	//mergeSort(data);
	//quickSort(data, 0, data.size() - 1);
	//heapSort(data);
	radixSort(data);
	for (int x : data) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}