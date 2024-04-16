#include <string>
#include "Prestadores.hpp"

#ifndef USER_H
#define USER_H

using namespace std;


class Usuario
{
public:
    string nome;
    string endereco;
    string cpf;
    string telefone;
    
    Usuario();

    Usuario(string nome, string endereco, string cpf, string telefone);

    void dados();
};

#endif