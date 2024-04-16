#include "usuario.hpp"
#include "livros.hpp"
#include "aluguel.hpp"
#include "historias.hpp"
#include "emprestados.hpp"
#include "pesquisa.hpp"

#include <iostream>

using namespace std;

int main()
{
    bool escolhaHistoria = true;
    while (escolhaHistoria)
    {
        cout << "Bem vindo ao LibrarySoftware" << endl;
        cout << "O que você deseja? " << endl;
        cout << "1 - Criar Usuário" << endl;
        cout << "2 - Alugar um livro " << endl;
        cout << "3 - Ver história de livros" << endl;
        cout << "4 - Renovação da reserva" << endl;
        cout << "5 - Cadastrar um novo livro" << endl;
        cout << "6 - Pesquisar livros disponíveis" << endl;

        int escolha;
        cin >> escolha;

        switch (escolha)
        {
        case 1:
        {
            criarUsuario();
            break;
        }
        case 2:
        {
            alugarLivro();
            break;
        }
        case 3:
        {
            listarHistorias();
            break;
        }
        case 4:
        {
            listarEmprestados();
            break;
        }
        case 5:
        {
            criarLivro();
            break;
        }
        case 6:
        {
            pesquisa();
            break;
        }
        default:
            cout << "Opção inválida" << endl;
            escolhaHistoria = false;
            break;
        }
    }

    cout << "Trabalho Rodando " << endl;
}
