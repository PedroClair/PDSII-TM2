#include "Personagem.hpp"
#include <iostream>

void Personagem::exibir() {
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Classe: " << classe << std::endl;
}

Personagem criarPersonagem(std::string nome, std::string classe) {
    Personagem personagem;
    personagem.nome = nome;
    personagem.classe = classe;
    return personagem;
}

