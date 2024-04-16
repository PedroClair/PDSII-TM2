#include <iostream>
#include <string>

#include <saldo.hpp>

using namespace std;

int main() {
    Saldo conta(1000);

    conta.adicionar_transacao("Depósito", 500);
    conta.adicionar_transacao("Compra de alimentos", -200);
    conta.adicionar_transacao("Pagamento de conta de luz", -100);

    // Exibindo o saldo atual e o histórico de transações
    cout << "Saldo atual: R$" << conta.obter_saldo_atual() << endl;
    cout << "Histórico de transações:" << endl;
    for (const auto& transacao : conta.obter_historico_transacoes()) {
        cout << "- " << transacao.first << ": " << transacao.second << endl;
    }

    return 0;
}