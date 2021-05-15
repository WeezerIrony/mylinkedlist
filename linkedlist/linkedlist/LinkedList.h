#pragma once
namespace gll
{
    class LinkedList final
    {
    private:
        struct Node final
        {
            Node(int val);
            int Value;
            Node* next;
            Node* previous;
        };
        Node* head{ nullptr };
        Node* tail{ nullptr };
    public:
        class iterator final {
        public:
            iterator(Node* elem);
            //const int& operator-> () const; 
            //int& operator-> (); 
            const int& operator* () const; 
            int& operator* (); 
            iterator& operator++ ();
            iterator operator++ (int);
            iterator& operator-- ();
            iterator operator-- (int);
            bool operator== (const iterator& rhs) const;
            bool operator!= (const iterator& rhs) const;
            //bool operator< (const iterator& rhs) const;
        private:
            Node* element;
        friend class LinkedList;
        };
        LinkedList() = default;
        iterator operator[] (int ind);
        iterator findFirst(int ind);
        iterator findLast(int ind);
        int returnValue(iterator it);
        void pushFront(int val);
        void pushBack(int val);
        void insertAfter(iterator it, int val);
        void insertBefore(iterator it, int val);
        void erase(iterator it);
        iterator begin();
        iterator end();
    };
}

