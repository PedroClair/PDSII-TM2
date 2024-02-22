#include "cliente.hpp"

Cliente::Cliente(std::string name, bool ativo):_nome(name), _ativo(ativo){}

//Setters
void Cliente::setNome(std::string nome){ this->_nome = nome;}
void Cliente::setAtivo(bool ativo){ this->_ativo = ativo;}

//Getters
std::string Cliente::getNome(){ return this->_nome;}
bool Cliente::isAtivo(){ return this->_ativo;}