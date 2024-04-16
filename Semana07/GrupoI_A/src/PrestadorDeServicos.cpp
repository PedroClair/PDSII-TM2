#include "PrestadorDeServicos.hpp"
#include <iostream>

PrestadorDeServicos::PrestadorDeServicos(std::string nome, std::string endereco, std::string cpf, std::string telefone, bool movel) 
    : nome(nome), endereco(endereco), cpf(cpf), telefone(telefone), movel(movel) {}

void PrestadorDeServicos::adicionar_servico(std::string servico, double valor) {
    servicos[servico] = valor;
}

void PrestadorDeServicos::apresentacao(){
    std::cout << "Nome do prestador: "<< nome << std::endl;

    // Só apresenta o endereço caso ele preste o serviço em local fixo
    std::cout << "Endereço: \"" << pegar_endereco() << "\""<< std::endl;
    
    listar_servicos();
}

void PrestadorDeServicos::listar_servicos() {
    std::cout << "Servicos oferecidos:\n";
    for (auto& servico : servicos) {
        std::cout << "   - "<< servico.first << ":    \tR$" << servico.second << std::endl;
    }
}

std::string PrestadorDeServicos::pegar_endereco(){
    if (!movel)
        return endereco;
    
    return std::string("---");
}

std::string PrestadorDeServicos::pegar_cpf(){
    return cpf;
}