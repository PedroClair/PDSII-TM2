#include "EscolhaClasse.hpp"
#include <iostream>

std::string escolherClasse() {
    std::string classe;

    std::cout << "Escolha a classe do personagem:" << std::endl;
    std::cout << "1. Mago\n2. Bruxo\n3. Necromante\n";
    std::cout << "4. Guerreiro\n5. Assassino\n6. Tanque\n";
    std::cout << "7. Monge\n8. Bardo\n9. Paladino\n";
    int escolha;
    std::cin >> escolha;

    switch (escolha) {
        case 1:
            classe = "Mago";
            break;
        case 2:
            classe = "Bruxo";
            break;
        case 3:
            classe = "Necromante";
            break;
        case 4:
            classe = "Guerreiro";
            break;
        case 5:
            classe = "Assassino";
            break;
        case 6:
            classe = "Tanque";
            break;
        case 7:
            classe = "Monge";
            break;
        case 8:
            classe = "Bardo";
            break;
        case 9:
            classe = "Paladino";
            break;
        default:
            std::cout << "Opção inválida!" << std::endl;
            classe = "Desconhecida";
    }

    return classe;
}
