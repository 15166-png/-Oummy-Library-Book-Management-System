#ifndef BOOKAIT_H
#define BOOKAIT_H

#include <string>
#include <vector>
#include <iosfwd> // for std::ostream

class Book {
private:
    std::string title;
    std::string author;
    std::string ISBN;
    bool        availability;
    std::string dateAdded;

public:
    Book() = default;
    Book(const std::string& t,
         const std::string& a,
         const std::string& i,
         bool avail,
         const std::string& date);

    void displayBookDetails(std::ostream& out) const;
    std::string getISBN() const;
    bool isAvailable() const;
};

// Helper functions
void printBooks(const std::vector<Book>& books, std::ostream& out);
void sortBooksByISBN(std::vector<Book>& books, bool ascending = true);

#endif // BOOKAIT_H
