#ifndef RECEITA_H
#define RECEITA_H

#include "Transacao.hpp"

#include <string>

class Receita : public Transacao {
    private:
        std::string _carteira;

    public:
        Receita(std::string carteira, double valor, std::string data, std::string categoria);

        void alterarCarteira(std::string nova_carteira);

        std::string getCarteira();

        void imprimirInfo();
};

#endif
