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

    // --------------------------
    // CUT AND INSERT BEFORE
    // --------------------------
    void cutAndInsertBefore(int index_start, int index_end, int index) {
        if (head == NULL) return;

        node* beforeStart = NULL;
        node* start = head;
        node* prev = NULL;

        // find start
        for (int i = 0; i < index_start; i++) {
            prev = start;
            start = start->ptr;
        }
        beforeStart = prev;

        // find end
        node* end = start;
        for (int i = index_start; i < index_end; i++) {
            end = end->ptr;
        }
        node* afterEnd = end->ptr;

        // CUT THE SUBLIST OUT
        if (beforeStart != NULL) {
            beforeStart->ptr = afterEnd;
        }
        else {
            head = afterEnd; // sublist starts at head
        }

        end->ptr = NULL; // detach sublist

        // --------------------------
        // INSERT BEFORE index
        // --------------------------

        // inserting at the head
        if (index == 0) {
            end->ptr = head;
            head = start;
            return;
        }

        // find node before insertion point
        node* temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->ptr;
        }

        node* oldNext = temp->ptr;

        temp->ptr = start;
        end->ptr = oldNext;
    }

    // --------------------------
    // DISPLAY
    // --------------------------
    void display() {
        node* temp = head;
        while (temp != NULL) {
            cout << temp->val;
            if (temp->ptr != NULL)
                cout << " -> ";
            temp = temp->ptr;
        }
        cout << endl;
    }

    // --------------------------
    // DESTRUCTOR
    // --------------------------
    ~SublistManipulator() {
        node* curr = head;
        while (curr != NULL) {
            node* next = curr->ptr;
            delete curr;
            curr = next;
        }
    }
};


int main() {

    SublistManipulator s1;

    s1.addNode(1);
    s1.addNode(5);
    s1.addNode(3);
    s1.addNode(2);
    s1.addNode(0);





    return 0;
}
