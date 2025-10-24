#include <iostream>
#include <queue>
#include<vector>
using namespace std;


class x {
	int dval;
public:
	x(int data) : dval(data) {}
	int getval() const{
		return dval;
	}

};

struct comparex {
	bool operator() (const x &a, const x &b) {
		return a.getval() > b.getval();
	}
};

int main() {

	priority_queue<x,vector<x>, comparex> pq;
	pq.push(x(5));
	pq.push(x(2));
	pq.push(x(8));
	pq.push(x(1));
	pq.push(x(9));
	cout << pq.size() << endl;
	while (!pq.empty()) {
		cout << pq.top().getval() << ", ";
		pq.pop();
			
	}



/*
	queue<x> q;
	q.push(x(5));
	q.push(x(1));
	q.push(x(8));

	while (!q.empty()) {
		cout << q.front().getval() << ", ";
		q.pop();
	} */


	

	/*
	//priority_queue<int> pq;
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int x : { 5, 1, 9, 3, 7, 3, 10 }) {
		pq.push(x);
	}

	while (!pq.empty()) {
		cout << pq.top() << ", ";
		pq.pop();
	}
	cout << "\n";
	*/

	/*
	//priority_queue:
	int arr[] = { 5,1,9,3,7,3, 10};
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < static_cast<int>(sizeof(arr) / sizeof(int)); i++) {
		pq.push(arr[i]);
	}

	cout << "Out from pq: ";
	
	for (int i = 0; i < static_cast<int>(sizeof(arr)/sizeof(int)); i++) {
		cout << pq.top() << ", ";
		pq.pop();
	}

	cout << "\n"; */

	/*
	int arr[] = { 5,1,9,3,7,3, 10 };
	priority_queue<int> pq; // or priority_queue<int, vector<int>, less<int>> pq; less <int> is optional bc by default it is max-heap
	for (int i = 0; i < static_cast<int>(sizeof(arr) / sizeof(int)); i++) {
		pq.push(arr[i]);
	}

	cout << "Out from pq: ";

	for (int i = 0; i < static_cast<int>(sizeof(arr) / sizeof(int)); i++) {
		cout << pq.top() << ", ";
		pq.pop();
	}

	cout << "\n"; */

	//queue:
	/* queue<int> q;
	q.push(5);
	q.push(1);
	q.push(9);
	q.push(3);
	q.push(7);
	q.push(3);

	cout << "FIFO order: " << endl;
	//cout << q.empty() << endl;

	while (!q.empty()) {
		cout << q.front() << " ,";
		q.pop();
	} */

	return 0;
}