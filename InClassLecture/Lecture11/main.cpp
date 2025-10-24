#include <iostream>
#include <vector>
#define vsize 10
using namespace std;

class X {
	int dval;
public:
	X(int val) :dval(val) {}
	void print() {
		cout << dval << endl;
	}
};
/*
void print(vector<int>* v) {
	cout << "iterating using vector pointer by index" << endl;
	/*for (int i = 0; i < v->size(); i++) { //v.size()
		cout << (*v)[i] << endl; // v[i]
	} 
	for (vector<int>::iterator it = v->begin(); it!= v->end(); ++it) {
		cout << (*it) << endl;
	}
} */

int main() {
	vector<X>* myobject = new vector<X>();
	myobject->push_back(X(0));
	myobject->push_back(X(1));
	myobject->push_back(X(2));
	myobject->push_back(X(3));

	/*
	(*myobject)[2].print(); //v[0].print();

	for (int i = 0; i < myobject->size(); ++i) {
		(*myobject)[i].print();

	} */

	for (vector<X>::iterator it = myobject->begin(); it != myobject->end(); ++it) {
		it->print();
	}





	/*
	vector<int>* values; 
	values = new vector<int>();
	
	for(int i = 0; i < vsize; ++i) {
		values->push_back(i % vsize);
	}
	print(values); */


	return 0;
}