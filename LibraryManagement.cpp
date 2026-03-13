#include <iostream>
#include <string>
using namespace std;

const int MAX_BOOKS = 100;

struct Book {
    string title;
    string author;
    bool issued;
};

Book library[MAX_BOOKS];
int totalBooks = 0;

// Add a new book to the library
void addBook() {
    if (totalBooks >= MAX_BOOKS) {
        cout << "Sorry, library is full!" << endl;
        return;
    }
    cin.ignore();
    cout << "Enter book title: ";
    getline(cin, library[totalBooks].title);
    cout << "Enter author name: ";
    getline(cin, library[totalBooks].author);
    library[totalBooks].issued = false;
    totalBooks++;
    cout << "Book added successfully!" << endl;
}

// Issue a book if available
void issueBook() {
    string name;
    cin.ignore();
    cout << "Enter the title of the book to issue: ";
    getline(cin, name);
    for (int i = 0; i < totalBooks; i++) {
        if (library[i].title == name) {
            if (!library[i].issued) {
                library[i].issued = true;
                cout << "Book issued successfully!" << endl;
                return;
            } else {
                cout << "Sorry, book is already issued." << endl;
                return;
            }
        }
    }
    cout << "Book not found in library." << endl;
}

// Display all books in the library
void displayBooks() {
    if (totalBooks == 0) {
        cout << "No books in library yet." << endl;
        return;
    }
    cout << "\nList of books:\n";
    for (int i = 0; i < totalBooks; i++) {
        cout << i+1 << ". " << library[i].title
             << " by " << library[i].author
             << (library[i].issued ? " [Issued]" : " [Available]") << endl;
    }
}

int main() {
    int choice;
    do {
        cout << "\n--- Library Management System ---\n";
        cout << "1. Add Book\n2. Issue Book\n3. Display Books\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: addBook(); break;
            case 2: issueBook(); break;
            case 3: displayBooks(); break;
            case 4: cout << "Exiting program." << endl; break;
            default: cout << "Invalid choice, try again." << endl;
        }
    } while (choice != 4);

    return 0;
}