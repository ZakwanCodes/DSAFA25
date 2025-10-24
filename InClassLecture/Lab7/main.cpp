#include <iostream>
using namespace std;

struct node {
	int data;
	int priority;
	string deparment_name;
	node* ptr;
};

class priority_queue {
private:
	node* head = NULL;

public:

	node* createnode(int, string, int);
	void priority_enqueue(int, string, int);
	void dequeue();
	void display();
	~priority_queue();

};

node* priority_queue::createnode(int x, string d, int p) {
	node* newnode = new node;
	newnode->data = x;
	newnode->priority = p;
	newnode->deparment_name = d;
	newnode->ptr = NULL;
	return newnode;
}

void priority_queue::priority_enqueue(int x, string d, int p) {
	node* newnode = createnode(x, d, p);
	node* curr = head;
	node* prev = NULL;

	if (head == NULL) {
		head = newnode;
		return;
	}
	if (head->ptr == NULL) {
		if (head->priority < newnode->priority) {
			newnode->ptr = head;
			head = newnode;
			return;
		}
		else {
			head->ptr = newnode;
			return;
		}
	}

	while (curr->ptr != NULL) {
		if (head->priority < newnode->priority) { //and there are more than one nodes
			newnode->ptr = head;
			head = newnode;
			return;
		}
		prev = curr;
		curr = curr->ptr;
		
		if (prev->priority > newnode->priority && curr->priority < newnode->priority) {
			prev->ptr = newnode;
			newnode->ptr = curr;
			return;
		}
	}
	curr->ptr = newnode;
	newnode->ptr = NULL;
}

void priority_queue::display() {
	node* curr = head;
	if (head == NULL) {
		cout << "Queue is empty" << endl;
		return;
	}
	while (curr != NULL) {
		cout << curr->data << " " <<  " " << curr->deparment_name << " " << curr->priority << endl;
		curr = curr->ptr;
	}
}

void priority_queue::dequeue() {
	node* temp = head;
	if (head == NULL) {
		cout << "Queue is empty" << endl;
		return;
	}
	head = head->ptr;
	delete temp;

}

priority_queue::~priority_queue() {
	node* curr = head;
	node* temp = NULL;
	while (curr->ptr != NULL) {
		temp = curr;
		curr = curr->ptr;
		delete temp;
	}
	delete curr;
}


int main() {
	priority_queue pqueue;
	pqueue.priority_enqueue(100, "Software", 100000);
	pqueue.priority_enqueue(101, "HR", 80000);
	pqueue.priority_enqueue(105, "Accounting", 90000);
	pqueue.priority_enqueue(110, "Manager", 120000);
	pqueue.priority_enqueue(200, "OfficeStaff", 60000);

	pqueue.display();
	cout << "----Dequeueing------- " << endl;

	pqueue.dequeue();
	pqueue.display();


	return 0;
}