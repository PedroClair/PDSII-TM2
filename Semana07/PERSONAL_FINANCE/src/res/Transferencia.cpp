#include "Transferencia.hpp"
#include "TransacaoExcp.hpp"

Transferencia::Transferencia(double valor, std::string data, std::string categoria, std::string origem, std::string destino)
        : Transacao(valor, data, categoria, "transferencia") {
    ValidarEntrada::origemDestino(origem, destino);

    this->_origem = origem;
    this->_destino = destino;
}

void Transferencia::alterarDestino(std::string novo_destino) {
    if (novo_destino == this->_origem) throw trsexcp::OrigemDestinoIguais(novo_destino);
    this->_destino = novo_destino;
}

void Transferencia::alterarOrigem(std::string nova_origem) {
    if (nova_origem == this->_destino) throw trsexcp::OrigemDestinoIguais(nova_origem);
    this->_origem = nova_origem;
}

std::string Transferencia::getOrigem() {
    return this->_origem;
}

std::string Transferencia::getDestino() {
    return this->_destino;
}

void Transferencia::imprimirInfo() {
    const std::string separador = "\t___________________________________";
    Utils::printColor(Foreground::f_yellow, separador);

    Utils::printColorNoLine(Efeitos::bold_bright, "\tID DA TRANSFERÊNCIA: ");
    std::cout << getID() << std::endl;
    
    Utils::printColorNoLine(Efeitos::bold_bright, "\tORIGEM: ");
    std::cout << getOrigem() << std::endl;
    Utils::printColorNoLine(Efeitos::bold_bright, "\tDESTINO: ");
    std::cout << getDestino() << std::endl;

    Utils::printColorNoLine(Efeitos::bold_bright, "\tVALOR: ");
    std::string valor = std::to_string(getValor());
    valor  = "R$ " + valor.substr(0, valor.find(".") + 3);
    Utils::printColor(Foreground::f_green, valor);

    Utils::printColorNoLine(Efeitos::bold_bright, "\tDATA: ");
    std::cout << getData() << std::endl;
    Utils::printColorNoLine(Efeitos::bold_bright, "\tCATEGORIA: ");
    std::cout << getCategoria() << std::endl;
    Utils::printColor(Foreground::f_yellow, separador);
}
