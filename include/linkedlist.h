#ifndef LinkedList_h
#define LinkedList_h
#include <cstddef>


class Node {
    public:

    int data;
    Node *next;

    Node();
};

class LinkedList{

    public:

    Node *head;
    Node *tail;

    LinkedList();

    bool is_empty();
    void addToHead(Node *&a);
    void addToTail(Node *&a);
    void add(int x, Node *&pred);
    void removeFromHead();
    void remove(int a);
    Node* retrieve(int x , Node *&p);
    bool search(int x);
    void traverse();



};

#endif