#include <iostream>
#include <cstring>

class Book {
private:
    char* author;
    char* title;
    double price;
    char* publisher;
    int stock_position;

public:
    // Constructor to initialize book details
    Book(const char* author, const char* title, double price, const char* publisher, int stock_position)
        : price(price), stock_position(stock_position) {
        this->author = new char[strlen(author) + 1];
        strcpy(this->author, author);

        this->title = new char[strlen(title) + 1];
        strcpy(this->title, title);

        this->publisher = new char[strlen(publisher) + 1];
        strcpy(this->publisher, publisher);
    }

    // Destructor to release memory
    ~Book() {
        delete[] author;
        delete[] title;
        delete[] publisher;
    }

    // Function to check if a book is available
    bool checkAvailability(const char* search_title, const char* search_author) {
        if (strcmp(title, search_title) == 0 && strcmp(author, search_author) == 0) {
            return true;
        }
        return false;
    }

    // Function to process book request
    void processRequest(int num_copies) {
        if (stock_position >= num_copies) {
            double total_cost = num_copies * price;
            std::cout << "Book details:\n";
            std::cout << "Title: " << title << std::endl;
            std::cout << "Author: " << author << std::endl;
            std::cout << "Publisher: " << publisher << std::endl;
            std::cout << "Price per copy: " << price << std::endl;
            std::cout << "Number of copies requested: " << num_copies << std::endl;
            std::cout << "Total cost: " << total_cost << std::endl;
            stock_position -= num_copies;
        } else {
            std::cout << "Required copies not in stock" << std::endl;
        }
    }
};

int main() {
    // Creating book objects
    Book book1("Author1", "Title1", 20.0, "Publisher1", 10);
    Book book2("Author2", "Title2", 15.0, "Publisher2", 5);

    char search_title[50], search_author[50];
    int num_copies;

    std::cout << "Enter title of the book: ";
    std::cin.getline(search_title, 50);

    std::cout << "Enter author of the book: ";
    std::cin.getline(search_author, 50);

    // Checking book availability
    if (book1.checkAvailability(search_title, search_author)) {
        std::cout << "Book available! Enter number of copies required: ";
        std::cin >> num_copies;
        book1.processRequest(num_copies);
    } else if (book2.checkAvailability(search_title, search_author)) {
        std::cout << "Book available! Enter number of copies required: ";
        std::cin >> num_copies;
        book2.processRequest(num_copies);
    } else {
        std::cout << "Book not available." << std::endl;
    }

    return 0;
}
