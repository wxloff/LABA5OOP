#include <iostream>
#include <windows.h>
using namespace std;

void partA(int n) {
    int* arr = new int[n];  // Выделяем память для массива целых чисел

    cout << "Введите " << n << " целых чисел:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "\nСодержимое массива (int): ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }

    cout << "\nАдрес начала массива: " << arr << "\n";
    for (int i = 0; i < n; ++i) {
        cout << "Расстояние элемента " << i << " от начала: "
            << (reinterpret_cast<char*>(&arr[i]) - reinterpret_cast<char*>(arr)) << " байт\n";
    }

    delete[] arr;  // Освобождаем память
}

void partB() {
    double* arr = new double[10];

    cout << "\nВведите 10 чисел типа double:\n";
    for (int i = 0; i < 10; ++i) {
        cin >> arr[i];
    }

    cout << "\nСодержимое массива (double): ";
    for (int i = 0; i < 10; ++i) {
        cout << arr[i] << " ";
    }

    cout << "\nАдрес начала массива: " << arr << "\n";
    for (int i = 0; i < 10; ++i) {
        cout << "Расстояние элемента " << i << " от начала: "
            << (reinterpret_cast<char*>(&arr[i]) - reinterpret_cast<char*>(arr)) << " байт\n";
    }

    delete[] arr;  // Освобождаем память
}

void partC() {
    short* arr = new short[10];

    cout << "\nВведите 10 чисел типа short:\n";
    for (int i = 0; i < 10; ++i) {
        cin >> arr[i];
    }

    cout << "\nСодержимое массива (short): ";
    for (int i = 0; i < 10; ++i) {
        cout << arr[i] << " ";
    }

    cout << "\nАдрес начала массива: " << arr << "\n";
    for (int i = 0; i < 10; ++i) {
        cout << "Расстояние элемента " << i << " от начала: "
            << (reinterpret_cast<char*>(&arr[i]) - reinterpret_cast<char*>(arr)) << " байт\n";
    }

    delete[] arr;  // Освобождаем память
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int n;
    cout << "Введите размер массива целых чисел: ";
    cin >> n;

    partA(n);
    partB();
    partC();

    return 0;
}
