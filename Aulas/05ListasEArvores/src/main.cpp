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
    
    return 0;
}
