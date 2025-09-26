#include <iostream>
using namespace std;

class mydynamicarray {
private
	int* ptr = NULL;
	int size;
	int capacity;
public:
	mydynamicarray(int capacity) {
		this->capacity = capacity; 
		size = 0;
		ptr = new int[capacity];
	}
	/*void resize() {
		int* newptr = new int[capacity * 2];
		copy(ptr, ptr + size, newptr);
		capacity *= 2;
		delete[] ptr;
		ptr = newptr;
	}*/
	void increaseArraySize(int*& data, int size, int newsize) {
		size = newsize;
		if (size < newsize) {
			int* newarrayptr = new int[newsize];
			copy(data, data + size, newarrayptr);
			cout << "newarrayptr: " << newarrayptr << endl;
			cout << "data(1): " << data << endl;
			delete[] data;
			data = newarrayptr;
			cout << "data(2): " << data << endl;
		}
		else {
			return;
		}
	}

	void push_back(int*& data, int size, int val) {
		//add val at the end of data ptr
		//check if data is full
		// increase data
		//else add val at the end of data 
		if (size == capacity) {
			increaseArraySize(data, size, newsize);
		}
		else {
			ptr[size] = val;
		}
	}
	/*void push_back(int num) {
		increaseArraySize(ptr, size, size);
		//if (size == capacity) {
		//	resize();
		//}
		ptr[size] = num;
		size++;

	} */

	void push_front(int num) {
		if (size == capacity) {
			increaseArraySize(ptr, size, size);

			//resize();

		}
		for (int i = size; i > 0; i--){
			ptr[i] = ptr[i - 1];
		}
		ptr[0] = num;
		size++;
	}

	void print() {
		for (int i = 0; i < size; i++) {
			cout << ptr[i] << " ";
		}
		
	}

	~mydynamicarray() {
		delete[] ptr;
	}


};


int main() {

	mydynamicarray arr(2);
	arr.push_back(arr.ptr, arr.size, 1);
	/*
	arr.push_back(1);
	arr.push_back(5);
	arr.push_front(10);
	arr.push_back(5);
	arr.push_back(2);
	arr.push_front(9);
	arr.push_back(8);
	arr.push_back(2);
	arr.push_front(7);    //7 9 10 1 5 5 2 8 2  */
	arr.print(); 
	return 0;
}