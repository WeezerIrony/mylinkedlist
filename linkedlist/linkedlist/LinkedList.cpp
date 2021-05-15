#include "LinkedList.h"
#include <exception>
#include <iostream>

namespace gll {
    LinkedList::Node::Node(int val) {
        Value = val;
        next = nullptr;
        previous = nullptr;
    }

    LinkedList::iterator::iterator(Node* elem) {
        element = elem;
    }

    //const int& LinkedList::iterator::operator-> () const {

    //}

    //int& LinkedList::iterator::operator-> () {

    //}

    const int& LinkedList::iterator::operator* () const {
        return element->Value;
    }

    int& LinkedList::iterator::operator* () {
        return element->Value;
    }

    LinkedList::iterator& LinkedList::iterator::operator++ () {
        element = element->next;
        return *this;
    }

    LinkedList::iterator LinkedList::iterator::operator++ (int) {
        iterator iter(element);
        element = element->next;
        return iter;
    }

    LinkedList::iterator& LinkedList::iterator::operator-- () {
        element = element->previous;
        return *this;
    }

    LinkedList::iterator LinkedList::iterator::operator-- (int) {
        iterator iter(element);
        element = element->previous;
        return iter;
    }

    bool LinkedList::iterator::operator== (const iterator& rhs) const {
        if (element == rhs.element) { return true; }
        else { return false; }
    }

    bool LinkedList::iterator::operator!= (const iterator& rhs) const {
        if (element != rhs.element) { return true; }
        else { return false; }
    }

    //bool LinkedList::iterator::operator< (const iterator& rhs) const {

    //}

    LinkedList::iterator LinkedList::operator[] (int ind) {
        auto* iter = head;
        for (int ctr = 0; ctr != ind; ctr++) { if (iter == nullptr) { break; } iter = iter->next; }
        return iterator(iter);
    }

    LinkedList::iterator LinkedList::findFirst(int val) {
        auto* iter = head;
        while (iter->Value != val) { if (iter == nullptr) { break; } iter = iter->next; }
        return iterator(iter);
    }

    LinkedList::iterator LinkedList::findLast(int val) {
        auto* iter = tail;
        while (iter->Value != val) { if (iter == nullptr) { break; } iter = iter->previous; }
        return iterator(iter);
    }

    int LinkedList::returnValue(iterator it) {
        return *it;
    }

    void LinkedList::erase(iterator it) {
        Node* nd = it.element;
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

    void LinkedList::insertAfter(iterator it, int val) {
        Node* nd = it.element;
        if (nd == nullptr) { throw std::runtime_error("Null pointer exception"); }
        if (nd == tail) { pushBack(val); }
        else {
            auto* newEl = new Node(val);
            newEl->previous = nd;
            newEl->next = nd->next;
            nd->next->previous = newEl;
            nd->next = newEl;
        }
    }

    void LinkedList::insertBefore(iterator it, int val) {
        Node* nd = it.element;
        if (nd == nullptr) { throw std::runtime_error("Null pointer exception"); }
        if (nd == head) { pushFront(val); }
        else {
            auto* newEl = new Node(val);
            newEl->next = nd;
            newEl->previous = nd->previous;
            nd->previous->next = newEl;
            nd->previous = newEl;
        }
    }

    LinkedList::iterator LinkedList::begin() {
        return iterator(head);
    }

    LinkedList::iterator LinkedList::end() {
        return iterator(tail);
    }
}
