#ifndef BARRICADA_H
#define BARRICADA_H

#include "TransacaoExcp.hpp"
#include "CartaoDeCreditoExcp.hpp"
#include "Utils.hpp"
#include "CarteiraExcp.hpp"

#define PIB_MUNDIAL 96000000000000

#include <iostream>
#include <limits>
#include <regex>
#include <iomanip>
#include <sstream>
#include <vector>

class Barricada {
    private:
        static const std::string TIPO_VALIDO,
                                 NUMERO_CC_VALIDO,
                                 CVV_VALIDO,
                                 FECHAMENTO_CC_VALIDO,
                                 DATA_VALIDA;

    public:
        static void validarOpcaoMenu(unsigned &input);

        static void validarValor(double &valor);

        static void validarID(unsigned &id);

        static void validarNumeroCartao(std::string &numero);

        static void validarCvvCartao(std::string &CVV);

        static void validarFechamentoCartao(std::string &fechamento);
        
        static void validarOrigemDestino(std::string &origem, std::string &destino);
                                          
        static void validarData(std::string &data);

        static void validarTipo(std::string &tipo);
};

#endif
