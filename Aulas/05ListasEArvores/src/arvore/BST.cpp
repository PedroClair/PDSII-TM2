#include "BST.hpp"

NodeT* createNode (int data){
    NodeT *aux = new NodeT;
    aux->data = data;
    aux->esq = nullptr;
    aux->dir = nullptr;
    return aux;
}

void BST::insertNode(int data){
    if (root == nullptr){
        root = createNode(data);
    } else {
        insertNodeHelper(root, data);
    }
}

void BST::insertNodeHelper(NodeT* root, int data){
    if (data < root->data){
        if (root->esq == nullptr){
            root->esq = createNode(data);
        } else {
            insertNodeHelper(root->esq, data);
        }
    } else if (data > root->data) {
        if (root->dir == nullptr){
            root->dir = createNode(data);
        } else {
            insertNodeHelper(root->dir, data);
        }
    } else {
        cout << "Dado existente!!" << endl;
    }
}

void BST::display(){
    cout << "Mostra a BST!!!" << endl;
}