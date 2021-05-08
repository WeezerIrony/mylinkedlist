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

    class LinkedList
    {
    public:
        LinkedList();
        Node* first();
        Node* last();
        Node* withIndex(int ind);
        Node* withValue(int ind, Node* st);
        int returnValue(Node* nd);
        void pushFront(int val);
        void pushBack(int val);
        void erase(Node* nd);
    private:
        Node* head;
        Node* tail;
    };
}

