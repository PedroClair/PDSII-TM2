#include "estatico.hpp"

ClasseAtributoEstatico::ClasseAtributoEstatico() {
    ClasseAtributoEstatico::numero++;
}
 
void ClasseAtributoEstatico::imprimirNumero () {
    std::cout << ClasseAtributoEstatico::numero << std::endl;
}
 
