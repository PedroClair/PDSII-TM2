#ifndef PONTO3D_H
#define PONTO3D_H

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

struct Ponto3D {
    float coordenadaX;
    float coordenadaY;
    float coordenadaZ;

    float calcularDistancia(Ponto3D* p);
};

void calculaLocal();

#endif //PONTO3D_H