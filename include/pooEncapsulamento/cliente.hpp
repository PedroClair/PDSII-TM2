#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>

class Cliente{
    private:
        std::string _nome;
        bool _ativo;
        //construtor
        Cliente(std::string, bool); 
        //Setters
        void setNome(std::string ativo);
        void setAtivo(bool ativo);
        //Getters
        std::string getNome();
        bool isAtivo();
};

#endif // CLIENTE_H