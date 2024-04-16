#ifndef PERSONAGEM_HPP
#define PERSONAGEM_HPP

#include <string>

class Personagem {
public:
    std::string nome;
    std::string classe;

    void exibir();
};

Personagem criarPersonagem(std::string nome, std::string classe);

#endif

