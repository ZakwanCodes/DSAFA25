#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> mainStack;
    stack<int> minStack;

public:
    MinStack() {}

    void push(int x) {
        mainStack.push(x);

        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        }
        else {
            minStack.push(minStack.top());
        }
    }

    void pop() {
        if (!mainStack.empty()) {
            mainStack.pop();
            minStack.pop();
        }
    }

    int top() {
        return mainStack.top();
    }

    int getMin() {
        return minStack.top();
    }

    void display() {
        stack<int> tempMain = mainStack;
        stack<int> tempMin = minStack;

        cout << "Main Stack: " << endl;
        while (!tempMain.empty()) {
            cout << tempMain.top() << " ";
            tempMain.pop();
        }

        cout << endl << "Min Stack: " << endl;
        while (!tempMin.empty()) {
            cout << tempMin.top() << " ";
            tempMin.pop();
        }

        cout << endl;
    }
};

int main() {
    MinStack stac;

    stac.push(5);
    stac.push(3);
    stac.push(7);
    stac.push(2);

    stac.display();

    cout << "Current Min = " << stac.getMin() << endl;

    return 0;
}
