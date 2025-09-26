#include <iostream>
using namespace std;

//Stack: Last in First Out (LIFO), Queue : First in First Out (FIFO)
//Queue (opposite of stack)
//Queue functions: Enque() adds elements at the end, Deque() removes elements from the front

//Priority Queue (special queue): {val, priority value, ptr} 
//Ex: {1, 5, 0x1} -> {2, 3, NULL} since 5 > 3, it will be the first element in the queue 

struct node {
	int val;
	int priority;
	node* ptr;
};

class queue {
private:
	node* head = NULL;
public:
	node* createnode(int, int);
	void priority_enqueue(int, int);
	void dequeue();
	void display();
	//~queue();
};

node* queue::createnode(int x, int y) {
	node* newnode = new node;
	newnode->val = x;
	newnode->priority = y;
	newnode->ptr = NULL;
	return newnode;
}

void::queue::priority_enqueue(int x, int p) {
	node* temp = createnode(x, p);
	node* curr = head;
	node* prev = NULL;

	if (head == NULL) { //the head has the max prioity in an empty list
		head = temp;
		temp->ptr = NULL;
		return;
	}
	//if prev priority is < newnode priotiy
		//newnode should be the prev node
		//prev node should be the newnode
	if (curr->ptr == NULL) {
		if (head->priority < temp->priority) {
			temp->ptr = head;
			head = temp;
			return;
		}
		curr->ptr = temp;
		return;

	}

	if (head->priority < temp->priority) { //and there are more than one nodes
		temp->ptr = head;
		head = temp;
		return;
	}

	//2 cases left, tempprior has lowest priority and temprior is in between two nodes
	prev = curr;   //do the traversin here
	curr = curr->ptr;
	//addwhile loop around this and outside the while loop add the node
	 if ((prev->priority > temp->priority) && (curr->priority < temp->priority)) {
		//add the new node in between prev and curr
		prev->ptr = temp;
		temp->ptr = curr;
		return;
	}

	//while (curr->ptr != NULL) {
	//	curr = curr->ptr;
	//}
	//curr->ptr = temp;

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
	cout << "{ " << temp->val << " , " << temp->priority << " }" << " -> ";
	while (temp->ptr != NULL) {
		temp = temp->ptr;
		cout << "{ " << temp->val << " , " << temp->priority << " }" << " -> ";

		
	}
	//cout << temp->ptr->val;
}
/*queue::~queue() {
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
} */
int main() {
	// {1,10} ->
	// {1, 10} -> {2, 9} ->
	queue myqueue;

	myqueue.priority_enqueue(1, 9);
	myqueue.display();
	cout << "\n";
	myqueue.priority_enqueue(2, 10);
	myqueue.display();
	cout << "\n";
	myqueue.priority_enqueue(3, 15);
	myqueue.display();
	cout << "\n";
	myqueue.priority_enqueue(4, 12);
	myqueue.display();
	cout << "\n";
	myqueue.priority_enqueue(5, 4);
	myqueue.display();
	cout << "\n";
	//myqueue.dequeue();
	//myqueue.display();





	return 0;
}