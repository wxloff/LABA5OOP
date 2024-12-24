#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>

using namespace std;

class Error {
public:
    virtual void printError() const = 0;
    virtual ~Error() = default;
};

class MemoryError : public Error {
public:
    void printError() const override {
        cout << "Ошибка доступа к памяти" << endl;
    }
};

class MathError : public Error {
public:
    void printError() const override {
        cout << "Математическая ошибка" << endl;
    }
};

class DivisionByZeroError : public MathError {
public:
    void printError() const override {
        cout << "Ошибка: деление на ноль!" << endl;
    }
};

class OverflowError : public MathError {
public:
    void printError() const override {
        cout << "Переполнение!" << endl;
    }
};

template <typename T>
class PointerArray {
private:
    vector<T*> arr;

public:
    void add(T* obj) {
        arr.push_back(obj);
    }

    T* operator[](size_t index) {
        if (index >= arr.size()) {
            throw runtime_error("Индекс выходит за пределы массива!");
        }
        return arr[index];
    }

    ~PointerArray() {
        for (auto ptr : arr) {
            delete ptr;
        }
    }
};

int main() {
    try {
        PointerArray<Error> errors;

        errors.add(new MemoryError());
        errors.add(new MathError());
        errors.add(new DivisionByZeroError());
        errors.add(new OverflowError());

        for (size_t i = 0; i < 5; ++i) {
            errors[i]->printError();
        }

    }
    catch (const runtime_error& e) {
        cout << "Исключение: " << e.what() << endl;
    }

    return 0;
}
