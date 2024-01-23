#include <cstdlib>
#include <cmath>
#include "ponto3d.hpp"

float Ponto3D::calcularDistancia(Ponto3D* p){
    float dx = p->coordenadaX;
    float dy = p->coordenadaY;
    float dz = p->coordenadaZ;
    return sqrt(dx*dx + dy*dy + dz*dz);
}
