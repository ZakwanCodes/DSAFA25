#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <fstream> //file stream to read file
//fstream library has ifstream and ofstream classes in it
//ifstream : used to read data from file
//ofstream : used t0 write data into file
using namespace std;

struct student {
	string name;
	string subject;
	int score;

	bool operator<(const student& other) const {
		return this->score > other.score;
	}
};


//put in vector 

//operator overloading for sorting
void sortStack(stack<student>& s) {
	vector<student> temp; 
	while (!s.empty()) {
		temp.push_back(s.top());
		s.pop();
	}

	sort(temp.begin(), temp.end());
	for (auto x : temp) {
		s.push(x);
	}

}

void sortQueue(queue<student>& q) {
	vector<student> temp;
	while (!q.empty()) {
		temp.push_back(q.front());
		q.pop();
	}

	sort(temp.begin(), temp.end());
	for (auto x : temp) {
		q.push(x);
	}
}

/*
class Student {
	string name; 
	double gpa;
public:
	Student() : name(""), gpa(0.0) {}
	Student(string t_name, double t_gpa) : name(t_name), gpa(t_gpa) {}
	string getName() {
		return name;
	}
	double getGpa() {
		return gpa;
	}
	void setGpa(double t_gpa) {
		gpa = t_gpa;
	}
}; */


int main() {
	//read input text file
	ifstream readInput; ofstream writeOutput;
	readInput.open("input.txt");
	writeOutput.open("output.txt");

	string name, subject; int score;

	vector<student> studentvector;
	stack<student> studentstack;
	queue<student> studentqueue;
	map<int, student> studentmap;
	//a. implement a map to store student objects 
	//b. sort the stack and the queue based on the score
	int initial_id = 100;
	while (readInput >> name >> subject >> score) {
		cout << name << " " << subject << " " << score << endl;

		student s = { name, subject, score };

		studentvector.push_back(s);

		studentstack.push(s);

		studentqueue.push(s);
		
		studentmap[initial_id++] = s;

		writeOutput << name << " : " << subject << " : " << score << endl;
	}

	/*for (auto x : studentvector) {
		cout << x.name << endl;
	} 

	for (int i = 0; i < studentvector.size(); i++) {
		cout << studentvector[i].name << " " << studentvector[i].subject << " " << studentvector[i].score << endl;
	} 
	
	for (vector<student>::iterator it = studentvector.begin(); it != studentvector.end(); it++) {
		cout << it->name << " " << it->subject << " " << it->score << endl;
	} 

	while (!studentstack.empty()) {
		cout << studentstack.top().name << " " << studentstack.top().subject << " " << studentstack.top().score << endl;
		studentstack.pop();
	}

	while (!studentqueue.empty()) {
		cout << studentqueue.front().name << " " << studentqueue.front().subject << " " << studentqueue.front().score << endl;
		studentqueue.pop();
	} */

	sortStack(studentstack);

	sortQueue(studentqueue);

	cout << endl << "sorting stack based on score:" << endl;
	while (!studentstack.empty()) {
		cout << studentstack.top().name << " " << studentstack.top().subject << " " << studentstack.top().score << endl;
		studentstack.pop();
	}

	cout << endl << "sorting queue based of score:" << endl;
	while (!studentqueue.empty()) {
		cout << studentqueue.front().name << " " << studentqueue.front().subject << " " << studentqueue.front().score << endl;
		studentqueue.pop();
	} 
	
	cout << endl << "printing map: " << endl;
	for (auto x : studentmap) {
		cout << x.second.name << " " << x.second.subject << " " << x.second.score << endl;
	} 



	system("pause");




	/*
	map<int, Student> students;

	students[100] = Student("Bob", 3.8);
	students[101] = Student("Peter", 3.1);

	//access student from map
	//find name of student with id = 100
	cout << "Name of the student with ID: 100 :: " << students[100].getName() << endl;
	cout << "Gpa of the student with ID: 100 :: " << students[100].getGpa() << endl; */



	return 0;
}