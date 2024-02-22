#ifndef CONTA_H
#define CONTA_H

#include <iostream>

class Conta {
    std::string nome;
    double saldo;

    public:
        //Constructors
        Conta(std::string, double);
        Conta(std::string);

        //Getters
        std::string getName();
        double getSaldo();

        //Setters
        void setName(std::string);
        void setSaldo(double);

        //Methods
        void depositar(double valor);
        void sacar(double valor);
};

#endif //CONTA_H