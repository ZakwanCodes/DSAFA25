#include <iostream>
using namespace std;

class mydynamicarray {
private:
    int* ptr = NULL;
    int count;   
    int size;    

public:
    mydynamicarray(int size) {
        this->size = size;
        count = 0;
        ptr = new int[size];
    }

    void resize() {
        int* newptr = new int[size * 2];
        copy(ptr, ptr + count, newptr);
        size *= 2;
        delete[] ptr;
        ptr = newptr;
    }

    void push_back(int num) {
        if (count == size) {
            resize();
        }
        ptr[count] = num;
        count++;
    }

    void push_front(int num) {
        if (count == size) {
            resize();
        }
        for (int i = count; i > 0; i--) {
            ptr[i] = ptr[i - 1];
        }
        ptr[0] = num;
        count++;
    }

    void print() {
        for (int i = 0; i < count; i++) {
            cout << ptr[i] << " ";
        }
    }

    ~mydynamicarray() {
        delete[] ptr;
    }
};

int main() {
    int size;
    cout << "Enter the original size of the array: ";
    cin >> size;
    mydynamicarray arr(size);

    arr.push_back(1);
    arr.push_back(5);
    arr.push_front(10);
    arr.push_back(5);
    arr.push_back(2);
    arr.push_front(9);
    arr.push_back(8);
    arr.push_back(2);
    arr.push_front(7);   // Expected: 7 9 10 1 5 5 2 8 2  

    arr.print();
    return 0;
}
