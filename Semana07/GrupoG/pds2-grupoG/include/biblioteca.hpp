#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP

#include <vector>
#include <string>

using namespace std;

struct Livro {
    string titulo;
    string autor;
    bool disponivel;
};

namespace Biblioteca {
    vector<Livro> listarLivrosDisponiveis();
    bool reservarLivro(const string& titulo);
}

#endif
