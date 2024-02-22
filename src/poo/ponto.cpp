#include "ponto.hpp"

Ponto::Ponto(int x, int y){this->coordenadaX = x; this->coordenadaY = y;}
Ponto::Ponto() : Ponto(-1, -1) {}
Ponto::Ponto(int xy) : Ponto(xy, xy){}

void Ponto::testaSets(){
    Ponto p(0);
    p.setarXY(10, 20);
    cout << "p.x: " << p.coordenadaX << endl;
    p.setarXY(50);
    cout << "p.x: " << p.coordenadaX << endl;
}

void Ponto::setarXY(int x, int y){
    this->coordenadaX = x;
    this->coordenadaY = y;
}

void Ponto::setarXY(int xy){
    this->coordenadaX = xy;
    this->coordenadaY = xy;
}

void Ponto::testaInicio(){
    Ponto p1(0); // STACK
    Ponto *p2 = new Ponto(0); // HEAP

    p1.coordenadaY = 123;
    p1.coordenadaX = 123;
    cout << "p.x: " << p1.coordenadaX << endl;

    p2->coordenadaX = 321;
    p2->coordenadaY = 321;
    cout << "p.x: " << p2->coordenadaX << endl;

    delete p2; // LIBERAR
}