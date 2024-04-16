#include <iostream>
#include "Campanha.hpp"
#include "EscolhaClasse.hpp"
#include "Personagem.hpp"

int main() {
    // Solicitar ao usuário que escolha a campanha
    Campanha campanha;
    std::string nomeCampanha = campanha.escolherCampanha();

    if (!nomeCampanha.empty()) {
        std::cout << "Campanha selecionada: " << nomeCampanha << std::endl;

        // Solicitar ao usuário que entre com o nome do personagem
        std::string nomePersonagem;
        std::cout << "Digite o nome do seu personagem: ";
        std::cin >> nomePersonagem;

        // Solicitar ao usuário que escolha a classe do personagem
        std::string classePersonagem = escolherClasse();

        // Criar um novo personagem com o nome e classe escolhidos e exibir informações
        Personagem personagem = criarPersonagem(nomePersonagem, classePersonagem);
        std::cout << "\nPersonagem criado com sucesso!\n";
        personagem.exibir();
    }

    // inventario
        inventario inventario;
        std::cout << "\nBem-vindo(a) a loja!" << std::endl;
        std::cout << "Escolha os itens que deseja comprar:" << std::endl;
        std::cout << "1. Espada" << std::endl;
        std::cout << "2. Poção de vida" << std::endl;
        std::cout << "3. Armadura" << std::endl;
        std::cout << "4. Poção de mana" << std::endl;

        int escolha;
        std::cin >> escolha;

        switch (escolha) {
            case 1:
                inventario.adicionarItem("Espada", 1);
                break;
            case 2:
                inventario.adicionarItem("Poção de vida", 1);
                break;
            case 3:
                inventario.adicionarItem("Armadura", 1);
                break;
            case 4:
                inventario.adicionarItem("Poção de mana", 1);
                break;
            default:
                std::cout << "Opção inválida!" << std::endl;
                break;
        }

        std::cout << "\nItens comprados:" << std::endl;
        inventario.mostrarItens();
    }
    Ataque ataque;
        std::cout << "\nEscolha um ataque para usar:" << std::endl;
        if (classePersonagem == "Mago") {
            ataque.adicionarAtaque("Bola de fogo");
            ataque.adicionarAtaque("Raio");
        } else if (classePersonagem == "Guerreiro") {
            ataque.adicionarAtaque("Corte horizontal");
            ataque.adicionarAtaque("Investida");
        } else if (classePersonagem == "Assassino") {
            ataque.adicionarAtaque("Ataque sorrateiro");
            ataque.adicionarAtaque("Arremesso de adaga");
        } else if (classePersonagem == "Monge") {
            ataque.adicionarAtaque("Chute giratório");
            ataque.adicionarAtaque("Soco rápido");
        }

        ataque.mostrarOpcoes();
    }


    return 0;
}
