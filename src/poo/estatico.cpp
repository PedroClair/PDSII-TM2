#include "estatico.hpp"

ClasseAtributoEstatico::ClasseAtributoEstatico() {
    ClasseAtributoEstatico::numero++;
}
 
void ClasseAtributoEstatico::imprimirNumero () {
    std::cout << ClasseAtributoEstatico::numero << std::endl;
}

int ClasseAtributoEstatico::numero = 0;
void ClasseAtributoEstatico::testaEstatico () {

    ClasseAtributoEstatico c1;
    c1.imprimirNumero();

    ClasseAtributoEstatico c2;
    c2.imprimirNumero();

    c1.imprimirNumero();
}
 
