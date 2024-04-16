#ifndef PRESTADOR_DE_SERVICOS_HPP
#define PRESTADOR_DE_SERVICOS_HPP

#include <string>
#include <map>

class PrestadorDeServicos {
private:
public:
    std::string nome;
    std::string endereco;
    std::string cpf;
    std::string telefone;
    std::map<std::string, double> servicos;

    bool movel;


    PrestadorDeServicos(std::string nome, std::string endereco, std::string cpf, std::string telefone, bool movel);
    void adicionar_servico(std::string servico, double valor);
    void listar_servicos();
    void apresentacao();
    std::string pegar_endereco();
    std::string pegar_cpf();
};

#endif