#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value);
};

class LIST {
private:
    Node* head;
    Node* tail;
public:
    LIST();
    void pushh_front(int val);
    void push_back(int val);
    void printll();
    void pop_front();
    void pop_back();
    void insert_inmiddel(int val, int pos);
    void searchbyvalue(int val);
    void searchbyindex(int index);
    bool hasCycle(); // Change to no argument
    void reversceList();
};

#endif // LINKEDLIST_H