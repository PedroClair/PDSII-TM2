#include "circunferencia.hpp"

float Ponto3D::calcularDistancia(Ponto3D* p){
  float dx = p->coordenadaX;
  float dy = p->coordenadaY;
  float dz = p->coordenadaZ;
  return sqrt(dx*dx + dy*dy + dz*dz);
}

void calculaLocal(){
  Ponto3D* p1 = new Ponto3D;
  p1->coordenadaX = 0;
  p1->coordenadaY = 0;
  p1->coordenadaZ = 0;

  Ponto3D* p2 = new Ponto3D;
  p2->coordenadaX = 5;
  p2->coordenadaY = 5;
  p2->coordenadaZ = 5;

  cout << p1->calcularDistancia(p2) << endl;
}
