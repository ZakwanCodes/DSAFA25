#include <iostream>
using namespace std;

class mydynamic2Darray {
private:
    int** a = NULL;
    int ROW;
    int COL;
    int rowcount;
    int columncount;

public:
    mydynamic2Darray(int rowinput, int colinput) {
        cout << "Constructor is called" << endl;
        ROW = rowinput;
        COL = colinput;
        rowcount = rowinput;
        columncount = colinput;

        a = new int* [ROW];
        a[0] = new int[ROW * COL];

        for (int i = 1; i < ROW; i++) {
            a[i] = a[0] + i * COL;
        }
    }

    void set2DArray();
    void display();
    void push_back_row();
    void push_back_col();
    void resize(int newrow, int newcol);
    ~mydynamic2Darray();
};

void mydynamic2Darray::set2DArray() {
    for (int i = 0; i < rowcount; i++) {
        for (int j = 0; j < columncount; j++) {
            a[i][j] = (i * columncount) + j;
        }
    }
}

void mydynamic2Darray::display() {
    cout << "Display:" << rowcount << " x " << columncount << endl;

    for (int i = 0; i < rowcount; i++) {
        for (int j = 0; j < columncount; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    cout << endl;
}

void mydynamic2Darray::push_back_row() {
    if (rowcount == ROW) {
        resize(ROW * 2, COL);
    }
    rowcount++;
    set2DArray();

}

void mydynamic2Darray::push_back_col() {
    if (columncount == COL) {
        resize(ROW, COL * 2);
    }
    columncount++;
    set2DArray();


}

void mydynamic2Darray::resize(int newrow, int newcol) {
    int** newa = new int* [newrow];
    newa[0] = new int[newrow * newcol];

    for (int i = 1; i < newrow; i++) {
        newa[i] = newa[0] + i * newcol;
    }

    for (int i = 0; i < rowcount; i++) {
        for (int j = 0; j < columncount; j++) {
            newa[i][j] = a[i][j];
        }
    }

    delete[] a[0];
    delete[] a;

    a = newa;
    ROW = newrow;
    COL = newcol;
}

mydynamic2Darray::~mydynamic2Darray() {
    cout << "Destructor is called" << endl;
    delete[] a[0];
    delete[] a;
}

int main() {
    mydynamic2Darray my2Darray(4, 3);
    my2Darray.set2DArray();
    my2Darray.display();

    cout << "Adding a row:" << endl;
    my2Darray.push_back_row();
    my2Darray.display();

    cout << "Adding a column:" << endl;
    my2Darray.push_back_col();
    my2Darray.display();



   
    return 0;
}
