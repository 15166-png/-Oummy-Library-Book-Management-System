#include "bookait.h"
#include <iostream>
#include <algorithm>
#include <iomanip>

Book::Book(const std::string& t, const std::string& a, const std::string& i, bool avail, const std::string& date)
    : title(t), author(a), ISBN(i), availability(avail), dateAdded(date) {}

void Book::displayBookDetails(std::ostream& out) const {
    out << "Title:      " << title << "\n"
        << "Author:     " << author << "\n"
        << "ISBN:       " << ISBN << "\n"
        << "Available:  " << (availability ? "Yes" : "No") << "\n"
        << "Date Added: " << dateAdded << "\n\n";
}

const std::string& Book::getISBN() const { return ISBN; }
const std::string& Book::getTitle() const { return title; }
bool Book::isAvailable() const { return availability; }

void printBooks(const std::vector<Book>& books, std::ostream& out) {
    for (const auto& b : books) {
        b.displayBookDetails(out);
    }
}

void sortBooksByISBN(std::vector<Book>& books, bool ascending) {
    std::sort(books.begin(), books.end(),
        [ascending](const Book& a, const Book& b) {
            return ascending ? (a.getISBN() < b.getISBN())
                             : (a.getISBN() > b.getISBN());
        });
}

void sortBooksByTitle(std::vector<Book>& books, bool ascending) {
    std::sort(books.begin(), books.end(),
        [ascending](const Book& a, const Book& b) {
            return ascending ? (a.getTitle() < b.getTitle())
                             : (a.getTitle() > b.getTitle());
        });
}
