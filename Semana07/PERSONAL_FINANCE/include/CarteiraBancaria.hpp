#ifndef CARTEIRA_BANCARIA_H
#define CARTEIRA_BANCARIA_H

#include "Carteira.hpp"
#include "CartaoDeCredito.hpp"
#include "CarteiraExcp.hpp"

#include <string>
#include <map>
#include <iostream>

class CarteiraBancaria : public Carteira {
    private:
        std::map<std::string, CartaoDeCredito> _cartoes;

    public:
        CarteiraBancaria(std::string nome, double saldo_inicial);

        ~CarteiraBancaria();

        void adicionarCartao(std::string nome, std::string numero, std::string CVV, std::string fechamento, double limite);

        void removerCartao(std::string nome);

        void adicionarDespesaCartao(std::string nome_cartao, double valor, std::string data, std::string categoria);

        void removerDespesaCartao(std::string nome_cartao, unsigned id);

        std::map<std::string, CartaoDeCredito> &getCartoes();

        CartaoDeCredito *getCartaoDeCredito(std::string nome);

        void pagarFatura(std::string cartao);

        void imprimirInfo();

        void imprimirCartoes();
};

#endif // !CARTEIRA_BANCARIA_H
