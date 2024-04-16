#include "Usuario.hpp"
#include <iostream>

using namespace std;

Usuario::Usuario(){}

Usuario::Usuario(std::string nome, std::string endereco, std::string cpf, std::string telefone) 
    : nome(nome), endereco(endereco), cpf(cpf), telefone(telefone) {}


void Usuario::dados(){
    cout << " ----[ Usuário ]----- \n\n";
    cout << "Nome: " << nome << "\n";
    cout << "Endereço: " << endereco << "\n";
    cout << "Cpf: " << cpf << "\n";
    cout << "Telefone: " << telefone << "\n";
}