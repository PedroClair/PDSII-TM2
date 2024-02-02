#ifndef BST_H
#define BST_H
#include <iostream>
using namespace std;

struct NodeT {
    int data;
    NodeT* esq;
    NodeT* dir;
};

struct BST {
    NodeT* root = nullptr;
    void insertNodeHelper(NodeT* root, int data);
    void insertNode(int data);
    //void removeNode(int data);
    void display();
};

void inorder(NodeT* n);

#endif