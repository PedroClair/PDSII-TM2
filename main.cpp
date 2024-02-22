#include <iostream>
#include "Conta.hpp"

using namespace std;
 
int main() {
  Conta bbrasil("Pedro", 100);
  bbrasil.sacar(200);
  bbrasil.depositar(300);
  bbrasil.sacar(200);
  return 0;
}


