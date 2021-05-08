#include <iostream>
#include "LinkedList.h"


int main()
{
    gll::LinkedList lk;
    lk.pushFront(42);
    lk.pushBack(24);
    std::cout << lk.returnValue(lk.first());
    return 0;
}