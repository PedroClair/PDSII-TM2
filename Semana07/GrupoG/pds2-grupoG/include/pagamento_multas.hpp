#ifndef PAGAMENTO_MULTAS_HPP
#define PAGAMENTO_MULTAS_HPP

#include <string>
#include <vector>

using namespace std;

struct Multa {
    string tipoMulta;
    double valor;
};

void listarMultasDisponiveis();
Multa selecionarMulta(int indice);

namespace PagamentoMultas {
    void realizarPagamento(const Multa& multa);
}

#endif



