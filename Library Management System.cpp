#include <iostream>
#include <string>
using namespace std;

struct Book {
    int id;
    string title;
    string author;
    int quantity;
};

const int MAX_BOOKS = 100;
Book library[MAX_BOOKS];
int bookCount = 0;

// Function prototypes
void addBook();
void displayBooks();
void searchBook();
void updateBook();
void deleteBook();

int main() {
    int choice;
    do {
        cout << "\n=== Library Management System ===\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book by ID\n";
        cout << "4. Update Book\n";
        cout << "5. Delete Book\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: updateBook(); break;
            case 5: deleteBook(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while(choice != 6);

    return 0;
}

// Add a new book
void addBook() {
    if(bookCount >= MAX_BOOKS) {
        cout << "Library full! Cannot add more books.\n";
        return;
    }

    Book b;
    cout << "Enter Book ID: ";
    cin >> b.id;
    cin.ignore(); // clear newline
    cout << "Enter Title: ";
    getline(cin, b.title);
    cout << "Enter Author: ";
    getline(cin, b.author);
    cout << "Enter Quantity: ";
    cin >> b.quantity;

    library[bookCount++] = b;
    cout << "Book added successfully!\n";
}

// Display all books
void displayBooks() {
    if(bookCount == 0) {
        cout << "No books in library.\n";
        return;
    }

    cout << "\nID\tTitle\tAuthor\tQuantity\n";
    for(int i = 0; i < bookCount; i++) {
        cout << library[i].id << "\t" 
             << library[i].title << "\t" 
             << library[i].author << "\t" 
             << library[i].quantity << "\n";
    }
}

// Search a book by ID
void searchBook() {
    if(bookCount == 0) {
        cout << "No books in library.\n";
        return;
    }

    int id;
    cout << "Enter Book ID to search: ";
    cin >> id;

    for(int i = 0; i < bookCount; i++) {
        if(library[i].id == id) {
            cout << "Book Found: " << library[i].title << " by " 
                 << library[i].author << ", Quantity: " 
                 << library[i].quantity << "\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

// Update a book
void updateBook() {
    if(bookCount == 0) {
        cout << "No books in library.\n";
        return;
    }

    int id;
    cout << "Enter Book ID to update: ";
    cin >> id;

    for(int i = 0; i < bookCount; i++) {
        if(library[i].id == id) {
            cin.ignore();
            cout << "Enter new Title: ";
            getline(cin, library[i].title);
            cout << "Enter new Author: ";
            getline(cin, library[i].author);
            cout << "Enter new Quantity: ";
            cin >> library[i].quantity;
            cout << "Book updated successfully!\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

// Delete a book
void deleteBook() {
    if(bookCount == 0) {
        cout << "No books in library.\n";
        return;
    }

    int id;
    cout << "Enter Book ID to delete: ";
    cin >> id;

    for(int i = 0; i < bookCount; i++) {
        if(library[i].id == id) {
            for(int j = i; j < bookCount - 1; j++) {
                library[j] = library[j + 1]; // shift left
            }
            bookCount--;
            cout << "Book deleted successfully!\n";
            return;
        }
    }
    cout << "Book not found.\n";
}
