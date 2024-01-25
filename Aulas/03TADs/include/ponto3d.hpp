#ifndef PONTO3D_H
#define PONTO3D_H

struct Ponto3D {
    float coordenadaX;
    float coordenadaY;
    float coordenadaZ;
    float calcularDistancia (Ponto3D*);
};

#endif 