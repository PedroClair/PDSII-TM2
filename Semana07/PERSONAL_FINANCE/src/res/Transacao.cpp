#include "Transacao.hpp"

unsigned Transacao::_contador = 0;

Transacao::Transacao(double valor, std::string data, std::string categoria,
    std::string subtipo) {

    ValidarEntrada::valor(valor);
    ValidarEntrada::data(data);

    this->_valor = valor;
    this->_data = data;
    this->_categoria = categoria;
    this->_contador++;
    this->_id = _contador;
    this->_subtipo = subtipo;
}

double Transacao::getValor() {
    return this->_valor;
}

std::string Transacao::getData() {
    return this->_data;
}

std::string Transacao::getCategoria() {
    return this->_categoria;
}

std::string Transacao::getSubtipo() {
    return this->_subtipo;
}

unsigned Transacao::getID() {
    return this->_id;
}
