#include <iostream>
using namespace std;

//stack: last in first out data structure (the last elemend added is the first one to be removed)
//important functions: 
// push(): allows us to add elements on the top of the stack
// pop(): allows us to remove the top element from the stack. Pop can remove all elements 
// isEmpty(): checks if the stack is empty, used in pop() to take care of empty stack case

struct node {
	int val;
	node* ptr;
};

class stack {
private:
	node* head = NULL;
public:
	node* createnode(int);
	void PUSH(int);
	int POP();
	void displayStack();
	bool isEmpty();
	void reverseStack();
	~stack();
};

node* stack::createnode(int x){
	node* newnode = new node;
	newnode->val = x;
	newnode->ptr = NULL;
	return newnode;
}

bool stack::isEmpty() {
	if (head == NULL) {
		return true;

	}
	return false;
}
void stack::PUSH(int x) {

	node* temp = createnode(x);
	node* curr = head;

	if (head == NULL) {
		temp->ptr = NULL;
		head = temp;
		return;
	}

	//find tail node
	while (curr->ptr != NULL) {
		curr = curr->ptr;
	}
	//curr->ptr = temp; 

	curr->ptr = temp;
	temp->ptr = NULL;
}

int stack::POP() {
	int x;
	if (isEmpty()) {
		return 0;
	}
	if (head->ptr == NULL) {
		//only one node
		x = head->val;
		delete head;
		head = NULL;
		return x;
	}
	node* curr = head;
	node* prev = NULL;
	while (curr->ptr != NULL) {
		prev = curr;
		curr = curr->ptr;
	}

	prev->ptr = NULL;
	x = curr->val;
	delete curr;

	return x;
}

void stack::reverseStack() {
	//create a temp stack T
	//POP() from original stack S
	// PUSH() into T
	//repeat until S is empty
	//Assign head to the T
	// S is the reverse stack of T
	int x; node* temp_head = NULL;

	while (!isEmpty()) {
		x = POP();
		node* temp = createnode(x);
		node* curr = temp_head;


		if (temp_head == NULL) {
			temp_head = temp;
		}
		else {
			while (curr->ptr != NULL) {
				curr = curr->ptr;
			}
			curr->ptr = temp;
		}
	}
	head = temp_head;
}





void stack::displayStack() {
	if (isEmpty()) {
		cout << "Empty stack\n";
		return;
	}
	node* temp = head;
	cout << temp->val << " -> ";

	while (temp->ptr != NULL) {
		temp = temp->ptr;
		cout << temp->val << " -> ";

	}
	//cout << temp->ptr->val << "\n";
}

stack::~stack() {
	if (isEmpty()) return;


	node* temp = head;
	//temp = temp->ptr;
	node* curr = NULL;


	while (temp->ptr != NULL) {
		curr = temp;
		temp = temp->ptr;
		delete curr;

	}
	delete temp;
}


int main() {
	stack s1;
	s1.PUSH(10);
	s1.PUSH(5);
	s1.PUSH(7);
	s1.PUSH(6);
	s1.PUSH(2);
	s1.displayStack();
	cout << endl;
	s1.POP();
	s1.displayStack();
	cout << endl;
	s1.reverseStack();
	s1.displayStack();

	return 0;
}