#include <iostream>
using namespace std;

struct node {
	node* ptr;
	int val;
};

class linkedlist {
private:
	node* head;
public:

	linkedlist() {
		head = NULL;
	}
	node* createnode(int i_val) {
		node* newnode = new node;
		newnode->val = i_val;
		newnode->ptr = NULL;
		return newnode;
	}

	void addnode(int i_val) {
		node* newnode = createnode(i_val);

		if (head == NULL) {
			head = newnode;
			return;
		}

		node* curr = head;
		while (curr->ptr != NULL) {
			curr = curr->ptr;
		}
		curr->ptr = newnode;
	}

	void printnode() {
		if (head == NULL) {
			cout << "Empty List\n";
			return;
		}
	
		node* curr = head;

		while (curr->ptr != NULL) {
			cout << curr->val << " ";
			curr = curr->ptr;
		}
		cout << curr->val << endl;
	}


	void cutinsertbefore(int index_start, int index_end, int index) {
		//initial list : 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
		//After cut(1, 3) and insert before index 5 :
		//1 -> 5 -> 2 -> 3 -> 4 -> 6 -> 7


		node* beforeStart = NULL;
		node* start = head;

		for (int i = 0; i < index_start; i++) {
			beforeStart = start;
			start = start->ptr;
		}

		node* afterEnd = NULL;
		node* end = start;

		for (int i = index_start; i < index_end; i++) {
			end = end->ptr;
		}

		afterEnd = end->ptr;


		node* insert = head;
		node* insertBefore = NULL;
		//start-> after end
		for (int i = 0; i < index; i++) {
			insertBefore = insert;
			insert = insert->ptr;
		}

		beforeStart->ptr = afterEnd;
		insertBefore->ptr = start;
		end->ptr = insert;	


	}

	void cutinsertafter(int index_start, int index_end, int index) {

		// ----- Find start and beforeStart -----
		node* beforeStart = NULL;
		node* start = head;

		for (int i = 0; i < index_start; i++) {
			beforeStart = start;
			start = start->ptr;
		}

		// ----- Find end and afterEnd -----
		node* end = start;
		for (int i = index_start; i < index_end; i++) {
			end = end->ptr;
		}

		node* afterEnd = end->ptr;

		// ----- Find insertion point (insert AFTER index) -----
		node* insert = head;

		for (int i = 0; i < index; i++) {
			insert = insert->ptr;
		}

		node* insertAfter = insert->ptr; // node AFTER the index

		// ----- DETACH segment -----
		if (beforeStart != NULL) {
			beforeStart->ptr = afterEnd;
		}
		else {
			head = afterEnd; // cutting from head
		}

		// ----- INSERT AFTER the index -----
		insert->ptr = start;     // attach start of cut segment
		end->ptr = insertAfter;  // attach end of cut segment
	}


};



int main() {

	linkedlist list;
	list.addnode(1);
	list.addnode(2);
	list.addnode(3);
	list.addnode(4);
	list.addnode(5);
	list.addnode(6);
	list.addnode(7);

	list.printnode();
	
	list.cutinsertbefore(1,3, 5);
	list.printnode();



	return 0;
}