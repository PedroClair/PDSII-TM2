#include "Barricada.hpp"

// [d]despesa, [r]receita, [t]transferencia, [a]todos
const std::string Barricada::TIPO_VALIDO = "^[drta]$";
const std::string Barricada::NUMERO_CC_VALIDO = "^[0-9]{13,16}$";
const std::string Barricada::CVV_VALIDO = "^[0-9]{3}$";
const std::string Barricada::FECHAMENTO_CC_VALIDO = "^(([0]?[1-9])|([1-2][0-9])|(3[01]))$";
const std::string Barricada::DATA_VALIDA = "^(?:(?:31(\\/|-|\\.)(?:0?[13578]|1[02]))\\1|"
                                           "(?:(?:29|30)(\\/|-|\\.)(?:0?[13-9]|1[0-2])\\2))"
                                           "(?:(?:1[6-9]|[2-9]\\d)?\\d{2})$|^(?:29(\\/|-|\\.)"
                                           "0?2\\3(?:(?:(?:1[6-9]|[2-9]\\d)?(?:0[48]|[2468]"
                                           "[048]|[13579][26])|(?:(?:16|[2468][048]|[3579][26])"
                                           "00))))$|^(?:0?[1-9]|1\\d|2[0-8])(\\/|-|\\.)(?:(?:0?"
                                           "[1-9])|(?:1[0-2]))\\4(?:(?:1[6-9]|[2-9]\\d)?\\d{2})$";

void Barricada::validarOpcaoMenu(unsigned &input) {
    // [0,19] é o intervalo de opções do menu
    while (std::cin.fail() or input < 0 or input > 19) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        Utils::printColorNoLine(Foreground::f_yellow, "🕵️ ENTRADA INVÁLIDA. COLOQUE UMA OPÇÃO DO MENU: ");
        std::cin >> input;
    }
}

void Barricada::validarValor(double &valor) {
    while (std::cin.fail() or valor <= 0 or valor > PIB_MUNDIAL) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

        if (valor > PIB_MUNDIAL) {
            Utils::printColor(Foreground::f_red, "🕵️ VOCÊ DIGITOU UM VALOR MAIOR QUE O PIB MUNDIAL.");
            Utils::printColorNoLine(Foreground::f_yellow, "DIGITE UM VALOR VÁLIDO: ");
            std::cin >> valor;
        }
        else if (valor == 0) {
            std::string resposta;
            Utils::printColorNoLine(Foreground::f_yellow, "🕵️ O VALOR É (OU FOI CONVERTIDO PARA) ZERO.\nDESEJA CONTINUAR ? [s/n]: ");
            std::cin >> resposta;
            if (resposta == "s" or resposta == "S") {
                break;
            }
            Utils::printColorNoLine(Foreground::f_yellow, "DIGITE UM NOVO VALOR: ");
            std::cin >> valor;
        }
        else {
            Utils::printColorNoLine(Foreground::f_yellow, "🕵️ ENTRADA INVÁLIDA. COLOQUE UM VALOR POSITIVO: ");
            std::cin >> valor;
        }
    }
}

void Barricada::validarID(unsigned &id) {
    while (std::cin.fail() or id < 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        Utils::printColorNoLine(Foreground::f_yellow, "🕵️ ENTRADA INVÁLIDA. COLOQUE UM VALOR DE ID VÁLIDO: ");
        std::cin >> id;
    }
}

void Barricada::validarNumeroCartao(std::string &numero) {
    while (!std::regex_match(numero, std::regex(NUMERO_CC_VALIDO))) {
        Utils::printColorNoLine(Foreground::f_yellow, "🕵️ ENTRADA INVÁLIDA. COLOQUE UM NÚMERO VÁLIDO (13 A 16 DÍGITOS): ");
        std::cin >> numero;
    }
}

void Barricada::validarCvvCartao(std::string &CVV) {
    while (!std::regex_match(CVV, std::regex(CVV_VALIDO))) {
        Utils::printColorNoLine(Foreground::f_yellow, "🕵️ ENTRADA INVÁLIDA. COLOQUE UM NÚMERO VÁLIDO (3 DÍGITOS): ");
        std::cin >> CVV;
    }
}

void Barricada::validarFechamentoCartao(std::string &fechamento) {
    while (!std::regex_match(fechamento, std::regex(FECHAMENTO_CC_VALIDO))) {
        Utils::printColorNoLine(Foreground::f_yellow, "🕵️ ENTRADA INVÁLIDA. COLOQUE UM DIA VÁLIDO (01 A 31): ");
        std::cin >> fechamento;
    }
}

void Barricada::validarOrigemDestino(std::string &origem, std::string &destino) {
    while (origem == destino) {
        Utils::printColor(Foreground::f_yellow, "🕵️ ENTRADA INVÁLIDA. A CARTEIRA DE ORIGEM É IGUAL A DE DESTINO. ");
        Utils::printColor(Foreground::f_yellow, "INSIRA OS DADOS NOVAMENTE.");
        Utils::printColorNoLine(Efeitos::bold_bright, "ORIGEM: ");
        std::cin >> origem;
        Utils::printColorNoLine(Efeitos::bold_bright, "DESTINO: ");
        std::cin >> destino;
    }
}

void Barricada::validarData(std::string &data) {
    while (!std::regex_match(data, std::regex(DATA_VALIDA))) {
        Utils::printColor(Foreground::f_yellow, "🕵️ ENTRADA INVÁLIDA. DIGITE UMA DATA CORRETA: ");
        std::cin >> data;
    }
}

void Barricada::validarTipo(std::string &tipo) {
    while (!std::regex_match(tipo, std::regex(TIPO_VALIDO))) {
        Utils::printColorNoLine(Foreground::f_yellow, "🕵️ ENTRADA INVÁLIDA. DIGITE UM TIPO CORRETO: ");
        std::cin >> tipo;
    }
}
