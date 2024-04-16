#ifndef IINVENTARIO_HPP
#define NVENTARIO_HPP
#include <string>
#include <vector>

struct Item {
    std::string nome;
    int quantidade;
};

class Inventario {
private:
    std::vector<Item> itens;

public:
    void adicionarItem(const std::string& nome, int quantidade);
    void mostrarItens() const;
};

#endif
