#include "funcionario.hpp"
#include <iostream>

using namespace std;

void quadroDeEmpregados(){
    struct Funcionario trabalhadora;
    trabalhadora.nome = "Rafinha";
    trabalhadora.endereco = "Rua RC 000";
    trabalhadora.CEP = 37200000;
    cout << "Nome: " << trabalhadora.nome << endl;
}
