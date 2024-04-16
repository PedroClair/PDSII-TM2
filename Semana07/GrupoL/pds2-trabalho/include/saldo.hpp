#ifndef SALDO_H
#define SALDO_H

#include <map>
#include <string>

struct Saldo {
    float saldo_atual;
    std::map<std::string, double> historico_transacoes;

    // Construtor para inicializar o saldo e o histórico de transações
    Saldo(double saldo_inicial);

    // Função para obter o saldo atual da conta
    double obter_saldo_atual();

    // Função para adicionar uma nova transação e atualizar o saldo
    void adicionar_transacao(std::string descricao, double valor);

    // Função para obter o histórico de transações
    std::map<std::string, double> obter_historico_transacoes();
};

#endif
