#include "Campanha.hpp"

void Campanha::exibirOpcoes() {
    std::cout << "Escolha uma campanha:" << std::endl;
    std::cout << "1. Caverna do Dragao" << std::endl;
    std::cout << "2. Monte Ararath" << std::endl;
    std::cout << "3. Eclipse" << std::endl;
    std::cout << "4. Em busca de Atlantida" << std::endl;
    std::cout << "5. Perdidos no Espaco" << std::endl;
}

std::string Campanha::escolherCampanha() {
    int escolha;
    exibirOpcoes();
    std::cin >> escolha;

    switch (escolha) {
        case 1:
            return "Caverna do Dragao";
        case 2:
            return "Monte Ararath";
        case 3:
            return "Eclipse";
        case 4:
            return "Em busca de Atlantida";
        case 5:
            return "Perdidos no Espaco";
        default:
            std::cerr << "Opcao invalida!" << std::endl;
            return "";
    }
}

