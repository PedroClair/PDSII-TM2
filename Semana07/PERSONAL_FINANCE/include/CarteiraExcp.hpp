#ifndef CARTEIRA_EXCP_H
#define CARTEIRA_EXCP_H

#include <iostream>
#include <exception>

namespace ctrexcp {

    class ValorInvalido : public std::exception {
        private:
            double _valor;
            std::string _nome;

        public:
            ValorInvalido(double valor, std::string nome);

            ValorInvalido(double valor);

            const char* what() const throw();

            double getValor();

            std::string getNome();
    };

    class ContaNaoEncontrada : public std::exception {
        private:
            std::string _nome;

        public:
            ContaNaoEncontrada(std::string nome);

            const char* what() const throw();

            std::string getNome();
    };

    class ContaJaExiste : public std::exception {
        public:
            std::string _nome;

        public:
            ContaJaExiste(std::string nome);

            const char* what() const throw();

            std::string getNome();
    };

    class ContaNaoPermiteCartao : public std::exception {
        public:
            std::string _nome_conta, _subtipo_conta;

        public:
            ContaNaoPermiteCartao(std::string nome_conta, std::string tipo_conta);

            const char * what() const throw();

            std::string getNomeConta();

            std::string getSubtipoConta();
    };

    class SaldoInsuficiente : public std::exception {
        public:
            double _saldo, _despesa;

        public:
            SaldoInsuficiente(double saldo, double despesa);

            const char * what() const throw();

            double getSaldo();

            double getDespesa();
    };
}


#endif
