#include "List.hpp"
#include "ListD.hpp"

int main() {
    List lista;
    lista.insertNode(111);
    lista.insertNode(222);
    lista.insertNode(333);
    lista.display();

    ListD listadupla;
    listadupla.display();
    
    return 0;
}
