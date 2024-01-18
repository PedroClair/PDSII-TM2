#include "funcionario.hpp"
#include <iostream>

Employee* insereFuncionario(){
    // Solicitar o número total de funcionários (N)
    int totalEmployees;
    std::cout << "Digite o número total de funcionários: ";
    std::cin >> totalEmployees;

    // Alocar dinamicamente um array de structs Employee
    Employee* employees = new Employee[totalEmployees];

    // Preencher os dados para cada funcionário
    for (int i = 0; i < totalEmployees; ++i) {
        std::cout << "\nFuncionário #" << (i + 1) << ":\n";
        std::cout << "Nome: ";
        std::cin >> employees[i].name;
        std::cout << "Endereço: ";
        std::cin >> employees[i].address;
        std::cout << "CEP: ";
        std::cin >> employees[i].zipcode;
    }

    // Imprimir os dados dos funcionários
    std::cout << "\nDados dos funcionários:\n";
    for (int i = 0; i < totalEmployees; ++i) {
        std::cout << "\nFuncionário #" << (i + 1) << ":\n";
        std::cout << "Nome: " << employees[i].name << "\n";
        std::cout << "Endereço: " << employees[i].address << "\n";
        std::cout << "CEP: " << employees[i].zipcode << "\n";
    }

    return employees;
}

void questao4GeraEMostraEquipe(){
    Employee* funcionarios;
    funcionarios = insereFuncionario();
    delete [] funcionarios;
}