#include "Inventario.hpp"
#include <iostream>

void Inventario::adicionarItem(const std::string& nome, int quantidade) {
    // Verificar se o item já existe no inventário
    for (auto& item : itens) {
        if (item.nome == nome) {
            item.quantidade += quantidade;
            return;
        }
    }

    // Caso o item não exista, adicioná-lo ao inventário
    itens.push_back({nome, quantidade});
}

void Inventario::mostrarItens() const {
    if (itens.empty()) {
        std::cout << "O inventario esta vazio." << std::endl;
        return;
    }

    std::cout << "Itens no inventario:" << std::endl;
    for (const auto& item : itens) {
        std::cout << item.nome << ": " << item.quantidade << std::endl;
    }
}
