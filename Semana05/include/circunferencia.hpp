#ifndef CIRCUNFERENCIA_H
#define CIRCUNFERENCIA_H

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

#endif