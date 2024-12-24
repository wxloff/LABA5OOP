#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

class Publication {
protected:
    string title;
    float price;

public:
    void getdata() {
        cout << "Введите название: ";
        cin.ignore();  // Очищаем буфер
        getline(cin, title);
        cout << "Введите цену: ";
        cin >> price;
    }

    void putdata() const {
        cout << "Название: " << title << endl;
        cout << "Цена: " << price << " руб." << endl;
    }
};

class Sales {
protected:
    float sales[3];  // Массив для хранения продаж за последние три месяца

public:
    void getdata() {
        cout << "Введите продажи за последние три месяца:\n";
        for (int i = 0; i < 3; ++i) {
            cout << "Месяц " << (i + 1) << ": ";
            cin >> sales[i];
        }
    }

    void putdata() const {
        cout << "Продажи за последние три месяца:\n";
        for (int i = 0; i < 3; ++i) {
            cout << "Месяц " << (i + 1) << ": " << sales[i] << " руб." << endl;
        }
    }
};

class Book : public Publication, public Sales {
private:
    int pages;  // Количество страниц

public:
    void getdata() {
        Publication::getdata();  // Вызов метода базового класса
        cout << "Введите количество страниц: ";
        cin >> pages;
        Sales::getdata();  // Вызов метода для ввода данных о продажах
    }

    void putdata() const {
        Publication::putdata();  // Вызов метода базового класса
        cout << "Количество страниц: " << pages << endl;
        Sales::putdata();  // Вызов метода для вывода данных о продажах
    }
};

class Type : public Publication, public Sales {
private:
    float recordingTime;  // Время записи в минутах

public:
    void getdata() {
        Publication::getdata();  // Вызов метода базового класса
        cout << "Введите время записи в минутах: ";
        cin >> recordingTime;
        Sales::getdata();  // Вызов метода для ввода данных о продажах
    }

    void putdata() const {
        Publication::putdata();  // Вызов метода базового класса
        cout << "Время записи: " << recordingTime << " минут" << endl;
        Sales::putdata();  // Вызов метода для вывода данных о продажах
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    Book book;
    Type audiobook;

    cout << "Введите данные для книги:\n";
    book.getdata();

    cout << "\nВведите данные для аудиокниги:\n";
    audiobook.getdata();

    cout << "\nДанные о книге:\n";
    book.putdata();

    cout << "\nДанные об аудиокниге:\n";
    audiobook.putdata();

    return 0;
}
