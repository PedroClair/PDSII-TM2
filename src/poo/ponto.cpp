#include "ponto.hpp"

void Ponto::testaInicio(){
    Ponto p1; // STACK
    Ponto *p2 = new Ponto(); // HEAP

    p1.coordenadaY = 123;
    p1.coordenadaX = 123;
    p2->coordenadaX = 321;
    p2->coordenadaY = 321;

    cout << p1.coordenadaX << "\t" << p1.coordenadaY << endl;
    cout << p2->coordenadaX << "\t" << p2->coordenadaY << endl;

    delete p2; // LIBERAR
}