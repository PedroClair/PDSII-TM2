#ifndef VALIDAR_ENTRADA_H
#define VALIDAR_ENTRADA_H

#include "CarteiraExcp.hpp"
#include "CartaoDeCreditoExcp.hpp"
#include "TransacaoExcp.hpp"

#include <cstdarg>
#include <regex>
#include <string>
#include <regex>

#define PIB_MUNDIAL 96000000000000

class ValidarEntrada {
    private:
        static const std::string TIPO_VALIDO,
                                 NUMERO_CC_VALIDO,
                                 CVV_VALIDO,
                                 FECHAMENTO_CC_VALIDO,
                                 DATA_VALIDA;

    public:
        static void valor(double &valor);

        static void numeroCartao(std::string &numero);

        static void cvvCartao(std::string &CVV);

        static void fechamentoCartao(std::string &fechamento);
        
        static void origemDestino(std::string &origem, std::string &destino);
                                          
        static void data(std::string &data);
};

#endif // !VALIDAR_ENTRADA_H
