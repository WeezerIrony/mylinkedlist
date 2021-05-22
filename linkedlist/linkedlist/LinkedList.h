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
    public:
        class iterator final {
        public:
            iterator(Node* elem) {
                element = elem;
            }

            //const T& operator-> () const {} 

            //T& operator-> () {} 

            const T& operator* () const {
                return element->Value;
            }

            T& operator* () {
                return element->Value;
            }

            iterator& operator++ () {
                element = element->next;
                return *this;
            }

            iterator operator++ (int) {
                iterator iter(element);
                element = element->next;
                return iter;
            }

            iterator& operator-- () {
                element = element->previous;
                return *this;
            }

            iterator operator-- (int) {
                iterator iter(element);
                element = element->previous;
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

            //bool operator< (const iterator& rhs) const;

        private:
            Node* element;
            friend class LinkedList;
        };

        T& front() {
            return head->Value;
        }

        T& back() {
            return tail->Value;
        }

        LinkedList() = default;

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
            auto iter = iterator(tail);
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
        }

        iterator begin() {
            return iterator(head);
        }

        iterator end() {
            return iterator(nullptr);
        }
    };
}

