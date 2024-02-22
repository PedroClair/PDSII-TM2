#include "Circunferencia.hpp"

Circunferencia::Circunferencia(double x, double y, double r) {
    coordenadaX = x;
    coordenadaY = y;
    raio = r;
}

double Circunferencia::calcularArea() {
    return M_PI * pow(raio, 2);
}