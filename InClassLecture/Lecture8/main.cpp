#include <iostream>
using namespace std;

//Stack: Last in First Out (LIFO), Queue : First in First Out (FIFO)
//Queue (opposite of stack)
//Queue functions: Enque() adds elements at the end, Deque() removes elements from the front


struct node {
	int val;
	node* ptr;
};

class queue {
private:
	node* head = NULL;
public:
	node* createnode(int);
	void enqueue(int);
	void dequeue();
	void display();
	~queue();
};	

node* queue::createnode(int x) {
	node* newnode = new node;
	newnode->val = x;
	newnode->ptr = NULL;
	return newnode;
}

void queue::enqueue(int x) {
	node* temp = createnode(x);
	node* curr = head;

	if (head == NULL) {
		head = temp;
		temp->ptr = NULL;
		return;
	}

	//find tail node
	while (curr->ptr != NULL) {
		curr = curr->ptr;
	}
 
	curr->ptr = temp;
	temp->ptr = NULL;
}
void queue::dequeue() {

	if (head == NULL) {
		cout << "Empty list\n";
		return;
	}
	node* temp = head;
	head = head->ptr;
	delete temp;


}
void queue::display() {
	if (head == NULL) {
		cout << "Empty List\n";
		return;
	}
	node* temp = head;
	while (temp->ptr != NULL) {
		cout << temp->val << " -> ";
		temp = temp->ptr;
	}
	cout << temp->val << "\n";
	//cout << temp->ptr->val;
}
queue::~queue() {
	if (head == NULL) {
		cout << "Empty list\n";
		return;
	}

	cout << "\nDeleting all the nodes\n";
	node* temp = head;
	temp = temp->ptr;
	node* curr = NULL;

	//need to take care for only head - edge case
	if (temp->ptr == head) {
		delete head;
		return;
	}

	while (temp->ptr != NULL) {
		curr = temp;
		temp = temp->ptr;
		delete curr;

	}
	delete head;
}
int main() {
	queue myqueue;

	myqueue.enqueue(10);
	myqueue.enqueue(2);
	myqueue.enqueue(11);
	myqueue.display();
	cout << endl;
	myqueue.dequeue();
	myqueue.display();





	return 0;
}