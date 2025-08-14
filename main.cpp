#include <iostream>
#include <fstream>
#include "bookait.h"

int main() {
    // ใช้ข้อมูลใหม่ตามที่ให้มา
    std::vector<Book> books = {
        Book("book 1", "Manunya", "1111111111", true,  "2025-08-01"),
        Book("book 2", "test 1",  "3333333333", false, "2025-05-01"),
        Book("book 3", "test 1",  "2222222222", true,  "2025-01-01")
    };

    std::ofstream outFile("library_sort_results.txt");
    if (!outFile) {
        std::cerr << "Failed to open output file.\n";
        return 1;
    }

    // ก่อนเรียงลำดับ
    outFile << "=== BEFORE SORTING (Original Order) ===\n";
    printBooks(books, outFile);

    // เรียงจากน้อยไปมาก (ตาม ISBN)
    sortBooksByISBN(books, true);
    outFile << "=== AFTER SORTING (Ascending by ISBN) ===\n";
    printBooks(books, outFile);

    // เรียงจากมากไปน้อย (ตาม ISBN)
    sortBooksByISBN(books, false);
    outFile << "=== AFTER SORTING (Descending by ISBN) ===\n";
    printBooks(books, outFile);

    outFile.close();

    std::cout << "Results saved to library_sort_results.txt\n";
    return 0;
}
