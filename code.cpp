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
    books[0].setBookDetails("The C++ Programming Language", "Bjarne Stroustrup", "9780321563842");
    books[1].setBookDetails("Clean Code", "Robert C. Martin", "9780132350884");
    books[2].setBookDetails("Design Patterns", "Gamma, Helm, Johnson, Vlissides", "9780201633610");
    books[3].setBookDetails("Effective Modern C++", "Scott Meyers", "9781491903995");
    books[4].setBookDetails("Cracking the Coding Interview", "Gayle Laakmann McDowell", "9780984782857");

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
