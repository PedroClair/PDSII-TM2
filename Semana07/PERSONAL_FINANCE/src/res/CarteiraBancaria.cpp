#include "CarteiraBancaria.hpp"

CarteiraBancaria::CarteiraBancaria(std::string nome, double saldo_inicial)
                                   : Carteira(nome, saldo_inicial, "CarteiraBancaria") {}

CarteiraBancaria::~CarteiraBancaria() {}

// ------------------------------------------- Metodos get/set ---------------------------------------------------------

std::map<std::string, CartaoDeCredito> &CarteiraBancaria::getCartoes() {
    return this->_cartoes;
}

CartaoDeCredito *CarteiraBancaria::getCartaoDeCredito(std::string nome) {
    if (this->_cartoes.find(nome) == this->_cartoes.end()) {
        throw cdcexcp::CartaoNaoEncontrado(nome);
    }
    return &getCartoes().find(nome)->second;
}

// --------------------------------------- ADD/RM cartao de credito ----------------------------------------------------

void CarteiraBancaria::adicionarCartao(std::string nome, std::string numero, std::string CVV, std::string fechamento, double limite) {
    if (this->_cartoes.find(nome) == this->_cartoes.end()) {
        CartaoDeCredito novo_cartao = CartaoDeCredito(nome, numero, CVV, fechamento, limite);
        this->_cartoes.insert(std::pair<std::string, CartaoDeCredito>(nome, novo_cartao));
    }
    else {
        throw cdcexcp::CartaoJaExiste(nome);
    }
}

void CarteiraBancaria::removerCartao(std::string nome) {
    this->getCartoes().erase(this->getCartaoDeCredito(nome)->getNome());
}

// ----------------------------------- ADD/RM despesa cartao de credito ------------------------------------------------

void CarteiraBancaria::adicionarDespesaCartao(std::string nome_cartao, double valor, std::string data, std::string categoria) {
    this->getCartaoDeCredito(nome_cartao)->adicionarDespesa(valor, data, categoria);
}

void CarteiraBancaria::removerDespesaCartao(std::string nome_cartao, unsigned id) {
    this->getCartaoDeCredito(nome_cartao)->removerDespesa(id);
}

// ------------------------------------ Pagar fatura cartao de credito -------------------------------------------------

void CarteiraBancaria::pagarFatura(std::string cartao) {
    CartaoDeCredito *cartaoDeCredito = getCartaoDeCredito(cartao);
    double valor_fatura = cartaoDeCredito->getTotalDespesas();

    if (valor_fatura > this->getSaldoAtual()) {
        throw ctrexcp::SaldoInsuficiente(this->getSaldoAtual(), valor_fatura);
    }
    this->setSaldoAtual(getSaldoAtual() - valor_fatura);

    std::map<unsigned, std::shared_ptr<Despesa>> &despesas_cartao = cartaoDeCredito->getListaDespesas();
    for (auto despesa : despesas_cartao) {
        this->getTransacoes().insert(std::move(despesa));
    }
    despesas_cartao.clear();
}

// ---------------------------------------- Metodos de impressao -------------------------------------------------------

void CarteiraBancaria::imprimirInfo() {
    const std::string separador = "___________________________________________";
    Utils::printColor(Foreground::f_yellow, separador);

    Utils::printColorNoLine(Efeitos::bold_bright, "CARTEIRA BANCÁRIA: ");
    std::cout << getNome() << std::endl;

    Utils::printColorNoLine(Efeitos::bold_bright, "SALDO ATUAL: ");
    std::cout << std::fixed << std::setprecision(2);
    std::string saldo = std::to_string(getSaldoAtual());
    saldo = "R$ " + saldo.substr(0, saldo.find(".") + 3);

    if (getSaldoAtual() > 0) {
        Utils::printColor(Foreground::f_green, saldo);
    }
    else if (getSaldoAtual() <= 0) {
        Utils::printColor(Foreground::f_red, saldo);
    }

    Utils::printColorNoLine(Efeitos::bold_bright, "QUANTIDADE DE TRANSAÇÕES: ");
    std::cout << getTransacoes().size() << std::endl;

    ultimasTransacoes(3);

    Utils::printColorNoLine(Efeitos::bold_bright, "QUANTIDADE DE CARTÕES: ");
    std::cout << getCartoes().size() << std::endl;
    imprimirCartoes();

    Utils::printColor(Foreground::f_yellow, separador);
}

void CarteiraBancaria::imprimirCartoes() {
    for (auto &it : getCartoes()) {
        std::cout << std::endl;
        it.second.imprimirInfo();
    }
}
