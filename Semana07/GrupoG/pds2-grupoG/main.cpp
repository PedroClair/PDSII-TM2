#include <iostream>
#include "renovacao.hpp"
#include "chat.hpp"
#include "biblioteca.hpp"
#include "pagamento_multas.hpp"
#include "notificacoes.hpp"

using namespace std;
using namespace Notificacoes;
using namespace Biblioteca;

int main() {
    cout << "Bem-vindo ao Chat Online da Biblioteca!\n";

    string pergunta;
    while (true) {
        cout << "\nVoce: ";
        getline(cin, pergunta);

        if (pergunta.empty()) {
            cout << "Saindo do Chat Online...\n";
            break;
        }

        string resposta = ChatOnline::responderDuvida(pergunta);
        cout << "Biblioteca: " << resposta << "\n";
    }

    cout << "Livros Disponiveis:\n";
    auto livros = Biblioteca::listarLivrosDisponiveis();
    for (const auto& livro : livros) {
        cout << livro.titulo << " - " << livro.autor << " (" << (livro.disponivel ? "Disponivel" : "Indisponivel") << ")\n";
    }

    string tituloParaReserva;
    cout << "\nDigite o titulo do livro que deseja reservar: ";
    getline(cin, tituloParaReserva);

    if (Biblioteca::reservarLivro(tituloParaReserva)) {
        enviarNotificacaoDisponibilidade();
    } else {
        cout << "Desculpe, o livro '" << tituloParaReserva << "' nao esta disponivel para reserva.\n";
    }

    std::vector<Livro> acervo = {
        {"A Revolucao dos Bichos", "George Orwell", 14, true},
        {"O Senhor dos Aneis", "J.R.R. Tolkien", 7, false},
        {"1984", "George Orwell", 21, true}
    };

    listarLivrosDisponiveis(acervo);

    std::string titulo;
    std::cout << "\nDigite o titulo do livro que deseja renovar o emprestimo: ";
    std::getline(std::cin, titulo);

    renovarEmprestimo(acervo, titulo);
 
    listarMultasDisponiveis();
    int indiceSelecionado;
    cout << "\nSelecione o numero da multa que deseja pagar: ";
    cin >> indiceSelecionado;

    Multa multaSelecionada = selecionarMulta(indiceSelecionado);

    if (multaSelecionada.tipoMulta.empty()) {
        cout << "Multa invalida. Encerrando o programa.\n";
        return 1;
    }

    PagamentoMultas::realizarPagamento(multaSelecionada);
    
    return 0;
}
