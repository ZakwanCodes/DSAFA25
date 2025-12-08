#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

class Book {
	int id_;
	string title_;
	string author_;
	int year_;
	double rating_;
	int dueDays_;
public:
	Book(int id, string title, string author, int year, double rating, int dueDays) {
		id_ = id;
		title_ = title;
		author_ = author;
		year_ = year;
		rating_ = rating;
		dueDays_ = dueDays;
	}
	int get_id() {
		return id_;
	}
	string get_title() {
		return title_;
	}
	string get_author() {
		return author_;
	}
	int get_year() {
		return year_;
	}
	double get_rating() {
		return rating_;
	}
	int get_dueDays() {
		return dueDays_;
	}
	void print() {
		cout << "ID: " << id_ << endl
			<< "Title: " << title_ << endl
			<< "Author: " << author_ << endl
			<< "Year: " << year_ << endl
			<< "Rating: " << rating_ << endl
			<< "Past Due Days: " << dueDays_ << endl << endl;
	}
};

void add_book(stack<Book>& st, Book b1) {
	stack<Book> temp = st;

	while (!temp.empty()) {
		if (temp.top().get_id() == b1.get_id()) {
			cout << "Duplicate ID not added" << endl;
			return;
		}
		temp.pop();
	}
	st.push(b1);
}
bool remove_book(stack<Book> &st) {
	if (st.empty()) {
		return false;
	}
	st.pop();
	return true;
}

bool compareByDueDays(Book& a, Book& b) {
	return a.get_dueDays() > b.get_dueDays();
}


void sort_book(stack<Book>& st) {
	vector<Book> books;

	while (!st.empty()) {
		books.push_back(st.top());
		st.pop();
	}

	sort(books.begin(), books.end(), compareByDueDays);


	for (auto x : books) {
		st.push(x);
	}
}

int main() {

	Book book0(1, "The Great Gatsby", "Scott F.", 1990, 5.0, 26);
	Book book1(1, "The Great Gatsby 2", "Scott F.", 1990, 5.0, 26);
	Book book2(2, "Animal Farm", "Orwell", 1999, 4.5, 13);
	Book book3(4, "Maze Runner", "James A.", 2005, 3.2, 28);
	Book book4(5, "Overthrow", "Kinzer.", 1990, 5.0, 5);


	stack<Book> library;
	add_book(library, book0);
	add_book(library, book1);
	add_book(library, book2);
	add_book(library, book3);
	add_book(library, book4);

	if (remove_book(library)) {
		cout << "Book removed" << endl;
	}

	cout << "Sorting books based on due days: " << endl << endl;
	sort_book(library);

	while (!library.empty()) {
		library.top().print();
		library.pop();
	}




	return 0;
}