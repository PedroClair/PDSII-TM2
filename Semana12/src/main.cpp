#include "persona.hpp"
#include "pessoa.hpp"
#include "aluno.hpp"
#include "curso.hpp"
#include "animal.hpp"
#include "cachorro.hpp"
#include "gato.hpp"
#include "pato.hpp"
#include "ponto3d.hpp"
#include <iostream>
#include <list>
#include <memory>

void cantoDaBixardaSmartPointer();
void cantoDaBixardaPointer();

int main() {
  cantoDaBixardaPointer();
  cout << "\n--------Ponteiro Inteligente--------------\n" <<endl;
  cantoDaBixardaSmartPointer();
  return 0; 
}

void cantoDaBixardaPointer(){
  Animal* bixo1 = new Gato();
  Animal* bixo2 = new Pato();
  bixo1->fale();
  bixo2->fale();
  delete bixo1;
  delete bixo2;

  list<Animal*> lista;
 
  for(int i=0; i<50;i++) {
    if (i % 3 == 0)
      lista.push_back(new Cachorro());
    else if (i % 3 == 1)
      lista.push_back(new Gato());
    else
      lista.push_back(new Pato());
  }
 
  for (auto a : lista)
    a->fale();
}

void cantoDaBixardaSmartPointer (){
  unique_ptr<Animal> bixo1(new Gato());
  unique_ptr<Animal> bixo2(new Pato());
  bixo1->fale();
  bixo2->fale();

  for(int i=0; i<50;i++) {
    if (i % 3 == 0){
      unique_ptr<Animal> bixo(new Gato());
      bixo->fale();
    }else if (i % 3 == 1){
      unique_ptr<Animal> bixo(new Pato());
      bixo->fale();
    }
    else{
      unique_ptr<Animal> bixo(new Cachorro());
      bixo->fale();
    }
  }
}

