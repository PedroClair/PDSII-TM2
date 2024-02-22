#include <iostream>
#include "ponto3d.hpp"

int main() {
    std::cout << "Lets code!" << std::endl;
    Ponto3D p;
    p.coordenadaX = 0;
    p.coordenadaY = 0;
    p.coordenadaZ = 0;
    Ponto3D *ptr = new Ponto3D();
    ptr->coordenadaX = 2;
    ptr->coordenadaY = 2;
    ptr->coordenadaZ = 2;

    std::cout << p.calcularDistancia(ptr) << std::endl;
    return 0;
}