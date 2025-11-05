#include <iostream>
#include <vector>
#include <string>
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
	bool operator>(const x& other) const {
		return dval > other.dval;
	}
	
};

ostream& operator<<(ostream& os, const x& a) {
	os << "x(" << a.getval() << ")";
	return os;
}


template <typename T>
void printVector(const vector<T>& vec, const string& name = "vector"){
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
	x max() {
		T maxItem = items[0];
		for (auto item : items) {
			if (item > maxItem) {
				maxItem = item;
			}
		}
		return maxItem;
	}
	x min() {
		T minItem = items[0];
		for (auto item : items) {
			if (item < minItem) {
				minItem = item;
			}
		}
		return minItem;
	}
	int sum() {
		int total = 0;
		for (auto item : items) {
			total += item.getval();
		}
		return total;
	}
	void sort() {
		for (int i = 0; i < items.size() - 1; i++) {
			for (int j = 0; j < items.size() - 1; j++) {
				if (items[j] > items[j + 1]) {
					T temp = items[j];
					items[j] = items[j + 1];
					items[j + 1] = temp;
				}
			}
		}

	}
	double average() {
		double avg = (double)sum() / items.size();
		return avg;
	}
	void display() const {
		printVector(items, "xmanager");
	}
};

int main(){
	xmanager<x> manager;
	manager.add(x(1));
	manager.add(x(15));
	manager.add(x(11));
	manager.add(x(2));
	manager.add(x(5));
	manager.add(x(8));

	

	cout << "Max Object: " << manager.max() << endl;
	cout << "Min Object: " << manager.min() << endl;
	cout << "Sum: " << manager.sum() << endl;
	
	manager.sort();
	manager.display();
	cout << "Average: " << manager.average() << endl;


	return 0;
}