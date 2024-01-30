#ifndef LISTD_H
#define LISTD_H

#include <iostream>
using namespace std;

struct NodeD {
    int data;
    NodeD* next;
    NodeD* previous;
};

struct ListD {
    NodeD* head = nullptr;
    NodeD* tail = nullptr;
    void insertNode(int data);
    void removeNode(int data);
    void display();
};

#endif
