#include <iostream>
using std::cout;


#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    int pages;

public:
    // Parameterized constructor with default values
    Book(std::string t = "Untitled", std::string a = "Unknown Author", int p = 0) {
        title = t;
        author = a;
        pages = p;
    }

    // Member function to display book details (Abstraction in action)
    void displayInfo() {
        cout << "Title: " << title 
                << ", Author: " << author 
                << ", Pages: " << pages << std::endl;
    }
};

int main() {
    // 1. Using all custom values
    Book book1("C++ Programming", "Bjarne Stroustrup", 1300);
    
    // 2. Using some default values (omitting pages)
    Book book2("Clean Code", "Robert C. Martin");
    
    // 3. Using all default values
    Book book3;

    book1.displayInfo();
    book2.displayInfo();
    book3.displayInfo();

    return 0;
}