#include "renovacao.hpp"

void renovarEmprestimo(std::vector<Livro>& acervo, const std::string& titulo) {
    for (auto& livro : acervo) {
        if (livro.titulo == titulo && livro.emprestado) {
            livro.prazoDevolucao += 7; // Estende o prazo em 7 dias
            std::cout << "O emprestimo do livro '" << titulo << "' foi renovado com sucesso!\n";
            return;
        }
    }
    std::cout << "O livro '" << titulo << "' nao foi encontrado ou nao esta emprestado.\n";
}

void listarLivrosDisponiveis(const std::vector<Livro>& acervo) {
    std::cout << "Livros disponiveis para renovacao de emprestimo:\n";
    for (const auto& livro : acervo) {
        if (!livro.emprestado) {
            std::cout << "Titulo: " << livro.titulo << " | Autor: " << livro.autor << "\n";
        }
    }
}