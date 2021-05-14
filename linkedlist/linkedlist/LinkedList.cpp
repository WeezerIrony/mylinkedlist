#include "LinkedList.h"
#include <exception>
#include <iostream>

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

    Node* LinkedList::operator [] (int ind) {
        auto* iter = head;
        for (int ctr = 0; ctr != ind; ctr++) { if (iter == nullptr) { break; } iter = iter->next; }
        return iter;
    }

    Node* LinkedList::findFirst(int val) {
        auto* iter = head;
        while (iter->Value != val) { if (iter == nullptr) { break; } iter = iter->next; }
        return iter;
    }

    Node* LinkedList::findLast(int val) {
        auto* iter = tail;
        while (iter->Value != val) { if (iter == nullptr) { break; } iter = iter->previous; }
        return iter;
    }

    int LinkedList::returnValue(Node* nd) {
        if (nd == nullptr) { throw std::runtime_error("Null pointer exception"); }
        else { return nd->Value; }
    }

    void LinkedList::erase(Node* nd) {
        if (nd == nullptr) { throw std::runtime_error("Null pointer exception"); }
        else {
            if (nd != tail) { nd->next->previous = nd->previous; }
            if (nd != head) { nd->previous->next = nd->next; }
            if (nd == head) { head = nd->next; }
            if (nd == tail) { tail = nd->previous; }
            delete nd;
        }
    }

    void LinkedList::pushFront(int val) {
        auto* newEl = new Node(val);
        if (head != nullptr) { newEl->next = head;  head->previous = newEl; head = newEl;}
        else { head = newEl; tail = head; }
    }

    void LinkedList::pushBack(int val) {
        auto* newEl = new Node(val);
        if (tail != nullptr) { newEl->previous = tail; tail->next = newEl; tail = newEl; }
        else { tail = newEl; head = tail; }
    }
}
