#include "biblioteca.hpp"
#include <iostream>

using namespace std;

namespace Biblioteca {
    vector<Livro> listarLivrosDisponiveis() {
        return {{"Livro 1", "Autor 1", true}, {"Livro 2", "Autor 2", true}, {"Livro 3", "Autor 3", true}};
    }

    bool reservarLivro(const string& titulo) {
        cout << "Reservando o livro '" << titulo << "'...\n";
        return true;
    }
}
