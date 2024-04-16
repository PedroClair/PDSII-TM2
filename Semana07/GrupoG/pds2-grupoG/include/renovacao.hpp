#ifndef RENOVACAO_HPP
#define RENOVACAO_HPP

#include <iostream>
#include <vector>
#include <string>

struct Livro {
    std::string titulo;
    std::string autor;
    int prazoDevolucao; // em dias
    bool emprestado;
};

void renovarEmprestimo(std::vector<Livro>& acervo, const std::string& titulo);
void listarLivrosDisponiveis(const std::vector<Livro>& acervo);

#endif