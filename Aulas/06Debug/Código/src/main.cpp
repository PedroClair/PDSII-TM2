#include<iostream>
#include<list>
using namespace std;

struct TADExemplo {
  int atributo;
};

int main() {
  list<TADExemplo*> itens;
  itens.push_back(new TADExemplo());
  itens.push_back(new TADExemplo());
  return 0;
}




