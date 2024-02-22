#ifndef PONTO_H
#define PONTO_H
 
class Ponto {
  public:
    double _x;
    double _y;
    
    Ponto();
    Ponto(double x, double y);
};
 
#endif

#ifndef M_PI
#define M_PI  3.14159265358979323846
#endif
 
#ifndef CIRCUNFERENCIA_H
#define CIRCUNFERENCIA_H
 
#include <cmath>
 
//#include "Ponto.hpp"
 
class Circunferencia {
 
  public:
    Ponto* _centro;
    double _raio;
 
    Circunferencia(Ponto* centro, double raio);
    double calcularArea();
    
};
 
#endif

#include <iostream>
using namespace std;
 
int main() {
 
  Circunferencia* c1 = new Circunferencia(new Ponto(), 10);
  cout << c1->calcularArea() << endl;
 
  Ponto p(5.0, 5.0);
  Circunferencia* c2 = new Circunferencia(&p, 10);
  cout << c2->calcularArea() << endl;
 
  delete c1;
  delete c2;
 
  return 0;
}


//#include "Ponto.hpp"
 
Ponto::Ponto() : Ponto(0.0, 0.0) {}
 
Ponto::Ponto(double x, double y) : _x(x), _y(y) {}

//#include "Circunferencia.hpp"
 
Circunferencia::Circunferencia(Ponto* centro, double raio) {
  this->_centro = centro;
  this->_raio = raio;
}
 
double Circunferencia::calcularArea() {
    return M_PI * pow(this->_raio, 2);
} 
