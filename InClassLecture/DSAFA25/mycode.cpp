#include <iostream>
#include <string>

using namespace std;

/*
struct student {
	string name, major;
	char grade;

}; */



class Line {
private:
	//private by default if not written
	float* length = NULL;
	int size; 
public:
	Line(int count) {
		cout << "Constructor is called" << endl; //when the object is created the constructor is called
		size = count;
		length = new float[size];
	}
	/*~Line() {
		cout << "Destructor is called" << endl; //when the object goes out of scope the destructor is called
	}*/

	void setLength();

	void printLength();

	~Line();

}; 

void Line::setLength() {
	for (int i = 0; i < size; i++) {
		length[i] = 2*i + (1 % size);

	}
}

void Line::printLength() {
	for (int i = 0; i < size; i++) {
		cout << length[i] << " ";
	}
	cout << endl;
}

Line::~Line() {
	cout << "Destructor is called" << endl; //calling a member function outside of the class by defining it in the class first then implementing it outside using the scoped operator
	delete[] length;
}



//Difference between struct and class is that struct has only priv variables and class has public and private variables
void fillArray(int* ptr, int size) {
	for (int i = 0; i < size; i++) {
		ptr[i] = i % size;
	}
}

void printArray(int * ptr, int size) {
	for (int i = 0; i < size; i++) {
		cout << ptr[i] << " ";
	}
	cout << endl;
}

void increaseArraySize(int *&data, int size, int newsize) {
	if (size < newsize) {
		int* newarrayptr = new int[newsize];
		copy(data, data+size, newarrayptr);
		cout << "newarrayptr: " << newarrayptr << endl;
		cout << "data(1): " << data << endl;
		delete[] data;
		data = newarrayptr;
		cout << "data(2): " << data << endl;
	}
	else {
		return;
	}
}
int main() {

	//Line myline(5);
	//myline.setLength();
	//myline.printLength();

	int size; int newsize;
	cout << "Enter array size: ";
	cin >> size;
	int* ptr = new int[size];
	cout << "ptr: " << ptr << endl;
	fillArray(ptr, size);
	printArray(ptr, size);


	cout << "Enter a new array size: ";
	cin >> newsize;
	increaseArraySize(ptr, size, newsize);
	printArray(ptr, size);
	fillArray(ptr, newsize);
	printArray(ptr, newsize);

	delete[] ptr;


	//int* ptr = new int[10];
	//object1.name;
	//student object1; int a;


	/*
	student* ptr = new student[10];

	for (int i = 0; i < 10; i++) {
		cout << "Enter your name, major and grade: ";
		cin >> ptr[i].name >> ptr[i].major >> ptr[i].grade;

		cout << "Name: " << ptr[i].name << ", Major: " << ptr[i].major << ", Grade: " << ptr[i].grade << endl;
	}

	delete [] ptr; */
	/*
	cout << "Enter your name, major and grade: ";
	cin >> ptr[0].name >> ptr[0].major >> ptr[0].grade;

	cout << "Name: " << ptr[0].name << endl;

	cout << "Enter your name, major and grade: ";
	cin >> ptr[1].name >> ptr[1].major >> ptr[1].grade;
	cout << "Name: " << ptr[1].name << endl; */





	/*Static vs Dynamic memory allocation
	Static: we are storing on stack, we define the size during comiplation
	Dynamic: we are storing on the heap, if we don't delete dynamic memory, we cause memory leak so we have to delete it whenever we use "new"*/

	/*Dynamic memory allocation

	int* ptr = new int[5] {2,3};
	cout << ptr[1] << endl;
	delete [] ptr; //deleting memory so there's no memory leak;*/





	/* Static memory allocation
	int A[5] = { 2, 3, 4, 5, 6}; 

	cout << A << endl; //A gives address of the first index in the array
	int* ptr = A;
	cout << ptr << endl;
	cout << *(ptr) << endl;
	cout << "ptr: " << ptr[2] << endl; //same as ptr = ptr + 2 and also same as A[2];
	ptr = ptr + 1; // in cpp int = 4 bytes so now ptr points to the next block of memory, ie we are adding 4 bytes to the present address and if we add 2 then we are adding 8 bytes to the present address
	cout << A[0] << endl;
	cout << A[1] << endl;
	cout << A[2] << endl;
	cout << A[3] << endl;
	cout << A[4] << endl; 
	*/







	/*
	cout << "Hello" << endl;
	//if no namespace: std::cout << "hello";

	int a = 2;
	int b = 4;
	float c = (float)a / b;
	cout << "c: " << c << endl;

	student studentObject; 
	cout << "Enter your name, major, and grade: ";
	cin >> studentObject.name >> studentObject.major >> studentObject.grade;

	cout << "name: " << studentObject.name << " major: " << studentObject.major << " grade: " << studentObject.grade;
	*/
	return 0;
	//return 10; return 20, return 1.5; all works so why do we return 0; 
}

//Array: stored consequtively in ram 