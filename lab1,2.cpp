#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
using namespace std;

enum class BookType {
    Fiction,   // Художественная литература
    Technical  // Техническая литература
};

class Book {
private:
    string author;
    string title;
    BookType type;

public:
    Book(const string& author, const string& title, BookType type)
        : author(author), title(title), type(type) {}

    BookType getType() const {
        return type;
    }

    void print() const {
        cout << "Автор: " << author << ", Название: " << title
            << ", Тип: " << (type == BookType::Fiction ? "Художественная" : "Техническая") << "\n";
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(const string& author, const string& title, BookType type) {
        books.emplace_back(author, title, type);
    }

    void countBooksUsingSwitch() const {
        int fictionCount = 0, technicalCount = 0;
        for (const auto& book : books) {
            switch (book.getType()) {
            case BookType::Fiction:
                ++fictionCount;
                break;
            case BookType::Technical:
                ++technicalCount;
                break;
            }
        }
        cout << "Количество художественных книг: " << fictionCount
            << ", Количество технических книг: " << technicalCount << "\n";
    }

    void countBooksWithoutSwitch() const {
        int fictionCount = 0, technicalCount = 0;
        for (const auto& book : books) {
            if (book.getType() == BookType::Fiction) {
                ++fictionCount;
            }
            else {
                ++technicalCount;
            }
        }
        cout << "Количество художественных книг: " << fictionCount
            << ", Количество технических книг: " << technicalCount << "\n";
    }

    void printLibrary() const {
        for (const auto& book : books) {
            book.print();
        }
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    Library library;

    library.addBook("Дж. К. Роулинг", "Гарри Поттер", BookType::Fiction);
    library.addBook("Герберт Шилдт", "C++: Полное руководство", BookType::Technical);
    library.addBook("Ф. М. Достоевский", "Преступление и наказание", BookType::Fiction);
    library.addBook("Дональд Кнут", "Искусство программирования", BookType::Technical);

    cout << "\nСодержимое библиотеки:\n";
    library.printLibrary();

    cout << "\nПодсчет книг с использованием оператора switch:\n";
    library.countBooksUsingSwitch();

    cout << "\nПодсчет книг без оператора switch:\n";
    library.countBooksWithoutSwitch();

    return 0;
}

