#include<iostream>
#include<queue>
using namespace std;

class StackUsingQueues {
private:
    queue<int> q1, q2;

public:

    void push(int x) {
        // Step 1: push new element into q2
        q2.push(x);

        // Step 2: move everything from q1 → q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Step 3: move everything back into q1 so q1 always holds the stack
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    void pop() {
        if (!q1.empty()) {
            q1.pop();
        }
    }

    int top() {
        if (!q1.empty()) {
            return q1.front();
        }
        return -1; // or throw
    }

    bool empty() {
        return q1.empty();
    }

    int size() {
        return q1.size();
    }

    void display() {
        queue<int> temp = q1;
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    StackUsingQueues stack;
    stack.push(4);
    stack.push(5);
    stack.push(7);
    stack.push(9);

    stack.display();  // 9 7 5 4

    cout << "Top: " << stack.top() << endl; // 9
    stack.pop();
    cout << "After pop top: " << stack.top() << endl; // 7

    return 0;
}
