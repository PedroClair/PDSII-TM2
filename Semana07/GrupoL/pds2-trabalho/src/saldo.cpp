#include "saldo.hpp"



Saldo::Saldo(double saldo_inicial) : saldo_atual(saldo_inicial) {}

double Saldo::obter_saldo_atual() {
    return saldo_atual;
}

void Saldo::adicionar_transacao(std::string descricao, double valor) {
    saldo_atual += valor;
    historico_transacoes[descricao] = valor;
}

std::map<std::string, double> Saldo::obter_historico_transacoes() {
    return historico_transacoes;
}
