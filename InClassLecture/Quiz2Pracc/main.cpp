#include<iostream>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;

template<typename T>
void printContainer(vector<T> data) {
	for (const auto& x : data) {
		cout << x << " ";
	}
	cout << endl;
}


/*
struct node {
	int val;
	node* left;
	node* right;
};

class BST {
public:
	node* createnode(int num){
		node* newnode = new node;
		newnode->val = num;
		newnode->left = NULL;
		newnode->right = NULL;
		return newnode;
	}

	node* insertnode(node* root, int num) {
		if (root == NULL) {
			root = createnode(num);
		}
		else if (num <= root->val){
			root->left = insertnode(root->left, num);
		}
		else {
			root->right = insertnode(root->right, num);
		}
		return root;
	}

	node* search(node* root, int x) {
		if (root == NULL) {
			return NULL;
		}
		if (root->val == x) {
			return root;
		}
		if (x <= root->val) {
			return search(root->left, x);
		}
		if (x >= root->val) {
			return search(root->right, x);
		}
	}

	node* traverse(node* root) {
		if (root == NULL) {
			return NULL;
		}
		traverse(root->left);
		cout << root->val << " ";
		traverse(root->right);
	}
};

*/

/*2
class x {
	int num;
public:
	x(int i_num) :num(i_num) {};
	int getnum() const {
		return num;
	}

	bool operator<(const x &other) const{
		return num > other.num;
	}


}; */


/*3
class x {
	int num;
public:
	x(int i_num) :num(i_num) {};
	int getnum() const {
		return num;
	}
};*/


/*1 struct comparex {
	bool operator()(const x& num1, const x& num2) {
		return num1.getnum() > num2.getnum();
	}
}; */

int main() {


	vector<int> v1 = { 2,6,12,7,3 };
	printContainer(v1);

	vector<double> v2 = {4.2,7.8,9.2 };
	printContainer(v2);


	/*
	BST* bt = new BST;
	node* root = NULL;
	root = bt->insertnode(root, 5);
	root = bt->insertnode(root, 8);
	root = bt->insertnode(root, 5);
	root = bt->insertnode(root, 3);
	root = bt->insertnode(root, 9);


	bt->traverse(root);
	
	
	if (bt->search(root, 23)) {
		cout << "Found" << endl;
	}
	else {
		cout << "Not found" << endl;
	} */

	/*
	stack<x, vector<x>> st;
	
	for (int y : {4, 6, 1, 7, 3, 61}) {
		st.push(x(y));
	}

	while (!st.empty()) {
		cout << st.top().getnum() << " ";
		st.pop();
	}

	stack<int> stackk;
	
	for (int x : {3, 6, 1, 6, 2, 6, 36, 7}) {
		stackk.push(x);
	}

	while (!stackk.empty()) {
		cout << stackk.top() << " ";
		stackk.pop();
	}*/


	/*2
	priority_queue<x> pq;

	pq.push(x(4));
	pq.push(x(3));
	pq.push(x(5));
	pq.push(x(7));
	pq.push(x(21));


	vector<x> temp;

	while (!pq.empty()) {
		temp.push_back(pq.top());
		pq.pop();
	}

	sort(temp.begin(), temp.end());

	for (auto x : temp) {
		pq.push(x);
	}



	while (!pq.empty()) {
		cout << pq.top().getnum() << " ";
		pq.pop();
	} */


	/*1 
	priority_queue<x,vector<x>, comparex> pq;
	
	for (auto x : { 3,5,1,5,35,7,9 }) {
		pq.push(x);
	}

	while (!pq.empty()) {
		cout << pq.top().getnum() << " ";
		pq.pop();
	} */


	return 0;
}