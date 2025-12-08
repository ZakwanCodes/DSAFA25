#include <iostream>
#include <string>
#include <vector> //STL
using namespace std;

class student {
	float gpa; 
	int id;
public:
	student(int iid) :id(iid) {
		gpa = 2.5;
	}
	void setgpa(float igpa) {
		gpa = igpa;
	}
	void myprint() {
		cout << id << " " << gpa << endl;
	}
};

int main() {

	//vector<T> name_ofTheVector 

	//store integers in a vector

	/*vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i % 10);
	}

	for (int i = 0; i < 10; i++) {
		cout << v[i] << endl;
	}  */

	/*
	int size = 10;

	vector<int> v1(size); // creating a vector of size size 
	for (int i = 0; i < size; i++) {
		v1[i] = i % 10;
		cout << v1[i] << endl;
	}
	v1.push_back(10);
	cout << v1[10] << endl;

	cout << v1.at(10) << endl; */

	/*
	vector<string> v2;
	v2.push_back("abc");
	v2.push_back("cde");
	cout << v2.at(0) << endl;

	for (auto x : v2) {
		cout << x << endl;
	} */

	/*
	vector<int> v3;

	for (int i = 0; i < 10; i++) {
		v3.push_back(i * 2);
	}


	for (vector<int>::iterator it = v3.begin(); it != v3.end(); ++it) {
		cout << *it << endl;
		
	} */

	vector<student> vx;

	for (int i = 0; i < 10; i++) {
		vx.push_back(student(i));
	}

	vx[1].setgpa(3.7);

	for (vector<student>::iterator it = vx.begin(); it != vx.end(); ++it) {
		(*it).myprint();
		//or it->myprint();
	}


	



}