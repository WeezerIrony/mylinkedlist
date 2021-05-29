#include <iostream>
#include "LinkedList.h"

struct customStructure final {
    std::string str;
    int num;
    friend std::ostream& operator<< (std::ostream& out, const customStructure& rhs) {
        out << rhs.str << " " << rhs.num << std::endl;
        return out;
    }
};

struct testStructure final {
    float field;
};

int main()
{
    gll::LinkedList<int> lk;
    lk.pushFront(78);
    lk.pushBack(24);
    lk.pushBack(45);
    lk.pushFront(42);
    lk.pushBack(42);
    std::cout << "Head is " << lk.front() << ", expecting 42" << std::endl;
    std::cout << "Element 1 is " << lk[1] << ", expecting 78" << std::endl;
    lk.erase(lk.begin());
    lk.erase(lk.findFirst(24));
    std::cout << "Head is " << lk.front() << ", expecting 78" << std::endl;
    std::cout << "Element 1 is " << lk[1] << ", expecting 45" << std::endl;
    std::cout << "Tail is " << lk.back() << ", expecting 42" << std::endl;
    lk.pushFront(32);
    lk.pushBack(32);
    std::cout << "Head is " << lk.front() << ", expecting 32" << std::endl;
    std::cout << "Tail is " << lk.back() << ", expecting 32" << std::endl;
    lk.erase(lk.findFirst(32));
    lk.erase(lk.findLast(32));
    std::cout << "Head is " << lk.front() << ", expecting 78" << std::endl;
    std::cout << "Tail is " << lk.back() << ", expecting 42" << std::endl;
    std::cout << "Element 0 is " << lk[0] << ", expecting 78" << std::endl;
    std::cout << "Element 1 is " << lk[1] << ", expecting 45" << std::endl;
    std::cout << "Element 2 is " << lk[2] << ", expecting 42" << std::endl;
    lk.insertAfter(lk.findFirst(45), 48);
    std::cout << "Element 2 is " << lk[2] << ", expecting 48" << std::endl;
    lk.insertBefore(lk.findFirst(45), 48);
    std::cout << "Element 1 is " << lk[1] << ", expecting 48" << std::endl;

    gll::LinkedList<customStructure> cl;
    cl.pushBack({ "one", 1 });
    cl.pushBack({ "two", 2 });
    cl.pushBack({ "three", 3 });

    for (auto c : cl)
        std::cout << c;

    gll::LinkedList<testStructure> list;
    list.pushBack(testStructure{ 1 });
    auto begin = list.begin();
    std::cout << begin->field;

    return 0;
}