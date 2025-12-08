#include <iostream>
#include <map>
using namespace std;

//map key-id, value employee object

class Employee {
private: 
	int id;
	string name;
	string position;
	double salary;
public:
	Employee() {}
	Employee(int id, string name, string position, double salary) : id(id), name(name), position(position), salary(salary) {};
	int getId() const { return id; }
	string getName() const { return name; }
	string getPosition() const { return position; }
	double getSalary() const { return salary; }

	void display() const {
		cout << "ID: " << id << endl
			<< "Name: " << name << endl
			<< "Position: " << position << endl
			<< "Salary: $" << salary << endl << endl;
	}
};

void searchEmployee(map<int, Employee> mp, int id) {
	for (auto it = mp.begin(); it != mp.end(); ++it) {
		if (it->first == id) { 
			cout << "Employee with ID " << id << " found" << endl;
			it->second.display();
			return;
		}
	}
	cout << "Employee with ID " << id << " not found" << endl << endl;

}

int main() {

	map<int, Employee> EmployeeMap;

	Employee e1(1, "Bob", "Intern", 60000);
	Employee e2(2, "Zak", "Intern", 60000);
	Employee e3(3, "Ronald", "HQ", 100000);
	Employee e4(4, "Joe", "Senior", 80000);
	Employee e5(5, "Jessica", "Junior", 70000);

	EmployeeMap[1] = e1;
	EmployeeMap[2] = e2;
	EmployeeMap[3] = e3;
	EmployeeMap[4] = e4;
	EmployeeMap[5] = e5;


	searchEmployee(EmployeeMap, 1);
	searchEmployee(EmployeeMap, 3);
	searchEmployee(EmployeeMap, 5);
	searchEmployee(EmployeeMap, 6);






	return 0;
}