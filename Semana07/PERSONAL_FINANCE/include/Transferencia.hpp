#ifndef TRANSFERENCIA_H
#define TRANSFERENCIA_H

#include "Transacao.hpp"

class Transferencia : public Transacao {
    private:
        std::string _origem;
        std::string _destino;

    public:
        Transferencia(double valor, std::string data, std::string categoria,
            std::string origem, std::string destino);

        void alterarOrigem(std::string nova_origem);

        void alterarDestino(std::string novo_destino);

        std::string getOrigem();

        std::string getDestino();

        void imprimirInfo();
};

#endif // !TRANSFERENCIA_H
