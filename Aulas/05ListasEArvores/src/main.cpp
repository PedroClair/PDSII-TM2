#include "List.hpp"
#include "ListD.hpp"
#include "BST.hpp"

int main() {
    List lista;
    lista.insertNode(111);
    lista.insertNode(222);
    lista.insertNode(333);
    lista.display();

    ListD listadupla;
    listadupla.display();

    BST arvore;
    arvore.display();

    BST bst;
    bst.insertNode(5);
    bst.insertNode(2);
    bst.insertNode(7);
    bst.insertNode(7);
    bst.display();

    return 0;
}
