#include "ValidarEntrada.hpp"

const std::string ValidarEntrada::NUMERO_CC_VALIDO = "^[0-9]{13,16}$";
const std::string ValidarEntrada::CVV_VALIDO = "^[0-9]{3}$";
const std::string ValidarEntrada::FECHAMENTO_CC_VALIDO = "^(([0]?[1-9])|([1-2][0-9])|(3[01]))$";
const std::string ValidarEntrada::DATA_VALIDA = "^(?:(?:31(\\/|-|\\.)(?:0?[13578]|1[02]))\\1|"
                                           "(?:(?:29|30)(\\/|-|\\.)(?:0?[13-9]|1[0-2])\\2))"
                                           "(?:(?:1[6-9]|[2-9]\\d)?\\d{2})$|^(?:29(\\/|-|\\.)"
                                           "0?2\\3(?:(?:(?:1[6-9]|[2-9]\\d)?(?:0[48]|[2468]"
                                           "[048]|[13579][26])|(?:(?:16|[2468][048]|[3579][26])"
                                           "00))))$|^(?:0?[1-9]|1\\d|2[0-8])(\\/|-|\\.)(?:(?:0?"
                                           "[1-9])|(?:1[0-2]))\\4(?:(?:1[6-9]|[2-9]\\d)?\\d{2})$";

void ValidarEntrada::valor(double &valor) {
    if (valor < 0 or valor > PIB_MUNDIAL) throw ctrexcp::ValorInvalido(valor);
}

void ValidarEntrada::numeroCartao(std::string &numero) {
    if (!std::regex_match(numero, std::regex(NUMERO_CC_VALIDO))) throw cdcexcp::NumeroInvalido(numero);
}

void ValidarEntrada::cvvCartao(std::string &CVV) {
    if (!std::regex_match(CVV, std::regex(CVV_VALIDO))) throw cdcexcp::CVVInvalido(CVV);
}

void ValidarEntrada::fechamentoCartao(std::string &fechamento) {
    if (!std::regex_match(fechamento, std::regex(FECHAMENTO_CC_VALIDO))) throw cdcexcp::FechamentoInvalido(fechamento);
}

void ValidarEntrada::data(std::string &data) {
    if (!std::regex_match(data, std::regex(DATA_VALIDA))) throw trsexcp::DataInvalida(data);
}

void ValidarEntrada::origemDestino(std::string &origem, std::string &destino) {
    if (destino == origem) throw trsexcp::OrigemDestinoIguais(destino);
}
