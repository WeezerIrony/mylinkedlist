#include "LinkedList.h"

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
        auto* prev = head;
        for (int iter = 0; iter != ind && prev->next != nullptr; iter++) { prev = prev->next; }
        return prev;
    }

    Node* LinkedList::findFirst(int val) {
        auto* iter = head;
        while (iter->Value != val) { iter = iter->next; }
        return iter;
    }

    Node* LinkedList::findLast(int val) {
        auto* iter = tail;
        while (iter->Value != val) { iter = iter->previous; }
        return iter;
    }

    int LinkedList::returnValue(Node* nd) {
        return nd->Value;
    }

    void LinkedList::erase(Node* nd) {
        if (nd != tail) { nd->next->previous = nd->previous; }
        if (nd != head) { nd->previous->next = nd->next; }
        if (nd == head) { head = nd->next; }
        if (nd == tail) { tail = nd->previous; }
        delete nd;

    }

    void LinkedList::pushFront(int val) {
        auto* newEl = new Node(val);
        if (head != nullptr) { newEl->next = head;  head->previous = newEl; head = newEl;}
        else { 
            if (tail != nullptr) {
                auto* iter = tail;
                while (iter->previous != head) { iter = iter->previous; }
                iter->previous = newEl;
                newEl->next = iter;
            }
            head = newEl; 
        }
    }

    void LinkedList::pushBack(int val) {
        auto* newEl = new Node(val);
        if (tail != nullptr) { newEl->previous = tail; tail->next = newEl; tail = newEl; }
        else {
            if (head != nullptr) {
                auto* iter = head;
                while (iter->next != tail) { iter = iter->next; }
                iter->next = newEl;
                newEl->previous = iter;
            }
            tail = newEl;
        }
    }
}
