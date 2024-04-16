#include "CartaoDeCredito.hpp"

CartaoDeCredito::CartaoDeCredito(std::string nome, std::string numero, std::string CVV, std::string fechamento,
                                 double limite_cartao) {

    ValidarEntrada::numeroCartao(numero);
    ValidarEntrada::cvvCartao(CVV);
    ValidarEntrada::fechamentoCartao(fechamento);
    ValidarEntrada::valor(limite_cartao);

    this->_nome = nome;
    this->_numero = numero;
    this->_CVV = CVV;
    this->_fechamento = fechamento;
    this->_limite_cartao = limite_cartao;
}

// -------------------------------------------------- Metodos set/get --------------------------------------------------

std::string CartaoDeCredito::getNome() {
    return this->_nome;
}

std::string CartaoDeCredito::getNumero() {
    return this->_numero;
}

std::string CartaoDeCredito::getCVV() {
    return this->_CVV;
}

std::string CartaoDeCredito::getFechamento() {
    return this->_fechamento;
}

double CartaoDeCredito::getLimite() {
    return this->_limite_cartao;
}

std::map<unsigned, std::shared_ptr<Despesa>> &CartaoDeCredito::getListaDespesas() {
    return this->_despesas;
}

double CartaoDeCredito::getTotalDespesas() {
    double soma_despesas = 0;
    for (auto it : this->_despesas) {
       soma_despesas += it.second->getValor();
    }
    return soma_despesas;
}

void CartaoDeCredito::alterarLimiteCartao(double novo_limite) {
    ValidarEntrada::valor(novo_limite);
    this->_limite_cartao = novo_limite;
}

// -------------------------------------------------- ADD/RM despesa ---------------------------------------------------

void CartaoDeCredito::adicionarDespesa(double valor, std::string data, std::string categoria) {
    if (this->getTotalDespesas() + valor > this->_limite_cartao) {
        throw cdcexcp::LimiteExcedido(this->_nome, this->_numero, this->_limite_cartao, this->getTotalDespesas());
    }

    // A "carteira" de uma despesa do cartao de credito eh o nome do cartao
    std::shared_ptr<Despesa> despesa = std::make_shared<Despesa>(this->_nome, valor, data, categoria);
    this->_despesas.insert(std::pair<unsigned, std::shared_ptr<Despesa>>(despesa->getID(), despesa));
}

void CartaoDeCredito::removerDespesa(unsigned id) {
    if (this->_despesas.find(id) == this->_despesas.end()) {
        throw trsexcp::TransacaoNaoEncontrada(id);
    }

    for (auto it = this->_despesas.begin(); it != this->_despesas.end(); it++) {
        if (it->second->getID() == id) {
            this->_despesas.erase(it);
            break;
        }
    }
}

// ------------------------------------------------ Metodos de impressao -----------------------------------------------

void CartaoDeCredito::listarDespesas() {
    this->imprimirInfo();
    for (auto it : _despesas) {
        it.second->imprimirInfo();
    }
}

void CartaoDeCredito::imprimirInfo() {
    const std::string separador = "\t___________________________________";
    Utils::printColor(Foreground::f_cyan, separador);

    Utils::printColorNoLine(Efeitos::bold_bright, "\tCARTÃO: ");
    std::cout << getNome() << std::endl;
    Utils::printColorNoLine(Efeitos::bold_bright, "\tNÚMERO: ");
    std::cout << getNumero() << std::endl;
    Utils::printColorNoLine(Efeitos::bold_bright, "\tCVV: ");
    std::cout << getCVV() << std::endl;
    Utils::printColorNoLine(Efeitos::bold_bright, "\tFECHAMENTO: ");
    std::cout << getFechamento() << std::endl;
    Utils::printColorNoLine(Efeitos::bold_bright, "\tLIMITE: ");
    std::cout << "R$ " << std::fixed << std::setprecision(2) << getLimite() << std::endl;
    Utils::printColorNoLine(Efeitos::bold_bright, "\tLIMITE DISPONÍVEL: ");

    double limite_disp_t = getLimite() - getTotalDespesas();
    std::string limite_disp = std::to_string(limite_disp_t);
    limite_disp = "R$ " + limite_disp.substr(0, limite_disp.find(".") + 3);

    if (limite_disp_t > 0) {
        Utils::printColor(Foreground::f_green, limite_disp);
    } 
    else if (limite_disp_t <= 0) {
        Utils::printColor(Foreground::f_red, limite_disp);
    }

    Utils::printColorNoLine(Efeitos::bold_bright, "\tVALOR PRÓXIMA FATURA: ");
    std::cout << "R$ " << this->getTotalDespesas() << std::endl;
    Utils::printColorNoLine(Efeitos::bold_bright, "\tDESPESAS REGISTRADAS: ");
    std::cout << this->_despesas.size() << std::endl;

    Utils::printColor(Foreground::f_cyan, separador);
}
