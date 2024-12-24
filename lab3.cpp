#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

class Detail {
protected:
    string name;
    explicit Detail(const string& name) : name(name) {}
public:
    virtual ~Detail() = default;
    virtual void display() const {
        cout << "Detail: " << name << endl;
    }
    template<typename T, typename... Args>
    friend shared_ptr<T> createDetail(Args&&... args);
};

class Assembly : public Detail {
protected:
    int partCount;
    explicit Assembly(const string& name, int partCount)
        : Detail(name), partCount(partCount) {}
public:
    void display() const override {
        cout << "Assembly: " << name << ", Part count: " << partCount << endl;
    }
    template<typename T, typename... Args>
    friend shared_ptr<T> createDetail(Args&&... args);
};

template<typename T, typename... Args>
shared_ptr<T> createDetail(Args&&... args) {
    static_assert(is_base_of<Detail, T>::value, "T must derive from Detail");
    return shared_ptr<T>(new T(forward<Args>(args)...));
}

int main() {
    vector<shared_ptr<Detail>> details;
    auto detail1 = createDetail<Detail>("Basic Part");
    auto assembly1 = createDetail<Assembly>("Complex Assembly", 5);
    details.push_back(detail1);
    details.push_back(assembly1);
    for (const auto& detail : details) {
        detail->display();
    }
    return 0;
}
