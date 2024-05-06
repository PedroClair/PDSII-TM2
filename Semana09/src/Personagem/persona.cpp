#include "persona.hpp"

Persona::Persona() : Persona(""){}

Persona::Persona(std::string novoNome) : nome(novoNome) { }

//Implementação do código
void Persona::cumprimento(){
  std::cout << "C tah baum? Ou baum dimais?" << std::endl;
}

Persona::~Persona(){ 
  std::cout << "A persona " << this->nome << " nao fara mais parte da realidade." << std::endl;
}