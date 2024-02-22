#include <iostream>
#include "pontoV2.hpp"
#include "circunferencia.hpp"

using namespace std;
 
int main() {
 
  PontoV2 *ptr = new PontoV2();
  Circunferencia* c1 = new Circunferencia(ptr, 10);
  cout << c1->calcularArea() << endl;
 
  PontoV2 p(5.0, 5.0);
  Circunferencia* c2 = new Circunferencia(&p, 10);
  cout << c2->calcularArea() << endl;
 
  delete ptr;
  delete c1;
  delete c2;

  return 0;
}


