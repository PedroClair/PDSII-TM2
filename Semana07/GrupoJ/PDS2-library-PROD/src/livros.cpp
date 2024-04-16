#include "../include/livros.hpp"
#include <iostream>

void criarLivro()
{
    Livro livro;
    livro.nome = "Machado de Assis";
    livro.numero = 1;
    cout << livro.nome << endl;
}
