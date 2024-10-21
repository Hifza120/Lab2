#include <iostream>
#include <string>

using namespace std;

class Book {
	string name;
	string author;
	int pages;
public:
	Book(const string & name, const string & author, int p) : name(name), author(author), pages(p) {}

	string getName() const {
		return name;
	}

	void display() const {
		cout << "Book: " << name << "\tAuthor: " << author << "\tPages: " << pages << endl;
	}

	int getPages() const {
		return pages;
	}
};

class Newspaper {
	string name;
	string date;
	string type;
public:
	Newspaper(const string & name, const string & date, const string & type) : name(name), date(date), type(type) {}

	string getName() const {
		return name;
	}

	void display() const {
		cout << "Newspaper: " << name << "\tDate: " << date << "\tType: " << type << endl;
	}

	string getDate() const {
		return date;
	}
};

class Library {
	Book* books[100];
	Newspaper* newspapers[100];
	int bookCount = 0;
	int newspaperCount = 0;

public:
	void addBook(const Book &book) {
		books[bookCount++] = new Book(book);
	}

	void addNewspaper(const Newspaper &newspaper) {
		newspapers[newspaperCount++] = new Newspaper(newspaper);
	}

	void displayCollection() const {
		for (int i = 0; i < bookCount; ++i) {
			books[i]->display();
		}
		for (int i = 0; i < newspaperCount; ++i) {
			newspapers[i]->display();
		}
	}

	void sortBooksByPages() {
		for (int i = 0; i < bookCount - 1; ++i) {
			for (int j = i + 1; j < bookCount; ++j) {
				if (books[i]->getPages() > books[j]->getPages()) {
					Book* temp = books[i];
					books[i] = books[j];
					books[j] = temp;
				}
			}
		}
	}

	void sortNewspapersByDate() {
		for (int i = 0; i < newspaperCount - 1; ++i) {
			for (int j = i + 1; j < newspaperCount; ++j) {
				if (newspapers[i]->getDate() > newspapers[j]->getDate()) {
					Newspaper* temp = newspapers[i];
					newspapers[i] = newspapers[j];
					newspapers[j] = temp;
				}
			}
		}
	}

	Book* searchBookByTitle(const string &title) {
		for (int i = 0; i < bookCount; ++i) {
			if (books[i]->getName() == title) {
				return books[i];
			}
		}
		return nullptr;
	}

	Newspaper* searchNewspaperByName(const string &name) {
		for (int i = 0; i < newspaperCount; ++i) {
			if (newspapers[i]->getName() == name) {
				return newspapers[i];
			}
		}
		return nullptr;
	}

	~Library() {
		for (int i = 0; i < bookCount; ++i) {
			delete books[i];
		}
		for (int i = 0; i < newspaperCount; ++i) {
			delete newspapers[i];
		}
	}
};

int main() {
	Book book1("The Catcher in the Rye", "J.D. Salinger", 277);
	Book book2("To Kill a Mockingbird", "Harper Lee", 324);
	Newspaper newspaper1("Washington Post", "2024-10-13", "Morning Edition");
	Newspaper newspaper2("The Times", "2024-10-12", "Weekend Edition");
	Library library;
	library.addBook(book1);
	library.addBook(book2);
	library.addNewspaper(newspaper1);
	library.addNewspaper(newspaper2);
	cout << "Before Sorting:\n";
	library.displayCollection();
	library.sortBooksByPages();
	library.sortNewspapersByDate();
	cout << "\nAfter Sorting:\n";
	library.displayCollection();
	Book* foundBook = library.searchBookByTitle("The Catcher in the Rye");
	if (foundBook) {
		cout << "\nFound Book:\n";
		foundBook->display();
	}
	else {
		cout << "\nBook not found.\n";
	}
	Newspaper* foundNewspaper = library.searchNewspaperByName("The Times");
	if (foundNewspaper) {
		cout << "\nFound Newspaper:\n";
		foundNewspaper->display();
	}
	else {
		cout << "\nNewspaper not found.\n";
	}
	return 0;
}
