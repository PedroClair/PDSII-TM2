#include <iostream>
#include "ponto3d.hpp"

using namespace std;

int main ( ){
    Ponto3D* p1 = new Ponto3D;
    p1->coordenadaX = 0;
    p1->coordenadaY = 0;
    p1->coordenadaZ = 0;

    Ponto3D* p2 = new Ponto3D;
    p2->coordenadaX = 5;
    p2->coordenadaY = 5;
    p2->coordenadaZ = 5;

    cout << p1->calcularDistancia(p2) << endl;

    return 0;
}