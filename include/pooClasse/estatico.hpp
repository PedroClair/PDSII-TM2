#ifndef ESTATICO_H
#define ESTATICO_H

#include <iostream>

class ClasseAtributoEstatico {
  public:
    static int numero;
    ClasseAtributoEstatico();
    void imprimirNumero ();
    void testaEstatico ();
};

//int ClasseAtributoEstatico::numero = 0;

#endif // ESTATICO_H