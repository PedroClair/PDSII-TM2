#include "Prestadores.hpp"
#include "PrestadorDeServicos.hpp"
#include "auxiliares.hpp"
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

void Prestadores::adicionar_prestador(PrestadorDeServicos &prestador)
{
    prestadores.push_back(prestador);
}

std::vector<PrestadorDeServicos> Prestadores::localizar_via_endereco(std::string endereco)
{
    std::map<std::string, int> score;
    std::map<std::string, int> maper;

    std::vector<PrestadorDeServicos> output;

    std::vector<std::string> palavras_endereco = tokenize(endereco, ",");

    for (int id = 0; id < (int) prestadores.size(); id++)
    {
        PrestadorDeServicos prestador = prestadores[id];
        score[prestador.pegar_cpf()] = 0;
        maper[prestador.pegar_cpf()] = id;
    }

    for (std::string &palavra : palavras_endereco)
    {
        for (PrestadorDeServicos &prestador : prestadores)
        {
            if (prestador.pegar_endereco().find(palavra) != std::string::npos)
            {
                score[prestador.pegar_cpf()] += palavra.length();
            }
        }
    }

    std::vector<std::string> cpfs = find_head(score);

    for (std::string cpf: cpfs)
    {
        output.push_back(prestadores[maper[cpf]]);
    }

    return output;
}
