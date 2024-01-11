#include<iostream>
#include<string>
#include <limits>  
using namespace std;

struct Book {
    string title;
    string author;
    int publication_year;
    string genre;
};

Book book[6];
Book Fiction[6];
Book Non_Fiction[6];

void input_details(Book book[]) {
    for (int i = 0; i < 6; i++) {
        cout << "Enter Book Details ";


        cout << "\nEnter Title: ";
        getline(cin, book[i].title);
        

        cout << "\nEnter Author Name :";
        getline(cin, book[i].author);

        while (true) {
            cout << "\nEnter Publication Year (numbers only): ";
            if (cin >> book[i].publication_year) {
                break;
            }
            else {
                cout << "Invalid input. Please enter a valid number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        

        while (true) {
            cout << "Enter Genre (1 for Fiction or 2 for Non-Fiction): ";
            int genreChoice;
            if (cin >> genreChoice && (genreChoice == 1 || genreChoice == 2)) {
                book[i].genre = (genreChoice == 1) ? "Fiction" : "Non-Fiction";
                break;
            }
            else {
                cout << "Invalid input. Please enter 1 for Fiction or 2 for Non-Fiction." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        cin.ignore();
        cout << endl;
    }
}

void categorizeBooks(Book book[], Book fiction[], Book nonFiction[], int& fictionCount, int& nonFictionCount) {
    fictionCount = nonFictionCount = 0;

    for (int i = 0; i < 6; ++i) {
        if (book[i].genre == "Fiction") {
            fiction[fictionCount++] = book[i];
        }
        else {
            nonFiction[nonFictionCount++] = book[i];
        }
    }
}

Book find_earliest_book(Book book[], int count) {
    Book earliestbook = book[0];
    for (int i = 1; i < count; i++) {
        if (book[i].publication_year < earliestbook.publication_year) {
            earliestbook = book[i];
        }
    }
    return earliestbook;
}

void displayBooks(Book book[], int count, string category) {
    cout << "Details of " << category << " books:" << endl;
    for (int i = 0; i < count; ++i) {
        cout << "Title: " << book[i].title << ", Author: " << book[i].author
            << ", Publication Year: " << book[i].publication_year << ", Genre: " << book[i].genre << endl;
    }
    cout << endl;
}

int main() {
    int fictionCount, nonFictionCount;

    input_details(book);

    categorizeBooks(book, Fiction, Non_Fiction, fictionCount, nonFictionCount);

    Book earliestFiction = find_earliest_book(Fiction, fictionCount);
    Book earliestNonFiction = find_earliest_book(Non_Fiction, nonFictionCount);

    displayBooks(Fiction, fictionCount, "Fiction");
    cout << "Earliest Fiction Book: " << earliestFiction.title << " (" << earliestFiction.publication_year << ")" << endl << endl;

    displayBooks(Non_Fiction, nonFictionCount, "Non-Fiction");
    cout << "Earliest Non-Fiction Book: " << earliestNonFiction.title << " (" << earliestNonFiction.publication_year << ")" << endl;

    return 0;
}
