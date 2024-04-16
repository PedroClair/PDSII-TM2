#include "Despesa.hpp"

Despesa::Despesa(std::string carteira, double valor, std::string data, std::string categoria) 
                : Transacao(valor, data, categoria, "despesa") {
    this->_carteira = carteira;
}

std::string Despesa::getCarteira() {
    return this->_carteira;
}

void Despesa::alterarCarteira(std::string nova_carteira) {
    this->_carteira = nova_carteira;
}

void Despesa::imprimirInfo() {
    const std::string separador = "\t___________________________________";

    Utils::printColor(Foreground::f_red, separador);

    Utils::printColorNoLine(Efeitos::bold_bright, "\tID DA DESPESA: ");
    std::cout << getID() << std::endl;

    Utils::printColorNoLine(Efeitos::bold_bright, "\tVALOR: ");
    std::string valor = std::to_string(getValor());
    valor  = "R$ " + valor.substr(0, valor.find(".") + 3);
    Utils::printColor(Foreground::f_red, valor);

    Utils::printColorNoLine(Efeitos::bold_bright, "\tDATA: ");
    std::cout << getData() << std::endl;
    Utils::printColorNoLine(Efeitos::bold_bright, "\tCATEGORIA: ");
    std::cout << getCategoria() << std::endl;

    Utils::printColor(Foreground::f_red, separador);
}
