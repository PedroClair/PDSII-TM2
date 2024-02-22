#include "ClasseTeste.hpp"
 
int main() {
 
  ClasseTeste c1(10, "Joao da Silva");
 
  c1.metodoA();
  c1.metodoB(50);
  c1.metodoA();
 
  ClasseTeste c2;
  c2.metodoA();
 
  return 0;
}
