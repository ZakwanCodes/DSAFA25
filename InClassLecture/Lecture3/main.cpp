#include <iostream>
using namespace std;
//#define ROW 4
//#define COL 3


class mydynamic2Darray {
private:
	int** a = NULL; int ROW; int COL;
public:
	mydynamic2Darray(int rowinput, int colinput) {
		cout << "constructor is called" << endl;
		ROW = rowinput;
		COL = colinput; 
		a = new int* [ROW];
		a[0] = new int[ROW * COL];

		for (int i = 1; i < ROW; i++) {
			a[i] = a[0] + i * COL;
		}
		a[0][0] = 5;
		cout << a[0][0] << endl;
	}

	
	void set2DArray();

	void display();
	~mydynamic2Darray();
};

void mydynamic2Darray::set2DArray() {
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			a[i][j] = (i * ROW) + (j * COL);
		}
	} 
}
void mydynamic2Darray::display() {
	cout << "Display is called" << endl;
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
}

mydynamic2Darray::~mydynamic2Darray() {
	cout << "Destrucutor is called" << endl;
	delete[] a[0];
	delete[] a;
}



int main() {

	mydynamic2Darray my2Darray(4, 3); //constructor is called  here
	my2Darray.set2DArray();
	my2Darray.display();
	//destructor is called


	 /*
	int a = 5;
	int* ptr = &a;
	cout << "addr(a): " << ptr << endl;
	cout << "deref(a): " << *ptr << endl;

	// ptr stores address of a but double ptr stores address of ptr
	// derefereing double ptr gives address of ptr which is addr(a)
	// double dereferencing doubleptr gives value of a which is 5
	int** dptr = &ptr;
	cout << "ddr(ptr): " << dptr << endl;
	cout << "val of ptr: " << *dptr << endl;
	cout << "val of a: " << **dptr << endl; 
	*/

		



	/*
	// dynamic memory allocation of 2d array
	// we need to store array of pointers first
	int** a = new int* [ROW]; 
	a[0] = new int[ROW * COL];

	for (int i = 1; i < ROW; i++) {
		a[i] = a[0] + i * COL; 
	}

	//use it 
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			a[i][j] = i * ROW + j * COL;
		}
	}

	//print it

	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
	delete[] a[0];
	delete[] a;
	*/

	/*
	//static memory allocation of 2d array
	int A[ROW][COL] = { {1,2,3}, {4,5,6}, {7,8,9}, {10,11,12} };
	//ROW * COL = size of 2d array. Hence, 4x3= 12 elements in total in this array.
	//  0 1 2
	// 0
	// 1
	// 2
	// 3

	for (int i = 0; i < ROW; i++) { //rows
		for (int j = 0; j < COL; j++) { //cols
			cout << A[i][j] << " ";
		}
		cout << "\n";
	} 
	*/

	return 0;
}