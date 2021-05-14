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
    std::cout << lk.returnValue(lk.first()) << std::endl; // should output 42
    std::cout << lk.returnValue(lk[1]) << std::endl; // should output 78
    lk.erase(lk.first());
    // current list: 78 24 45 42
    lk.erase(lk[1]);
    // current list: 78 45 42
    std::cout << lk.returnValue(lk.first()) << std::endl; // should output 78
    std::cout << lk.returnValue(lk[1]) << std::endl; // should output 45
    std::cout << lk.returnValue(lk.last()) << std::endl; // should output 42
    lk.pushFront(32);
    lk.pushBack(32);
    // current list: 32 78 45 42 32
    std::cout << lk.returnValue(lk.first()) << std::endl; // should output 32
    std::cout << lk.returnValue(lk.last()) << std::endl; // should output 32
    lk.erase(lk.findFirst(32));
    // current list: 78 45 42 32
    lk.erase(lk.findLast(32));
    // current list: 78 45 42
    std::cout << lk.returnValue(lk.first()) << std::endl; // should output 78
    std::cout << lk.returnValue(lk.last()) << std::endl; // should output 42
    std::cout << lk.returnValue(lk[0]) << std::endl; // should output 78
    std::cout << lk.returnValue(lk[1]) << std::endl; // should output 45
    std::cout << lk.returnValue(lk[2]) << std::endl; // should output 42
    return 0;
}