#include <iostream>
#include "LinkedList.h"


int main()
{
    gll::LinkedList lk;
    lk.pushFront(78);
    lk.pushBack(24);
    lk.pushBack(45);
    lk.pushFront(42);
    lk.pushBack(42);
    lk.erase(lk.first());
    lk.erase(lk[1]);
    std::cout << lk.returnValue(lk.first()) << std::endl;
    std::cout << lk.returnValue(lk.last()) << std::endl;
    lk.pushFront(32);
    lk.pushBack(32);
    std::cout << lk.returnValue(lk.first()) << std::endl;
    std::cout << lk.returnValue(lk.last()) << std::endl;
    lk.erase(lk.findFirst(32));
    lk.erase(lk.findLast(32));
    std::cout << lk.returnValue(lk.first()) << std::endl;
    std::cout << lk.returnValue(lk.last()) << std::endl;
    return 0;
}