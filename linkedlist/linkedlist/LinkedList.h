#pragma once
namespace gll
{
    struct Node final
    {
        Node(int val);
        int Value;
        Node* next;
        Node* previous;
    };

    class LinkedList final
    {
    public:
        class iterator final {
        public:
            iterator(Node* elem);
            const Node& operator-> () const; 
            Node& operator-> (); 
            const Node& operator* () const; 
            Node& operator* (); 
            iterator& operator++ ();
            iterator operator++ (int);
            iterator& operator-- ();
            iterator operator-- (int);
            bool operator== (const iterator& rhs) const;
            bool operator!= (const iterator& rhs) const;
            bool operator< (const iterator& rhs) const;
        private:
            Node* element;
        };
        LinkedList();
        Node* first();
        Node* last();
        Node* operator[] (int ind);
        Node* findFirst(int ind);
        Node* findLast(int ind);
        int returnValue(Node* nd);
        void pushFront(int val);
        void pushBack(int val);
        void insertAfter(Node* nd, int val);
        void insertBefore(Node* nd, int val);
        void erase(Node* nd);
        iterator begin();
        iterator end();
    private:
        Node* head;
        Node* tail;
    };
}

