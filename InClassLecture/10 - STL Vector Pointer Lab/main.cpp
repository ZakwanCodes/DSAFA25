#include <iostream>
#include <string>
#include <vector> //STL
using namespace std;

class student {
	float gpa; int id; string grade; string gradYear;
public:
	student(int iid) :id(iid) {
		gpa = 2.5;
		grade = "B";
		gradYear = "2028";
	}
	void setgpa(float igpa) {
		gpa = igpa;
	}
	void setgrade(string igrade) {
		grade = igrade;
	}
	void setgradYear(string igradeYear) {
		gradYear = igradeYear;
	}
	void findMaxMin(vector<student> students) {
		vector<student>::iterator maxIt = students.begin();
		vector<student>::iterator minIt = students.begin();

		for (vector<student>::iterator it = students.begin(); it != students.end(); ++it) {
			if (it->gpa > maxIt->gpa) {
				maxIt = it;
			}
			if (it->gpa < minIt->gpa) {
				minIt = it;
			}
		}

		cout << "Max/Min GPA among students: " << endl;
		cout << "Highest GPA: " << maxIt->gpa << ", Grade: " << maxIt->grade << ", ID: " << maxIt->id << endl;
		cout << "Lowest GPA: " << minIt->gpa << ", Grade: " << minIt->grade << ", ID: " << minIt->id << endl;
	}

	void myprint() {
		cout << id << " " << gpa << " " << grade << " " << gradYear << endl;
	}
};

int main() {

	vector<student> vx;

	for (int i = 0; i < 10; i++) {
		vx.push_back(student(i));
	}

	vx[1].setgpa(3.7);
	vx[1].setgrade("A");
	vx[1].setgradYear("2026");
	vx[4].setgpa(1.3);
	vx[4].setgrade("F");
	vx[4].setgradYear("2029");


	for (vector<student>::iterator it = vx.begin(); it != vx.end(); ++it) {
		(*it).myprint();
		//or it->myprint();
		
	}
	vx[0].findMaxMin(vx);

	return 0;
}