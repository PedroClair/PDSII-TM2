#ifndef GERENCIA_CARTEIRA_H
#define GERENCIA_CARTEIRA_H

#include "Barricada.hpp"
#include "Transferencia.hpp"
#include "Carteira.hpp"
#include "CarteiraBancaria.hpp"
#include "Receita.hpp"
#include "Despesa.hpp"
#include "CartaoDeCredito.hpp"
#include "GerenciaCarteiraExcp.hpp"
#include "CarteiraExcp.hpp"
#include "TransacaoExcp.hpp"
#include "ValidarEntrada.hpp"

#include <algorithm>
#include <cctype>
#include <memory>
#include <map>

class GerenciaCarteira {
    private:
        std::map<std::string, std::shared_ptr<Carteira>> _carteiras;

    public:
        GerenciaCarteira();

        std::map<std::string, std::shared_ptr<Carteira>> &getCarteiras();

        std::shared_ptr<Carteira> getCarteira(std::string nome);

        // Carteira
        void adicionarCarteira(std::string nome, double saldo_inicial);

        // overload para adicionar CarteiraBancaria
        void adicionarCarteira(double saldo_inicial, std::string nome);

        void removerCarteira(std::string nome);

        void adicionarReceita(std::string conta, double valor, std::string data,
            std::string categoria);

        void adicionarDespesa(std::string conta, double valor, std::string data,
            std::string categoria);

        void adicionarDespesaCartao(std::string conta,std::string cartao, double valor, std::string data,
            std::string categoria);

        void adicionarTransferencia(double valor, std::string data, std::string categoria,
            std::string origem, std::string destino);

        void removerReceita(std::string conta, unsigned id);

        void removerDespesa(std::string conta, unsigned id);

        void removerDespesaCartao(std::string conta, std::string cartao, unsigned id);

        void removerTransferencia(std::string conta, unsigned id);

        void adicionarCartao(std::string conta, std::string nome,
            std::string numero, std::string CVV, std::string fechamento, double limite_cartao);

        void removerCartao(std::string conta, std::string cartao);

        void pagarFaturaCartao(std::string conta, std::string cartao);

        void listarDespesasCartao(std::string conta, std::string cartao);

        void imprimirCarteiras();

        void listarTransacao(std::string conta, std::string tipo);

};

#endif
