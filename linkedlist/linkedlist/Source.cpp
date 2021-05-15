#include <iostream>
#include "LinkedList.h"


int main()
{
    gll::LinkedList lk;
    lk.pushFront(78);
    // current list: 78
    lk.pushBack(24);
    // current list: 78 24
    lk.pushBack(45);
    // current list: 78 24 45
    lk.pushFront(42);
    // current list: 42 78 24 45
    lk.pushBack(42);
    // current list: 42 78 24 45 42
    std::cout << "Head is " << lk.returnValue(lk.begin()) << ", expecting 42" << std::endl;
    std::cout << "Element 1 is " << lk.returnValue(lk[1]) << ", expecting 78" << std::endl; // should output 78
    lk.erase(lk.begin());
    // current list: 78 24 45 42
    lk.erase(lk[1]);
    // current list: 78 45 42
    std::cout << "Head is " << lk.returnValue(lk.begin()) << ", expecting 78" << std::endl;
    std::cout << "Element 1 is " << lk.returnValue(lk[1]) << ", expecting 45" << std::endl;
    std::cout << "Tail is " << lk.returnValue(lk.end()) << ", expecting 42" << std::endl;
    lk.pushFront(32);
    lk.pushBack(32);
    // current list: 32 78 45 42 32
    std::cout << "Head is " << lk.returnValue(lk.begin()) << ", expecting 32" << std::endl; // should output 32
    std::cout << "Tail is " << lk.returnValue(lk.end()) << ", expecting 32" << std::endl; // should output 32
    lk.erase(lk.findFirst(32));
    // current list: 78 45 42 32
    lk.erase(lk.findLast(32));
    // current list: 78 45 42
    std::cout << "Head is " << lk.returnValue(lk.begin()) << ", expecting 78" << std::endl;
    std::cout << "Tail is " << lk.returnValue(lk.end()) << ", expecting 42" << std::endl;
    std::cout << "Element 0 is " << lk.returnValue(lk[0]) << ", expecting 78" << std::endl;
    std::cout << "Element 1 is " << lk.returnValue(lk[1]) << ", expecting 45" << std::endl;
    std::cout << "Element 2 is " << lk.returnValue(lk[2]) << ", expecting 42" << std::endl;
    return 0;
}