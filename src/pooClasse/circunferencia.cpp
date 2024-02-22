#include "circunferencia.hpp"
 
Circunferencia::Circunferencia(PontoV2* centro, double raio) {
  this->_centro = centro;
  this->_raio = raio;
}
 
double Circunferencia::calcularArea() {
    return M_PI * pow(this->_raio, 2);
} 