#ifndef PONTO_H
#define PONTO_H

#include <iostream>
using namespace std;

class Ponto {
    public:
        int coordenadaX;
        int coordenadaY;
    
        void testaInicio();
        void setarXY(int x, int y);
        void setarXY(int xy);
        void Ponto::testaSets();
};

#endif //PONTO_H