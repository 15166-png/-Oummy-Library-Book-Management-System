#include <iostream>
#include <string>
#include <array>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;
    bool available{true};

public:
    // Set all attributes at once
    void setBookDetails(const std::string& t, const std::string& a,
                        const std::string& i, bool isAvailable = true) {
        title = t;
        author = a;
        isbn = i;
        available = isAvailable;
    }

    // Display book details in a clear format
    void displayBookDetails() const {
        std::cout << "Title        : " << title  << "\n"
                  << "Author       : " << author << "\n"
                  << "ISBN         : " << isbn   << "\n"
                  << "Availability : " << (available ? "Available" : "Borrowed") 
                  << "\n";
    }

    // Attempt to borrow the book; returns true on success
    bool borrowBook() {
        if (!available) return false;
        available = false;
        return true;
    }

    // Return the book; returns true if state actually changed
    bool returnBook() {
        if (available) return false;
        available = true;
        return true;
    }

    // Helper accessor for lookups
    const std::string& getISBN() const { return isbn; }
};

int main() {
    std::array<Book, 5> books;

    // Initialize library with 5 books
    books[0].setBookDetails("book 1", "Manunya", "1111111111", true, "2025-08-01");
    books[1].setBookDetails("book 2", "test 1", "3333333333", false, "2025-05-01");
    books[2].setBookDetails("book 3", "test 1", "2222222222", true, "2025-01-01");
    books[3].setBookDetails("book 4", "test 3", "4444444444", true, "2025-09-03");
    books[4].setBookDetails("book 5", "test 4", "5555555555", true, "2025-10-18");

    std::cout << "=== Community Library Catalog ===\n\n";
    for (const auto& b : books) {
        b.displayBookDetails();
        std::cout << "------------------------------\n";
    }

    std::cout << "Borrow a book by entering its ISBN (enter 0 to quit):\n";

    std::string inputISBN;
    while (true) {
        std::cout << "\nEnter ISBN (or 0 to exit): ";
        std::cin >> inputISBN;

        if (inputISBN == "0") {
            std::cout << "Goodbye!\n";
            break;
        }

        bool found = false;
        for (auto& b : books) {
            if (b.getISBN() == inputISBN) {
                found = true;
                if (b.borrowBook()) {
                    std::cout << "Success: You borrowed:\n";
                    b.displayBookDetails();
                } else {
                    std::cout << "Error: That book is currently unavailable (already borrowed).\n";
                }
                break;
            }
        }

        if (!found) {
            std::cout << "Error: No book with ISBN " << inputISBN << " was found in the catalog.\n";
        }
    }

    return 0;
}
