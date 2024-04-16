#include "Receita.hpp"

Receita::Receita(std::string carteira, double valor, std::string data, std::string categoria) 
                : Transacao(valor, data, categoria, "receita") {
    this->_carteira = carteira;
}

void Receita::alterarCarteira(std::string nova_carteira) {
    this->_carteira = nova_carteira;
}

std::string Receita::getCarteira() {
    return this->_carteira;
}

void Receita::imprimirInfo() {
    const std::string separador = "\t___________________________________";

    Utils::printColor(Foreground::f_green, separador);

    Utils::printColorNoLine(Efeitos::bold_bright, "\tID DA RECEITA: ");
    std::cout << getID() << std::endl;
    
    Utils::printColorNoLine(Efeitos::bold_bright, "\tVALOR: ");
    std::string valor = std::to_string(getValor());
    valor  = "R$ " + valor.substr(0, valor.find(".") + 3);
    Utils::printColor(Foreground::f_green, valor);

    Utils::printColorNoLine(Efeitos::bold_bright, "\tDATA: ");
    std::cout << getData() << std::endl;
    Utils::printColorNoLine(Efeitos::bold_bright, "\tCATEGORIA: ");
    std::cout << getCategoria() << std::endl;

    Utils::printColor(Foreground::f_green, separador);
}
