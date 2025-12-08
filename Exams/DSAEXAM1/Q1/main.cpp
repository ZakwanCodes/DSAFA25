#include <iostream>
using namespace std;

class Matrix {
private:
	int** arr = NULL;
	int ROWS;
	int COLS;

public:
	Matrix(int, int);
	~Matrix();
	void setMatrix();
	void display();
	Matrix transpose() const;
};


Matrix::Matrix(int m, int n) {
	ROWS = m;
	COLS = n;
	arr = new int* [ROWS];
	arr[0] = new int[ROWS * COLS];

	for (int i = 1; i < ROWS; i++) {
		arr[i] = arr[0] + i * COLS;
	}

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			arr[i][j] = 0;
		}
	}
}

void Matrix::setMatrix() {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			arr[i][j] = (i + 1 + j);
		}
	}
}

Matrix Matrix::transpose() const {
	Matrix m1(COLS, ROWS);
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			m1.arr[j][i] = arr[i][j];
		}
	}
	cout << "transposed" << endl;
	m1.display();
	return m1;
}



void Matrix::display() {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}
}

Matrix::~Matrix() {
	delete[] arr[0];
	delete[] arr;
}

int main() {

	Matrix m1(2, 3);
	m1.setMatrix();
	m1.display();
	m1.transpose();

	
	return 0;
}