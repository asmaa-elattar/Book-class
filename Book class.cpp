#include <iostream>
using namespace std;

class Book {
private:
    string title;
    string author;
    int pages;
    float price;
    static int bookCount;
public:
    Book() {
        title = "Unknown";
        author = "Unknown";
        pages = 0;
        price = 0.0;
        bookCount++;
    }
    Book(string t, string a, int p, float pr) {
        title = t;
        author = a;
        pages = p;
        price = pr;
        bookCount++;
    }
    Book(const Book &b) {
        title = b.title;
        author = b.author;
        pages = b.pages;
        price = b.price;
        bookCount++;
    }
    void setDetails(string t, string a, int p, float pr) {
        title = t;
        author = a;
        pages = p;
        price = pr;
    }
    void displayDetails() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Pages: " << pages << endl;
        cout << "Price: $" << price << endl;
    }
    void applyDiscount(float percent) {
        price -= price * (percent / 100);
        cout << "Discount of " << percent << "% applied. New price: $" << price << endl;
    }
    static void showBookCount() {
        cout << "Total books created: " << bookCount << endl;
    }
};
int Book::bookCount = 0;
int main() {
    Book b1;
    b1.displayDetails();
    Book b2("The Alchemist", "Paulo Coelho", 208, 19.99);
    b2.displayDetails();
    b2.applyDiscount(10);
    Book b3 = b2;
    b3.displayDetails();
    Book::showBookCount();

    return 0;
}
