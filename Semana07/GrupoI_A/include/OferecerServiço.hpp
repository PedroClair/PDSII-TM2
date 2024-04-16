#ifndef OFERECER_SERVICO_HPP
#define OFERECER_SERVICO_HPP

#include "Usuario.hpp"
#include "PrestadorDeServicos.hpp"
#include <iostream>

class OferecerServico {
public:
    void oferecerServico(Usuario& usuario, PrestadorDeServicos& prestador);
};

#endif
