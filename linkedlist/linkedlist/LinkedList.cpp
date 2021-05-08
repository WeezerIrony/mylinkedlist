#include "LinkedList.h"
#include <string>

namespace gll {
    LinkedList::LinkedList() {
        head = 0;
        tail = 0;
    }

    Node::Node(int val) {
        Value = val;
        next = nullptr;
        previous = nullptr;
    }

    Node* LinkedList::first() {
        return head;
    }

    Node* LinkedList::last() {
        return tail;
    }

    Node* LinkedList::withIndex(int ind) {
        auto* prev = head;
        for (int iter = 0; iter != ind && prev != nullptr; iter++) { prev = prev->next; }
        return prev;
    }

    Node* LinkedList::withValue(int val, Node* st) {
        auto* prev = st;
        while (prev->Value != val) { prev = (prev == head) ? prev->next : prev = prev->previous; }
        return prev;
    }

    int LinkedList::returnValue(Node* nd) {
        return nd->Value;
    }

    void LinkedList::erase(Node* nd) {
        auto* iter = head;
        while (iter->next != nd) { iter = iter->next; }
        iter->next = nd->next;
        delete nd;
    }

    void LinkedList::pushFront(int val) {
        auto* newEl = new Node(val);
        newEl->next = head;
        if (head != nullptr) { head->previous = newEl; }
        head = newEl;
    }

    void LinkedList::pushBack(int val) {
        auto* newEl = new Node(val);
        newEl->previous = tail;
        if (tail != nullptr) { tail->next = newEl; }
        tail = newEl;
    }
}
