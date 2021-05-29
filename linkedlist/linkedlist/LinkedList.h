#include <exception>
#include <iostream>
#pragma once
namespace gll
{
    template <typename T>
    class LinkedList final
    {
    private:
        struct Node final
        {
            Node(T val) {
                Value = val;
                next = nullptr;
                previous = nullptr;
            }
            T Value;
            Node* next;
            Node* previous;
        };
        Node* head{ nullptr };
        Node* tail{ nullptr };
        int size{ 0 };
    public:
        class iterator final {
        public:
            iterator(Node* elem, int ind) {
                element = elem;
                index = ind;
            }

            const T* operator-> () const {
                return &element->Value;
            } 

            T* operator-> () {
                return &element->Value;
            }

            const T& operator* () const {
                return element->Value;
            }

            T& operator* () {
                return element->Value;
            }

            iterator& operator++ () {
                element = element->next;
                index++;
                return *this;
            }

            iterator operator++ (int) {
                iterator iter(element);
                element = element->next;
                index++;
                return iter;
            }

            iterator& operator-- () {
                element = element->previous;
                index--;
                return *this;
            }

            iterator operator-- (int) {
                iterator iter(element);
                element = element->previous;
                index--;
                return iter;
            }

            bool operator== (const iterator& rhs) const {
                if (element == rhs.element) return true;
                else return false;
            }

            bool operator!= (const iterator& rhs) const {
                if (element != rhs.element) return true;
                else return false;
            }

            bool operator< (const iterator& rhs) const {
                if (index < rhs.index) return true;
                else return false;
            }

        private:
            Node* element;
            int index;
            friend class LinkedList;
        };

        T& front() {
            return head->Value;
        }

        T& back() {
            return tail->Value;
        }

        LinkedList() = default;

        int getSize() const {
            return size;
        }

        T& operator[] (int ind) {
            auto iter = begin();
            for (int ctr = 0; ctr != ind; ctr++) {
                if (iter.element == nullptr) throw std::runtime_error("Null pointer exception");
                ++iter;
            }
            if (iter.element != nullptr) return *iter;
        }

        iterator findFirst(const T& val) {
            auto iter = begin();
            while (*iter != val) {
                if (iter.element == nullptr) break;
                ++iter;
            }
            return iter;
        }

        iterator findLast(const T& val) {
            auto iter = iterator(tail, (getSize()-1));
            while (*iter != val) {
                if (iter.element == nullptr) break;
                --iter;
            }
            return iter;
        }

        int returnValue(iterator it) {
            return *it;
        }

        void pushFront(const T& val) {
            auto* newEl = new Node(val);
            if (head != nullptr) {
                newEl->next = head;
                head->previous = newEl;
                head = newEl;
            }
            else {
                head = newEl;
                tail = head;
            }
            size++;
        }

        void pushBack(const T& val) {
            auto* newEl = new Node(val);
            if (tail != nullptr) {
                newEl->previous = tail;
                tail->next = newEl;
                tail = newEl;
            }
            else {
                tail = newEl;
                head = tail;
            }
            size++;
        }

        void insertAfter(iterator it, const T& val) {
            Node* nd = it.element;
            if (nd == nullptr) throw std::runtime_error("Null pointer exception");
            if (nd == tail) pushBack(val);
            else {
                auto* newEl = new Node(val);
                newEl->previous = nd;
                newEl->next = nd->next;
                nd->next->previous = newEl;
                nd->next = newEl;
            }
            size++;
        }

        void insertBefore(iterator it, const T& val) {
            Node* nd = it.element;
            if (nd == nullptr) throw std::runtime_error("Null pointer exception");
            if (nd == head) pushFront(val);
            else {
                auto* newEl = new Node(val);
                newEl->next = nd;
                newEl->previous = nd->previous;
                nd->previous->next = newEl;
                nd->previous = newEl;
            }
            size++;
        }

        void erase(iterator it) {
            Node* nd = it.element;
            if (nd == nullptr) throw std::runtime_error("Null pointer exception");
            else {
                if (nd != tail) nd->next->previous = nd->previous;
                if (nd != head) nd->previous->next = nd->next;
                if (nd == head) head = nd->next;
                if (nd == tail) tail = nd->previous;
                delete nd;
            }
            size--;
        }

        iterator begin() {
            return iterator(head, 0);
        }

        iterator end() {
            return iterator(nullptr, getSize());
        }
    };
}

