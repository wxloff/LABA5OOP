#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>

using namespace std;

class Base {
public:
    virtual ~Base() = default;
    virtual void show() const {
        cout << "I am Base" << endl;
    }
};

class Derived : public Base {
public:
    void show() const override {
        cout << "I am Derived" << endl;
    }
};

vector<shared_ptr<Base>> storage;

void add(const shared_ptr<Base>& obj) {
    storage.push_back(obj);
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    for (int i = 0; i < 10; ++i) {
        if (rand() % 2 == 0) {
            add(make_shared<Base>());
        }
        else {
            add(make_shared<Derived>());
        }
    }

    for (const auto& obj : storage) {
        obj->show();
    }

    return 0;
}
