#include <iostream>
#include <vector>
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
		cout << "ID: " << id_ << endl;
		cout << "Title: " << title_ << endl;
		cout << "Author: " << author_ << endl;
		cout << "Year: " << year_ << endl;
		cout << "Rating : " << rating_ << endl;
		cout << endl;
	}
};

void add_book(vector<Book>* v, Book& b) {
	for (int i = 0; i < v->size(); ++i) {
		if ((*v)[i].get_id() == b.get_id()) {
			return;
		}
	}
	v->push_back(b);
}

bool remove_book_by_id(vector<Book>* v, int id) {
	for (int i = 0; i < v->size(); ++i) {
		if ((*v)[i].get_id() == id) {
			v->erase(v->begin() + i);
			cout << "Book removed with id: " << id << endl;
			return true;
		}
	}
	return false;
}

Book* find_book_by_id(vector<Book>* v, int id) {
	for(int i = 0; i < v->size(); ++i){
		if ((*v)[i].get_id() == id) {
			cout << "Book found with id: " << id << endl;
			return &(*v)[i];
		}
	}
}



int main() {

	vector<Book>* library = new vector<Book>();
	Book b1(1, "TGG", "Scott A.", 2005, 4.5);
	Book b2(2, "AJS", "James A.", 2000, 5);
	Book b3(3, "SFA", "Scott B.", 1982, 2);
	Book b4(4, "SGF", "James B.", 2012, 3);
	Book b5(5, "DFA", "Scott C.", 2012, 3);
	Book b6(6, "G2R", "James C", 2012, 3);
	Book b7(7, "SDA", "Scott D.", 2012, 3);
	Book b8(8, "GBR", "James D.", 2012, 3);
	Book b9(9, "VAA", "Scott F.", 2012, 3);
	Book b10(10, "SAF", "James F.", 2012, 3);



																						
	add_book(library, b1);
	add_book(library, b2);
	add_book(library, b3);
	add_book(library, b4);
	add_book(library, b5);
	add_book(library, b6);
	add_book(library, b7);
	add_book(library, b8);
	add_book(library, b9);
	add_book(library, b10);




	remove_book_by_id(library, 1);
	remove_book_by_id(library, 5);


	for (int i = 0; i < library->size(); ++i) {
		(*library)[i].print();
	}


	Book* find = find_book_by_id(library, 2);
	find->print();

	return 0;
}