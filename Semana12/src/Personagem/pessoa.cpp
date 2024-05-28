#include "pessoa.hpp"

//Construtores
Pessoa::Pessoa(){}
Pessoa::Pessoa(std::string nome, unsigned int cpf) : Persona(nome), _cpf(cpf) { }

//Encapsulamento dos atributos
unsigned int Pessoa::getCpf(){
  return this->_cpf;
}

void Pessoa::setCpf(unsigned int novoCpf){
  this->_cpf = novoCpf;
}

void Pessoa::cumprimenta(){
     std::cout << "A Pessoa tah baum diamis so " << std::endl;
};

//Destrutores 
Pessoa::~Pessoa(){ 
  std::cout << "A Pessoa " << this->getName() << " com cpf " << this->_cpf << " nao fara mais parte da realidade." << std::endl;
}