#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

class x {
	int dval;
public:
	x(int v) : dval(v) {}
	int getval() {
		return dval;
	}
};

bool operator<(x &a, x& b) {
	return a.getval() < b.getval();
}

int main(){
	vector<int> v{ 5,1,9,8,2,3 };

	//reverse this set of integers in the vector

	stack<x> st;

	for (int y : v) {
		st.push(x(y));
	}

	vector<x> temp;
	//move the elements from st to vector
	while (!st.empty()) {
		temp.push_back(st.top().getval());
		st.pop();
	}


	for (auto x : temp) {
		cout << x.getval() << " ";
	}
	cout << endl;

	//sort temp
	sort(temp.begin(), temp.end());
	//add temp elements to stack

	for (auto x : temp) {
		cout << x.getval() << " ";
	}
	cout << endl;

	for (auto x : temp) {
		st.push(x);
	}

	while (!st.empty()) {
		cout << st.top().getval() << " ";
		st.pop();
	}


	/*
	vector<int> v{5,1,9,8,2,3};

	//reverse this set of integers in the vector

	stack<int> st;

	for (int x : v) {
		st.push(x);
	}
	
	vector<int> temp;
	//move the elements from st to vector
	while (!st.empty()) {
		temp.push_back(st.top());
		st.pop();
	}

	//sort temp
	sort(temp.begin(), temp.end());
	
	for (int x : temp) {
		cout << x << " ";
	}
	cout << endl;

	//add temp elements to stack

	for (int x : temp) {
		st.push(x);
	}

	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}


	/*

	/*vector<int> v{5,1,9,8,2,3};

	//reverse this set of integers in the vector

	stack<int> st;

	for (int x : v) {
		st.push(x);
	}
	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	} */




	/*
	stack<x> st;

	st.push(x(5));
	st.push(x(7));
	st.push(x(6));
	st.push(x(8));

	while (!st.empty()) {
		cout << st.top().getval() << endl;
		st.pop();
	} */



	/*
	stack<int, vector<int>> st;

	for (int x : {5, 6, 8, 9, 7}) {
		st.push(x);
	}

	while (!st.empty()) {
		cout << st.top() << endl;
		st.pop();
	} */

	/*
	stack<int> st;
	st.push(5);
	st.push(7);
	st.push(6);
	st.push(8);

	while (!st.empty()) {
		cout << st.top() << endl;
		st.pop();
	} */

	return 0;
}