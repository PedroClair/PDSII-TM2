#include "conta.hpp"

//Constructors
Conta::Conta(std::string n, double s) {
    this->nome = n;
    this->saldo = s;
}

Conta::Conta(std::string n){
    this->nome = n;
    this->saldo = 0;
}

//Getters
std::string Conta::getName(){
    return this->nome;
}

double Conta::getSaldo(){
    return this->saldo;
}

//Setters
void Conta::setName(std::string n){
    this->nome = n;
}

void Conta::setSaldo(double newSaldo){
    this->saldo = newSaldo;
}

//Methods
void Conta::depositar(double valor){
    double capital = getSaldo();
    setSaldo(capital + valor);
    std::cout << "Saldo atualizado para: " << capital + valor << std::endl;
}

void Conta::sacar(double valor){
    double capital = getSaldo();
    if (capital < valor)
        std::cout << "Saldo insuficiente!!" << std::endl;
    else
        setSaldo(capital - valor);
}
