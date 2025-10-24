#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



/*
class point {
	int x, y;
public:
	point(int x = 0, int y = 0) : x(x), y(y){}
	void print() {
		cout << "x: " << x << ", " << "y: " << y << endl;
	}
	point operator+(point &other) {
		return point(x + other.x, y + other.y);
	}
	//write an operator overloading function so we can find the point which is closer to the center (0,0) on the x axis
	bool operator<(point &other) {
		return x < other.x;
	}
}; */

class X {
	int dval;
public:
	X(int val) : dval(val) {}
	int getval() {
		return dval;
	}
	void print() {
		cout << dval << endl;
	}
};

bool compareX(X& a, X& b) {
	return a.getval() < b.getval();
}

int main() {

	vector<X> objects{X(5), X(2), X(8), X(1), X(9)};
	cout << "Before sort: " << endl;
	for (auto obj : objects) {
		obj.print();
	}
	sort(objects.begin(), objects.end(), compareX);
	cout << "After sort: " << endl;
	for (auto obj : objects) {
		obj.print();
	}


	/*
	point x1(1, 5);
	x1.print();
	point x2(10, 3);
	x2.print();

	//point p3 = p1 + p2;  need to overload + operator
	point x3 = x1 + x2;
	x3.print();
	if (x1 < x2) {
		cout << "x1 is closer to center" << endl;
	}
	else {
		cout << "x2 is closer to center" << endl;
	} */

	/*
	vector<int> v{ 5,1,9,3,7,3 };


	cout << "Before sort: " << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		cout << (*it) << " ";
	} 
	cout << endl;

	sort(v.begin(), v.end());

	cout << "After sort: (Ascending order): " << endl;

	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		cout << (*it) << " ";
	}
	cout << endl;

	cout << "After sort: (Descending order): " << endl;

	sort(v.begin(), v.end(), greater<int>());


	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		cout << (*it) << " ";
	}

	cout << endl;

	cout << "After removing duplicated: " << endl;

	v.erase(unique(v.begin(), v.end()));


	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		cout << (*it) << " ";
	} */




	return 0;
}