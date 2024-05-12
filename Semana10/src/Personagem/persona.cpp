#include "persona.hpp"

//Construtores
Persona::Persona() : Persona(""){}
Persona::Persona(std::string novoNome) : nome(novoNome) { }

//Encapsulamento dos atributos
std::string Persona::getName(){
  return this->nome;
}

void Persona::setName(std::string novoNome){
  this->nome = novoNome;
}

//Implementação do código
void Persona::cumprimento(){
  std::cout << "C tah baum? Ou baum dimais?" << std::endl;
}

//Destrutores 
Persona::~Persona(){ 
  std::cout << "A persona " << this->nome << " nao fara mais parte da realidade." << std::endl;
}