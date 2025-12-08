#include <iostream>
using namespace std;

//Circular linked list
//Head -> node1 -> node2 ->... -> node n -> tail ->head
struct node {
	int val;
	node* ptr;
};

class linkedList {
private:
	node* head = NULL;
	int nodeCount = 0;
public:
	node* createnode(int);
	void add2List(int);
	void addAt(int, int);
	void deleteAt(int);
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
	nodeCount++;
	node* curr = head;

	if (head == NULL) {
		temp->ptr = temp;
		head = temp;
		return;
	}

	//find tail node
	while (curr->ptr != head) {
		curr = curr->ptr;
	}
	//curr->ptr = temp; 
	
	curr->ptr = temp;
	temp->ptr = head;
}

void linkedList::display() {
	if (head == NULL) {
		cout << "Empty List\n";
		return;
	}
	node* temp = head;
	while (temp->ptr != head) {
		cout << temp->val << " -> ";
		temp = temp->ptr;
	}
	cout << temp->val << "\n";
	cout << temp->ptr->val << "-> ....\n";
}

linkedList::~linkedList() {
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

	while (temp->ptr != head) {
		curr = temp;
		temp = temp->ptr;
		delete curr;

	}
	delete head;
}



void linkedList::addAt(int index, int x) {
	if (index > nodeCount || index < 0) {
		cout << "Out of bound index\n";
		return;
	}

	node* prev = NULL;
	node* curr = head;

	if (index == 0) {
		//createnode(index);
		if (head == NULL) {
			node* newnode = createnode(x);
			newnode->ptr = newnode;
			head = newnode;
			nodeCount++;
			return;
		}
		else {
			while (curr->ptr != head) {
				curr = curr->ptr;
			}
			node* newnode = createnode(x);
			curr->ptr = newnode;
			newnode->ptr = head;
			head = newnode;
			nodeCount++;
			return;
		}
		
	}
	if (index == nodeCount) { //head is one node. nodeCount
		add2List(x);
		return;
	}
	
	int tempIndex = 0;

	while (tempIndex < index) {
		prev = curr;
		curr = curr->ptr;
		tempIndex++;
	}
	node* tempNode = createnode(x); //create a newnode
	prev->ptr = tempNode; //add new node to the prev node
	tempNode->ptr = curr; //add curr node to the temp node
	nodeCount++;
}

void linkedList::deleteAt(int index) {
	if (index > nodeCount -1 || index < 0) {
		cout << "Out of bound index\n";
		return;
	}
	node* prev = NULL;
	node* curr = head;
	if (index == 0) {
		if (head->ptr == head) { //  only one node in the list
			delete head;
			head = NULL;
		}
		else {
			node* curr = head;
			while (curr->ptr != head) {
				curr = curr->ptr;
			}
			node* temp = head;
			head = head->ptr;
			curr->ptr = head;
			delete temp;
		}
		nodeCount--;
		return;
	}

	int tempIndex = 0;

	while (tempIndex != index) {
		prev = curr;
		curr = curr->ptr;
		tempIndex++;
	}

	prev->ptr = curr->ptr;
	delete curr;
	nodeCount--;
}



int main() {
	//driver
	linkedList mylist;
	
	mylist.add2List(1);
	mylist.add2List(2);
	mylist.add2List(3);
	mylist.add2List(4);
	mylist.add2List(5);
	mylist.display();
	mylist.addAt(2, 9);
	mylist.display();
	mylist.addAt(6, 123);
	mylist.display();
	mylist.addAt(0, 222);
	mylist.display();
	mylist.deleteAt(0);
	mylist.display();
	mylist.deleteAt(6);
	mylist.display();
	mylist.deleteAt(2);
	mylist.display();

	
	return 0;
}