#include <iostream>
#include <queue>
#include <stack>
using namespace std;

//5,7,1 -> 1,7,5

class QueueReverser {
private:
	queue<int> q;
public:
	QueueReverser() {

	}
	void enqueue(int val) {
		q.push(val);

	}

	void dequeue() {
		q.pop();
	}

	void RevereseUsingStack() {
		stack<int> st;

		while (!q.empty()) {
			st.push(q.front());
			q.pop();

		}

		while (!st.empty()) {
			q.push(st.top());
			st.pop();
		}
	}

	void display() {
		while (!q.empty()) {
			cout << q.front() << " ";
			q.pop();
		}
	}

	int size() {
		return q.size();
	}

	bool isEmpty() {
		if (q.empty()) {
			return true;
		}
		else {
			return false;
		}
	}
};


int main() {

	QueueReverser q1;
	q1.enqueue(5);
	q1.enqueue(7);
	q1.enqueue(1);
	q1.RevereseUsingStack();

	q1.display();



	return 0;
}