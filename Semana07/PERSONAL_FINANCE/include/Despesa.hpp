#ifndef DESPESA_H
#define DESPESA_H

#include "Transacao.hpp"

#include <memory>

class Despesa : public Transacao {
    private:
        std::string _carteira;

    public:
        Despesa(std::string _carteira, double valor, std::string data, std::string categoria);

        std::string getCarteira();

        void alterarCarteira(std::string nova_carteira);

        void imprimirInfo();
};

#endif
