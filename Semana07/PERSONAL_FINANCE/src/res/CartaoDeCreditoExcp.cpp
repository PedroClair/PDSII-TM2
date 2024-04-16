#include "CartaoDeCreditoExcp.hpp"

// ---------------------------------------------- Métodos LimiteExcedido -----------------------------------------------

cdcexcp::LimiteExcedido::LimiteExcedido(std::string nome_cartao,
                                        std::string numero_cartao,
                                        double limite_cartao,
                                        double soma_despesas_atuais) {
    this->_nome_cartao = nome_cartao;
    this->_numero_cartao = numero_cartao;
    this->_limite_cartao = limite_cartao;
    this->_soma_despesas_atuais = soma_despesas_atuais;
}

const char* cdcexcp::LimiteExcedido::what() const throw() {
    return "ERRO 🕵️: LIMITE DO CARTÃO EXCEDIDO";
}

std::string cdcexcp::LimiteExcedido::getNomeCartao() {
    return this->_nome_cartao;
}

std::string cdcexcp::LimiteExcedido::getNumeroCartao() {
    return this->_numero_cartao;
}

double cdcexcp::LimiteExcedido::getLimiteCartao() {
    return this->_limite_cartao;
}

// ---------------------------------------- Métodos Exceção CartaoNaoEncontrado ----------------------------------------

cdcexcp::CartaoNaoEncontrado::CartaoNaoEncontrado(std::string nome_cartao) {
    this->_nome_cartao = nome_cartao;
}

std::string cdcexcp::CartaoNaoEncontrado::getNomeCartao() {
    return this->_nome_cartao;
}

const char* cdcexcp::CartaoNaoEncontrado::what() const throw() {
    return "ERRO 🕵️: CARTÃO NÃO ENCONTRADO";
}

// ------------------------------------------- Métodos Exceção NumeroInvalido ------------------------------------------

cdcexcp::NumeroInvalido::NumeroInvalido(std::string numero) {
    this->_numero = numero;
}

std::string cdcexcp::NumeroInvalido::getNumero() {
    return this->_numero;
}

const char* cdcexcp::NumeroInvalido::what() const throw() {
    return "ERRO 🕵️: NÚMERO DO CARTÃO NÃO TEM ENTRE 13 E 16 CARACTERES NUMÉRICOS";
}

// -------------------------------------------- Métodos Exceção CVVInvalido --------------------------------------------

cdcexcp::CVVInvalido::CVVInvalido(std::string CVV) {
    this->_CVV = CVV;
}

std::string cdcexcp::CVVInvalido::getCVV() {
    return this->_CVV;
}

const char* cdcexcp::CVVInvalido::what() const throw() {
    return "ERRO 🕵️: CVV DO CARTÃO NÃO TEM 3 CARACTERES NUMÉRICOS";
}

// ----------------------------------------- Métodos Exceção FechamentoInvalido ----------------------------------------

cdcexcp::FechamentoInvalido::FechamentoInvalido(std::string fechamento) {
    this->_fechamento = fechamento;
}

std::string cdcexcp::FechamentoInvalido::getFechamento() {
    return this->_fechamento;
}

const char* cdcexcp::FechamentoInvalido::what() const throw() {
    return "ERRO 🕵️: FECHAMENTO DO CARTÃO NÃO ESTÁ ENTRE OS DIAS 01 E 31";
}

// ------------------------------------------ Métodos Exceção CartaoJaExiste -------------------------------------------

cdcexcp::CartaoJaExiste::CartaoJaExiste(std::string nome){
    this->_nome = nome;
}

const char* cdcexcp::CartaoJaExiste::what() const throw() {
    return "ERRO 🕵️: CARTÃO JÁ EXISTE";
}

std::string cdcexcp::CartaoJaExiste::getNome() {
    return this->_nome;
}
