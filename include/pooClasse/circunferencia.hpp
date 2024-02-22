#ifndef CIRCUNFERENCIA_H
#define CIRCUNFERENCIA_H
 
#include <cmath>
#include "pontoV2.hpp"
#include "constante.hpp"
 
class Circunferencia {
  public:
    PontoV2* _centro;
    double _raio;
 
    Circunferencia(PontoV2* centro, double raio);
    double calcularArea();  
};

#endif