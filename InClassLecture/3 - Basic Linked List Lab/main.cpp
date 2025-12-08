#include <iostream>
using namespace std;

//Linked List allows us to use non-contiguous blocks to store data 
//Head -> node1 -> node2 ->... -> node n -> NULL

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
	void addHead(int);
	void display();
	void deleteHead();
	void deleteTail();
	void addAt(int, int);
	void deleteAt(int);
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
	nodeCount++;
}

void linkedList::deleteHead() {
	//1. check if list is empty
	//2. store the head node in a temp var
	//3. move the head pointer to the next node
	//4. delete the temo node
	if (nodeCount > 0) {
		nodeCount--;
	}
	if (head == NULL) {
		cout << "Empty list\n";
		return;
	}
	node* temp = head;
	head = head->ptr;
	delete temp;
}

void linkedList::deleteTail() {
	//1. check if list is empty
	//2. check if the list has only one node or multiple, if only one then delete the one node
	if (head == NULL) {
		cout << "Empty list\n";
		return;
	}
	if (head->ptr == NULL) {
		//only one node
		delete head;
		head = NULL;
		nodeCount--;
		return;
	}

	/*node* curr = head;
	while (curr->ptr->ptr != NULL) {
		curr = curr->ptr;
	}
	node* temp = curr->ptr;
	cout << "Last node addr: " << curr->ptr << endl;
	delete temp;
	cout << "Last node val: " << temp << endl;

	curr->ptr = NULL;
	*/


	node* curr = head;
	node* prev = NULL;
	while (curr->ptr != NULL) {
		prev = curr;
		curr = curr->ptr;
	}

	prev->ptr = NULL;
	delete curr;
	nodeCount--;


}

void linkedList::addAt(int index, int x) {
	if (index > nodeCount || index < 0) {
		cout << "Out of bound index\n";
		return;
	}
	if (index == 0) {
		addHead(x);
		return;
	}
	if (index == nodeCount) { //head is one node. nodeCount
		add2List(x);
		return;
	}
	int tempIndex = 0;
	node* prev = NULL;
	node* curr = head;

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
	if (index >= nodeCount || index < 0) {
		cout << "Out of bound index\n";
		return;
	}

	if (index == 0) {
		node* temp = head;
		head = head->ptr;
		delete temp;
		nodeCount--;
		return;
	}

	int tempIndex = 0;
	node* prev = NULL;
	node* curr = head;

	while (tempIndex != index) {
		prev = curr;
		curr = curr->ptr;
		tempIndex++;
	}

	node* temp = curr->ptr;
	prev->ptr = temp;
	delete curr;
	nodeCount--;

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

	mylist.deleteHead();
	mylist.display();

	mylist.deleteTail();
	mylist.display();

	mylist.addAt(2, 10);
	mylist.display();

	mylist.deleteAt(2);
	mylist.display();

	mylist.addAt(2, 612);
	mylist.display();

	mylist.deleteAt(4);
	mylist.display();

	mylist.addAt(4, 21);
	mylist.display();

	mylist.deleteAt(0);
	mylist.display();


	return 0;
}