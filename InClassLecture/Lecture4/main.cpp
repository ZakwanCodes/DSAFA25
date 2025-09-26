#include <iostream>
using namespace std;

//Linked List allows us to use non-contiguous blocks to store data 

struct node {
	int val;
	node* ptr;
};

class linkedList {
private:
	node* head = NULL;
public:
	node* createnode(int);
	void add2List(int);
	void addHead(int);
	void display();
	~linkedList();
};

node* linkedList::createnode(int x) {
	node* newnode = new node;
	newnode->val = x;
	newnode->ptr = NULL;
	return newnode;
}

void linkedList::add2List(int x) {
	node* temp = createnode(x);
	node* curr = head;

	if (head == NULL) {
		temp->ptr = head;
		head = temp;
		return;
	}
	
	while (curr->ptr != NULL) {
		curr = curr->ptr;
	}
	curr->ptr = temp;
}

void linkedList::display() {
	if (head == NULL) {
		cout << "Empty List\n";
		return;
	}
	node* temp = head;
	while (temp != NULL) {
		cout << temp->val << " -> ";
		temp = temp->ptr;
	}
	cout << "NULL\n";
}

linkedList::~linkedList() {
	cout << "Deleting all the nodes\n";
	node* temp = head; 
	node* curr = NULL;
	while (temp != NULL) {
		curr = temp;
		temp = temp->ptr;
		delete curr;
	}
}

void linkedList::addHead(int x) {
	node* newnode = createnode(x);
	newnode->ptr = head;
	head = newnode;
}



int main() {
	//driver
	linkedList mylist;
	mylist.add2List(1);
	mylist.add2List(2);
	mylist.add2List(3);
	mylist.addHead(2);
	mylist.addHead(4);
	mylist.addHead(5);


	mylist.display();

	return 0;
}