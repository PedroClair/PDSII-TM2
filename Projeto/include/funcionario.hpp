#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <iostream>
#include <string>

// Struct para armazenar informações do funcionário
struct Employee {
    std::string name;
    std::string address;
    std::string zipcode;
};

Employee* insereFuncionario();
void questao4GeraEMostraEquipe();
void fill_data (Employee* , int );
void questao5FillData();

#endif