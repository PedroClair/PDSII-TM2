#ifndef CARTAO_DE_CREDITO_H
#define CARTAO_DE_CREDITO_H

#include "Despesa.hpp"
#include "CartaoDeCreditoExcp.hpp"
#include "CarteiraExcp.hpp"
#include "Utils.hpp"
#include "TransacaoExcp.hpp"
#include "ValidarEntrada.hpp"

#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <string>

class CartaoDeCredito {
    private:
        std::string _nome,
                    _numero,
                    _CVV,
                    _fechamento;

        double _limite_cartao;
        std::map<unsigned, std::shared_ptr<Despesa>> _despesas;

    public:
        CartaoDeCredito(std::string nome, std::string numero, std::string CVV, std::string fechamento, double limite_cartao);

        std::string getNome();

        std::string getNumero();

        std::string getCVV();

        std::string getFechamento();

        double getTotalDespesas();

        double getLimite();

        std::map<unsigned, std::shared_ptr<Despesa>> &getListaDespesas();

        void alterarLimiteCartao(double limite);

        void adicionarDespesa(double valor, std::string data, std::string categoria);

        void listarDespesas();

        void removerDespesa(unsigned id);

        void imprimirInfo();
};

#endif
