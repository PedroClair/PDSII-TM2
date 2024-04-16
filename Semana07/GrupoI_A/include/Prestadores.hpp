#ifndef PRESTADORES_H

#define PRESTADORES_H

#include "PrestadorDeServicos.hpp"
#include <vector>

class Prestadores{ 
public:
    std::vector<PrestadorDeServicos> prestadores;
    void adicionar_prestador(PrestadorDeServicos&);
    std::vector<PrestadorDeServicos> localizar_via_endereco(std::string endereco);
};


#endif