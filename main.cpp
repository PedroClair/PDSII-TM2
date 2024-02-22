#include "estatico.hpp"

int ClasseAtributoEstatico::numero = 0;

int main() {
    ClasseAtributoEstatico c1;
    c1.imprimirNumero();

    ClasseAtributoEstatico c2;
    c2.imprimirNumero();

    c1.imprimirNumero();
    return 0;
}