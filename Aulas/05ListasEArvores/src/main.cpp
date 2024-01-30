#include "List.hpp"

int main() {
    List lista;
    lista.insertNode(111);
    lista.insertNode(222);
    lista.insertNode(333);
    lista.removeNode(222);
    lista.display();
    return 0;
}
