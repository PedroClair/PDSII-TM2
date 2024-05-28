#ifndef CURSO_H
#define CURSO_H

#include <iostream>

class Curso {
 
  private:
    std::string _nome;
    int _codigo;
 
  public:
    Curso(std::string nome, int codigo) : _nome(nome), _codigo(codigo) { }
 
    std:: string getNome() { return this->_nome; };
    int getCodigo() { return this->_codigo; };
 
}; 

#endif //CURSO_H
