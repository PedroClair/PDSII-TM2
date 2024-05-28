#include "persona.hpp"

//Construtores
Persona::Persona(){}
Persona::Persona(std::string nome) : _nome(nome) { }

//Encapsulamento dos atributos
std::string Persona::getName(){
  return this->_nome;
}

void Persona::setName(std::string novoNome){
  this->_nome = novoNome;
}

//Implementação do código

//Destrutores 
Persona::~Persona(){ 
  std::cout << "A persona " << this->_nome << " nao fara mais parte da realidade." << std::endl;
}