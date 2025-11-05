#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class x {
	int dval;
public:
	x(int val) : dval(val) {}
	int getval() const { return dval; }
	bool operator<(const x& other) const {
		return dval < other.dval;
	}
	bool operator==(const x& other) const {
		return dval == other.dval;
	}
	bool operator>(const x& other) const{
		return dval > other.dval;
	}
};

ostream& operator<<(ostream& os, const x& a) {
	 os << "x(" << a.getval() << ")";
	 return os;	
}

template <typename T>
void printVector(const vector<T>& vec, const string& name = "vector") {
	cout << name << " : ";
	for (const auto& element : vec) {
		cout << element << " ";
	}
	cout << endl;
}

template<typename T>
class xmanager {
	vector<T> items;
public:
	void add(const T& item) {
		items.push_back(item);
		cout << "Added: " << item << endl;
	}
	void display() const {
		printVector(items, "xmanager");
	}
};


/*
template<typename container>
void printContainer(const container& cont) {
	cout << "Container elements: ";
	for (const auto& element : cont) {
		cout << element << " ";
	}
	cout << endl;
}

template<typename T>
void printContainer(queue<T> q) {
	cout << "Queue elements: ";
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}

template<typename T>
void printContainer(stack<T> s) {
	cout << "Stack elements: ";
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
} */



/*
template<typename T>
class calculator {
public:
	T add(T a, T b) {
		return a + b;
	}
};

template<>
class calculator<string> {
public:
	string add(string a, string b) {
		return a + b;
	}
}; */

int main() {

	xmanager<x> manager;
	manager.add(x(1));
	manager.add(x(5));
	manager.add(x(15));

	manager.display();

	/*
	vector<int> intvec = { 1,2,3,4,5 };
	printContainer(intvec);

	vector<double> doublevec = { 1.5,2.3,3,4,5 };
	printContainer(doublevec);

	queue<string> q;
	q.push("first");
	q.push("second");
	q.push("third");
	q.push("fourth");
	printContainer(q);

	stack<double> s;
	s.push(1.1);
	s.push(1.2);
	s.push(2.3);
	s.push(3.4);
	s.push(4.45);
	printContainer(s); */

	/*
	calculator<int> intcalc;
	cout << intcalc.add(5, 3) << endl;

	calculator<double> doublecalc;
	cout << doublecalc.add(2.5, 3.8) << endl;

	calculator<string> stringcalc;
	cout << stringcalc.add("Hello ", "World") << endl; */
}