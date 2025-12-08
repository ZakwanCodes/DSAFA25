#include <iostream>
#include <queue>
using namespace std;

class Book {
	int id_;
	string title_;
	string author_;
	int year_;
	double rating_;
public:
	Book(int id, string title, string author, int year, double rating) {
		id_ = id;
		title_ = title;
		author_ = author;
		year_ = year;
		rating_ = rating;

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
	void print() {
		cout << "ID: " << id_ << endl
			<< "Title: " << title_ << endl
			<< "Author: " << author_ << endl
			<< "Year: " << year_ << endl
			<< "Rating: " << rating_ << endl << endl;
	}
};

void add_book(queue<Book>& q, Book b) {//duplicate id -> throw
	queue<Book> temp = q;

	while (!temp.empty()) {
		if (temp.front().get_id() == b.get_id()) {
			cout << "Duplicate ID detected with id: " << b.get_id() << ", Book not added" << endl << endl;
			return;
		}
		temp.pop();
	}

	q.push(b);
}

bool remove_book(queue<Book> &q) { //remove book
	if (q.empty()) {
		return false;
	}
	else {
		q.pop();
		return true;
	}

}

int main() {

	queue<Book> q; 
	add_book(q, Book(1, "TGG", "Scott A.", 2005, 4.5));
	add_book(q, Book(1, "TTG", "James A.", 2006, 5.0));
	add_book(q, Book(2, "SFA", "Scott B.", 2002, 2.5));
	add_book(q, Book(3, "SFS", "James B.", 2002, 5.0));
	
	if (remove_book(q)) {
		cout << "Book removed" << endl << endl;
	}


	while (!q.empty()) {
		q.front().print();
		q.pop();
	} 
	return 0;
}