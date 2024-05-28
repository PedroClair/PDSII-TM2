#include "curso.hpp"

Curso::Curso(std::string nome, int codigo) : _nome(nome), _codigo(codigo) { }
std:: string Curso::getNome() { return this->_nome; };
int Curso::getCodigo() { return this->_codigo; };