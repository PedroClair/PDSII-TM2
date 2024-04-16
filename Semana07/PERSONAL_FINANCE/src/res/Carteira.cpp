#include "Carteira.hpp"

Carteira::Carteira(std::string nome, double saldo_inicial) {
    ValidarEntrada::valor(saldo_inicial);

    this->_nome = nome;
    this->_saldo_atual = saldo_inicial;
    this->_subtipo = "Carteira";
}

Carteira::Carteira(std::string nome, double saldo_inicial, std::string subtipo) {
    ValidarEntrada::valor(saldo_inicial);

    this->_nome = nome;
    this->_saldo_atual = saldo_inicial;
    this->_subtipo = subtipo;
}

Carteira::~Carteira() { }

std::string Carteira::getNome() {
    return this->_nome;
}

double Carteira::getSaldoAtual() {
    return this->_saldo_atual;
}

void Carteira::setSaldoAtual(double saldo) {
    ValidarEntrada::valor(saldo);

    this->_saldo_atual = saldo;
}


std::string Carteira::getSubtipo() {
    return this->_subtipo;
}

//------------------------------------------- Manipulaco do map de transacoes ------------------------------------------ 

void Carteira::adicionarTransacao(std::shared_ptr<Transacao> transacao) {
    this->_transacoes.insert(std::pair<unsigned, std::shared_ptr<Transacao>>(transacao->getID(), transacao));
}

std::shared_ptr<Transacao> Carteira::getTransacao(unsigned id) {
    if (this->getTransacoes().find(id) == this->getTransacoes().end()) {
        throw trsexcp::TransacaoNaoEncontrada(id);
    }
    return this->getTransacoes().find(id)->second;
}

std::map<unsigned, std::shared_ptr<Transacao>> &Carteira::getTransacoes() {
    return this->_transacoes;
}

// ------------------------------------------------- ADD/RM receita ----------------------------------------------------

void Carteira::adicionarReceita(double valor, std::string data, std::string categoria) {
    std::shared_ptr<Receita> receita = std::make_shared<Receita>(this->getNome(), valor, data, categoria);
    setSaldoAtual(getSaldoAtual() + valor);
    this->adicionarTransacao(receita);
}

void Carteira::removerReceita(unsigned id) {
    std::shared_ptr<Transacao> receita = this->getTransacao(id);
    double valor = receita->getValor();

    if (this->getSaldoAtual() < valor) throw ctrexcp::SaldoInsuficiente(this->getSaldoAtual(), valor);

    if (receita->getSubtipo() == "receita") {
        setSaldoAtual(getSaldoAtual() - valor);
        this->_transacoes.erase(id);
    }
    else {
        throw trsexcp::TipoTransacaoInvalido(receita->getSubtipo());
    }
}

// ------------------------------------------------- ADD/RM despesa ----------------------------------------------------

void Carteira::adicionarDespesa(double valor, std::string data, std::string categoria) {
    if (this->getSaldoAtual() < valor) throw ctrexcp::SaldoInsuficiente(this->getSaldoAtual(), valor);

    std::shared_ptr<Despesa> despesa = std::make_shared<Despesa>(this->getNome(), valor, data, categoria);
    setSaldoAtual(getSaldoAtual() - valor);
    this->adicionarTransacao(despesa);
}

void Carteira::removerDespesa(unsigned id) {
    std::shared_ptr<Transacao> despesa = this->getTransacao(id);
    double valor = despesa->getValor();

    if (despesa->getSubtipo() == "despesa") {
        setSaldoAtual(getSaldoAtual() + valor);
        this->_transacoes.erase(id);
    }
    else {
        throw trsexcp::TipoTransacaoInvalido(despesa->getSubtipo());
    }
}

// ---------------------------------------------- Metodos de impressao -------------------------------------------------

void Carteira::ultimasTransacoes(unsigned quantidade) {
    auto it = getTransacoes().rbegin();
    for (unsigned i = 0; i < quantidade && i < getTransacoes().size(); ++i) {
        it->second->imprimirInfo();
        ++it;
    }
}

void Carteira::imprimirInfo() {
    const std::string separador = "___________________________________________";
    Utils::printColor(Foreground::f_yellow, separador);

    Utils::printColorNoLine(Efeitos::bold_bright, "CARTEIRA: ");
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

    Utils::printColor(Foreground::f_yellow, separador);
}
