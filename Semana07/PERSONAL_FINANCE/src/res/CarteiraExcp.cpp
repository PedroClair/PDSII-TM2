#include "CarteiraExcp.hpp"

// --------------------------------------------- Métodos para ValorInvalido --------------------------------------------

ctrexcp::ValorInvalido::ValorInvalido(double valor) {
    this->_valor = valor;
}

double ctrexcp::ValorInvalido::getValor() {
    return this->_valor;
}

const char* ctrexcp::ValorInvalido::what() const throw() {
    return "ERRO 🕵️: VALOR INVÁLIDO. VALOR < 0 ou VALOR > PIB MUNDIAL.";
}

// ------------------------------------------ Métodos para ContaNaoEncontrada ------------------------------------------

ctrexcp::ContaNaoEncontrada::ContaNaoEncontrada(std::string nome) {
    this->_nome = nome;
}

std::string ctrexcp::ContaNaoEncontrada::getNome() {
    return this->_nome;
}

const char* ctrexcp::ContaNaoEncontrada::what() const throw() {
    return "ERRO 🕵️: CONTA NÃO ENCONTRADA.";
}


// --------------------------------------------- Metodos para ContaJaExiste --------------------------------------------

ctrexcp::ContaJaExiste::ContaJaExiste(std::string nome) {
    this->_nome = nome;
}

const char* ctrexcp::ContaJaExiste::what() const throw() {
    return "ERRO 🕵️: JÁ EXISTE UMA CARTEIRA REGISTRADA COM ESSE NOME.";
}

std::string ctrexcp::ContaJaExiste::getNome() {
    return this->_nome;
}

// ---------------------------------------- Metodos para ContaNaoPermiteCartao -----------------------------------------

ctrexcp::ContaNaoPermiteCartao::ContaNaoPermiteCartao(std::string nome, std::string subtipo) {
    this->_nome_conta = nome;
    this->_subtipo_conta = subtipo;
}

const char* ctrexcp::ContaNaoPermiteCartao::what() const throw() {
    return "ERRO 🕵️: A CONTA SELECIONADA NÃO PERMITE CARTÃO DE CRÉDITO.";
}

std::string ctrexcp::ContaNaoPermiteCartao::getNomeConta() {
    return this->_nome_conta;
}

std::string ctrexcp::ContaNaoPermiteCartao::getSubtipoConta() {
    return this->_subtipo_conta;
}

// ------------------------------------------- Metodos para SaldoInsuficiente ------------------------------------------

ctrexcp::SaldoInsuficiente::SaldoInsuficiente(double saldo, double despesa) {
    this->_saldo = saldo;
    this->_despesa = despesa;
}

const char* ctrexcp::SaldoInsuficiente::what() const throw() {
    return "ERRO 🕵️: SALDO INSUFICIENTE PARA REALIZAR A TRANSAÇÃO";
}

double ctrexcp::SaldoInsuficiente::getSaldo() {
    return this->_saldo;
}

double ctrexcp::SaldoInsuficiente::getDespesa() {
    return this->_despesa;
}
