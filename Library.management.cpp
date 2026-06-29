#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure for Book
struct Book
{
    int id;
    string title;
    string author;
    bool issued;
};

// Vector to store books
vector<Book> books;

// Function to Add Book
void addBook()
{
    Book b;

    cout << "\nEnter Book ID: ";
    cin >> b.id;
    cin.ignore();

    cout << "Enter Book Title: ";
    getline(cin, b.title);

    cout << "Enter Author Name: ";
    getline(cin, b.author);

    b.issued = false;

    books.push_back(b);

    cout << "\nBook Added Successfully!\n";
}

// Function to Display Books
void displayBooks()
{
    if (books.empty())
    {
        cout << "\nNo Books Available!\n";
        return;
    }

    cout << "\n========== Book List ==========\n";

    for (int i = 0; i < books.size(); i++)
    {
        cout << "Book ID : " << books[i].id << endl;
        cout << "Title   : " << books[i].title << endl;
        cout << "Author  : " << books[i].author << endl;

        if (books[i].issued)
            cout << "Status  : Issued" << endl;
        else
            cout << "Status  : Available" << endl;

        cout << "-----------------------------" << endl;
    }
}

// Function to Search Book
void searchBook()
{
    if (books.empty())
    {
        cout << "\nNo Books Available!\n";
        return;
    }

    cin.ignore();

    string key;

    cout << "\nEnter Book Title or Author: ";
    getline(cin, key);

    bool found = false;

    for (int i = 0; i < books.size(); i++)
    {
        if (books[i].title == key || books[i].author == key)
        {
            cout << "\nBook Found!\n";
            cout << "Book ID : " << books[i].id << endl;
            cout << "Title   : " << books[i].title << endl;
            cout << "Author  : " << books[i].author << endl;

            if (books[i].issued)
                cout << "Status  : Issued\n";
            else
                cout << "Status  : Available\n";

            found = true;
        }
    }

    if (!found)
    {
        cout << "\nBook Not Found!\n";
    }
}

// Function to Issue Book
void issueBook()
{
    if (books.empty())
    {
        cout << "\nNo Books Available!\n";
        return;
    }

    int id;

    cout << "\nEnter Book ID to Issue: ";
    cin >> id;

    for (int i = 0; i < books.size(); i++)
    {
        if (books[i].id == id)
        {
            if (books[i].issued)
            {
                cout << "\nBook is Already Issued!\n";
            }
            else
            {
                books[i].issued = true;
                cout << "\nBook Issued Successfully!\n";
            }
            return;
        }
    }

    cout << "\nBook Not Found!\n";
}

// Function to Return Book
void returnBook()
{
    if (books.empty())
    {
        cout << "\nNo Books Available!\n";
        return;
    }

    int id;

    cout << "\nEnter Book ID to Return: ";
    cin >> id;

    for (int i = 0; i < books.size(); i++)
    {
        if (books[i].id == id)
        {
            if (!books[i].issued)
            {
                cout << "\nBook is Already Available!\n";
            }
            else
            {
                books[i].issued = false;
                cout << "\nBook Returned Successfully!\n";
            }
            return;
        }
    }

    cout << "\nBook Not Found!\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n========================================";
        cout << "\n      LIBRARY MANAGEMENT SYSTEM";
        cout << "\n========================================";
        cout << "\n1. Add Book";
        cout << "\n2. Display Books";
        cout << "\n3. Search Book";
        cout << "\n4. Issue Book";
        cout << "\n5. Return Book";
        cout << "\n6. Exit";
        cout << "\n----------------------------------------";
        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addBook();
            break;

        case 2:
            displayBooks();
            break;

        case 3:
            searchBook();
            break;

        case 4:
            issueBook();
            break;

        case 5:
            returnBook();
            break;

        case 6:
            cout << "\nThank You for Using Library Management System!\n";
            break;

        default:
            cout << "\nInvalid Choice! Please Try Again.\n";
        }

    } while (choice != 6);

    return 0;
}
