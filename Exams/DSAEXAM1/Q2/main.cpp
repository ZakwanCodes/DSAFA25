#include <iostream>
using namespace std;

struct node {
    int val;
    node* ptr;
};

class SublistManipulator {
private:
    node* head;

public:
    SublistManipulator() {
        head = NULL;
    }

    void addNode(int value) {
        node* newnode = new node;
        newnode->val = value;
        newnode->ptr = NULL;

        if (head == NULL) {
            head = newnode;
            return;
        }

        node* temp = head;
        while (temp->ptr != NULL) {
            temp = temp->ptr;
        }
        temp->ptr = newnode;
    }

    // -------------------------------
    // Helper: Cut out sublist safely
    // -------------------------------
    void cutSublist(int index_start, int index_end, node*& start, node*& end) {
        start = head;
        node* prev = NULL;

        // validate indices
        if (index_start < 0 || index_end < index_start) {
            start = end = NULL;
            return;
        }

        // move to start
        for (int i = 0; i < index_start && start != NULL; i++) {
            prev = start;
            start = start->ptr;
        }

        if (start == NULL) { // start index out of bounds
            end = NULL;
            return;
        }

        // move to end
        end = start;
        for (int i = index_start; i < index_end && end->ptr != NULL; i++) {
            end = end->ptr;
        }

        // detach sublist
        node* afterEnd = end->ptr;
        if (prev != NULL) {
            prev->ptr = afterEnd;
        }
        else {
            head = afterEnd; // cutting from head
        }
        end->ptr = NULL;
    }

    // -------------------------------
    // Insert BEFORE index
    // -------------------------------
    void cutAndInsertBefore(int index_start, int index_end, int index) {
        node* start, * end;
        cutSublist(index_start, index_end, start, end);
        if (start == NULL) return; // nothing to insert

        if (index <= 0 || head == NULL) { // insert at head
            end->ptr = head;
            head = start;
            return;
        }

        // find node before insertion point
        node* temp = head;
        for (int i = 0; i < index - 1 && temp->ptr != NULL; i++) {
            temp = temp->ptr;
        }

        node* oldNext = temp->ptr;
        temp->ptr = start;
        end->ptr = oldNext;
    }

    // -------------------------------
    // Insert AFTER index
    // -------------------------------
    void cutAndInsertAfter(int index_start, int index_end, int index) {
        node* start, * end;
        cutSublist(index_start, index_end, start, end);
        if (start == NULL) return; // nothing to insert

        node* temp = head;
        if (temp == NULL) { // empty list
            head = start;
            return;
        }

        for (int i = 0; i < index && temp->ptr != NULL; i++) {
            temp = temp->ptr;
        }

        // temp might still be valid node
        node* oldNext = temp->ptr;
        temp->ptr = start;
        end->ptr = oldNext;
    }

    // -------------------------------
    // Display
    // -------------------------------
    void display() const {
        node* temp = head;
        while (temp != NULL) {
            cout << temp->val;
            if (temp->ptr != NULL) cout << " -> ";
            temp = temp->ptr;
        }
        cout << endl;
    }

    // -------------------------------
    // Destructor
    // -------------------------------
    ~SublistManipulator() {
        node* curr = head;
        while (curr != NULL) {
            node* next = curr->ptr;
            delete curr;
            curr = next;
        }
    }
};

// -------------------------------
// TESTING
// -------------------------------
int main() {
    SublistManipulator s;

    s.addNode(1);
    s.addNode(2);
    s.addNode(3);
    s.addNode(4);
    s.addNode(5);
    s.addNode(6);
    s.addNode(7);

    cout << "Initial list: ";
    s.display();

    s.cutAndInsertBefore(1, 3, 5);
    cout << "\nAfter cut(1,3) and insert before index 5:\n";
    s.display();

    s.cutAndInsertAfter(2, 4, 5);
    cout << "\nAfter cut(2,4) and insert after index 5:\n";
    s.display();

    return 0;
}
