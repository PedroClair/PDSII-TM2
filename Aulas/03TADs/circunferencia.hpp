#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#ifndef CIRCUNFERENCIA_H
#define CIRCUNFERENCIA_H

#include <cmath>

struct Circunferencia {
    double coordenadaX, coordenadaY;
    double raio;

    Circunferencia(double, double, double);
    double calcularArea();
};

#endif