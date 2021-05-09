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
        LinkedList();
        Node* first();
        Node* last();
        Node* operator [] (int ind);
        Node* findFirst(int ind);
        Node* findLast(int ind);
        int returnValue(Node* nd);
        void pushFront(int val);
        void pushBack(int val);
        void erase(Node* nd);
    private:
        Node* head;
        Node* tail;
    };
}

