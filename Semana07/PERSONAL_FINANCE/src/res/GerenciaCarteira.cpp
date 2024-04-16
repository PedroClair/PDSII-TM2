#include "GerenciaCarteira.hpp"

GerenciaCarteira::GerenciaCarteira() {}

std::map<std::string, std::shared_ptr<Carteira>>& GerenciaCarteira::getCarteiras() {
    return this->_carteiras;
}

std::shared_ptr<Carteira> GerenciaCarteira::getCarteira(std::string nome) {
    // A funcao 'find' map retorna um ponteiro para map.end se nao houver chave com o mesmo 'nome'
    if (getCarteiras().find(nome) == getCarteiras().end()) {
        throw ctrexcp::ContaNaoEncontrada(nome);
    }
    else {
        return getCarteiras().find(nome)->second;
    }
}

// ---------------------------------------- ADD/RM Carteira ------------------------------------------------------------

void GerenciaCarteira::adicionarCarteira(std::string nome, double saldo_inicial) {
    // Carteira
    ValidarEntrada::valor(saldo_inicial);

    if (getCarteiras().find(nome) == getCarteiras().end()) {
        std::shared_ptr<Carteira> carteira = std::make_shared<Carteira>(nome, saldo_inicial);
        this->_carteiras.insert(std::pair<std::string, std::shared_ptr<Carteira>>(nome, carteira));
    }
    else {
        throw ctrexcp::ContaJaExiste(nome);
    }
}

void GerenciaCarteira::adicionarCarteira(double saldo_inicial, std::string nome) {
    // Overload para adicionar CarteiraBancaria
    if (getCarteiras().find(nome) == getCarteiras().end()) {
        std::shared_ptr<CarteiraBancaria> carteira = std::make_shared<CarteiraBancaria>(nome, saldo_inicial);
        this->_carteiras.insert(std::pair<std::string, std::shared_ptr<Carteira>>(nome, carteira));
    }
    else {
        throw ctrexcp::ContaJaExiste(nome);
    }
}

void GerenciaCarteira::removerCarteira(std::string nome) {
    if (this->getCarteiras().find(nome) == this->getCarteiras().end()) {
        throw ctrexcp::ContaNaoEncontrada(nome);
    }

    this->_carteiras.erase(this->_carteiras.find(nome));
}

// ---------------------------------------- ADD/RM Receita -------------------------------------------------------------

void GerenciaCarteira::adicionarReceita(std::string carteira, double valor, std::string data, std::string categoria) {
    std::shared_ptr<Carteira> minha_carteira = getCarteira(carteira);
    minha_carteira->adicionarReceita(valor, data, categoria);
}

void GerenciaCarteira::removerReceita(std::string carteira, unsigned id) {
    getCarteira(carteira)->removerReceita(id);
}

// ---------------------------------------- ADD/RM Despesa -------------------------------------------------------------

void GerenciaCarteira::adicionarDespesa(std::string carteira, double valor, std::string data, std::string categoria) {
    std::shared_ptr<Carteira> minha_carteira = getCarteira(carteira);
    minha_carteira->adicionarDespesa(valor, data, categoria);
}

void GerenciaCarteira::removerDespesa(std::string carteira, unsigned id) {
    getCarteira(carteira)->removerDespesa(id);
}

// ------------------------------------- ADD/RM Transferencia ----------------------------------------------------------

void GerenciaCarteira::adicionarTransferencia(double valor, std::string data, std::string categoria, std::string origem,
                                              std::string destino) {

    ValidarEntrada::origemDestino(origem, destino);

    std::shared_ptr<Carteira> carteira_origem = getCarteira(origem);
    if (carteira_origem->getSaldoAtual() < valor) throw ctrexcp::SaldoInsuficiente(carteira_origem->getSaldoAtual(), valor);

    std::shared_ptr<Carteira> carteira_destino = getCarteira(destino);
    std::shared_ptr<Transferencia> transferencia = std::make_shared<Transferencia>(valor, data, categoria, origem, destino);

    carteira_origem->setSaldoAtual(carteira_origem->getSaldoAtual() - valor);
    carteira_destino->setSaldoAtual(carteira_destino->getSaldoAtual() + valor);

    carteira_origem->adicionarTransacao(transferencia);
    carteira_destino->adicionarTransacao(transferencia);
}

void GerenciaCarteira::removerTransferencia(std::string carteira, unsigned id) {
    std::shared_ptr<Carteira> minha_carteira = getCarteira(carteira);

    std::shared_ptr<Transacao> transacao = minha_carteira->getTransacao(id);

    if (transacao->getSubtipo() != "transferencia") {
        throw trsexcp::TipoTransacaoInvalido(transacao->getSubtipo());
    }

    std::shared_ptr<Transferencia> transferencia;
    transferencia = std::dynamic_pointer_cast<Transferencia>(transacao);

    std::shared_ptr<Carteira> carteira_origem = this->getCarteira(transferencia->getOrigem());
    std::shared_ptr<Carteira> carteira_destino = this->getCarteira(transferencia->getDestino());
    
    // Verificar se há saldo suficiente para ser debitado na carteiira de destino
    if (carteira_destino->getSaldoAtual() < transferencia->getValor()) {
        throw ctrexcp::SaldoInsuficiente(carteira_destino->getSaldoAtual(), transferencia->getValor());
    }

    carteira_origem->setSaldoAtual(carteira_origem->getSaldoAtual() + transferencia->getValor());
    carteira_destino->setSaldoAtual(carteira_destino->getSaldoAtual() - transferencia->getValor());

    carteira_origem->getTransacoes().erase(id);
    carteira_destino->getTransacoes().erase(id);
}

// ------------------------------------ ADD/RM Cartao de Credito -------------------------------------------------------

void GerenciaCarteira::adicionarCartao(std::string carteira, std::string nome, std::string numero, std::string CVV,
                                       std::string fechamento, double limite_cartao) {

    std::shared_ptr<Carteira> minha_carteira = getCarteira(carteira);
    if (minha_carteira->getSubtipo() == "CarteiraBancaria") {
        std::shared_ptr<CarteiraBancaria> carteira_bancaria;
        carteira_bancaria = std::dynamic_pointer_cast<CarteiraBancaria>(minha_carteira);

        carteira_bancaria->adicionarCartao(nome, numero, CVV, fechamento, limite_cartao);
    } 
    else {
        throw ctrexcp::ContaNaoPermiteCartao(carteira, minha_carteira->getSubtipo());
    }
}

void GerenciaCarteira::removerCartao(std::string carteira, std::string cartao) {
    std::shared_ptr<Carteira> minha_carteira = getCarteira(carteira);
    if (minha_carteira->getSubtipo() == "CarteiraBancaria") {
        std::shared_ptr<CarteiraBancaria> carteira_bancaria;
        carteira_bancaria = std::dynamic_pointer_cast<CarteiraBancaria>(minha_carteira);

        carteira_bancaria->removerCartao(cartao);
    }
    else {
        throw ctrexcp::ContaNaoPermiteCartao(carteira, minha_carteira->getSubtipo());
    }
}

// -------------------------------- ADD/RM Despesa Cartao de Credito ---------------------------------------------------

void GerenciaCarteira::adicionarDespesaCartao(std::string carteira, std::string cartao, double valor, std::string data, 
                                              std::string categoria) {

    std::shared_ptr<Carteira> minha_carteira = getCarteira(carteira);
    if (minha_carteira->getSubtipo() == "CarteiraBancaria") {
        std::shared_ptr<CarteiraBancaria> carteira_bancaria;
        carteira_bancaria = std::dynamic_pointer_cast<CarteiraBancaria>(minha_carteira);

        carteira_bancaria->getCartaoDeCredito(cartao)->adicionarDespesa(valor, data, categoria);
    }
    else {
        throw ctrexcp::ContaNaoPermiteCartao(carteira, minha_carteira->getSubtipo());
    }
}

void GerenciaCarteira::removerDespesaCartao(std::string carteira, std::string cartao, unsigned id) {
    std::shared_ptr<Carteira> minha_carteira = getCarteira(carteira);
    if (minha_carteira->getSubtipo() == "CarteiraBancaria") {
        std::shared_ptr<CarteiraBancaria> carteira_bancaria;
        carteira_bancaria = std::dynamic_pointer_cast<CarteiraBancaria>(minha_carteira);

        carteira_bancaria->getCartaoDeCredito(cartao)->removerDespesa(id);
    }
    else {
        throw ctrexcp::ContaNaoPermiteCartao(carteira, minha_carteira->getSubtipo());
    }
}

// ------------------------- Pagar fatura / listar despeas cartao de credito -------------------------------------------

void GerenciaCarteira::pagarFaturaCartao(std::string carteira, std::string cartao) {
    std::shared_ptr<Carteira> minha_carteira = getCarteira(carteira);
    if (minha_carteira->getSubtipo() == "CarteiraBancaria") {
        std::shared_ptr<CarteiraBancaria> carteira_bancaria;
        carteira_bancaria = std::dynamic_pointer_cast<CarteiraBancaria>(minha_carteira);

        carteira_bancaria->pagarFatura(cartao);
    }
    else {
        // TO DO: Ser possivel pagar fatura do cartao com uma carteira
        throw ctrexcp::ContaNaoPermiteCartao(carteira, minha_carteira->getSubtipo());
    }
}

void GerenciaCarteira::listarDespesasCartao(std::string carteira, std::string cartao) {
    std::shared_ptr<Carteira> minha_carteira = getCarteira(carteira);
    if (minha_carteira->getSubtipo() == "CarteiraBancaria") {
        std::shared_ptr<CarteiraBancaria> carteira_bancaria;
        carteira_bancaria = std::dynamic_pointer_cast<CarteiraBancaria>(minha_carteira);

        carteira_bancaria->getCartaoDeCredito(cartao)->listarDespesas();
    }
    else {
        throw ctrexcp::ContaNaoPermiteCartao(carteira, minha_carteira->getSubtipo());
    }
}

// ----------------------------------------- Metodos de impressao ------------------------------------------------------

void GerenciaCarteira::imprimirCarteiras() {
    if(!(getCarteiras().empty())) {
        for (auto const& carteira : getCarteiras()) {
            carteira.second->imprimirInfo();
        }
    } 
    else {
        throw gcexcp::PerfilVazio();
    }
}

void GerenciaCarteira::listarTransacao(std::string carteira, std::string tipo) {
    tipo = (tipo == "d") ? "despesa" 
         : (tipo == "r") ? "receita" 
         : (tipo == "t") ? "transferencia"
         : (tipo == "a") ? "todas"
         : throw trsexcp::TipoTransacaoInvalido(tipo);

    std::shared_ptr<Carteira> minha_carteira = getCarteira(carteira);

    Utils::printColorNoLine(Efeitos::bold_bright, "CARTEIRA: ");
    Utils::printColorNoLine(Efeitos::bold_bright, minha_carteira->getNome());

    if (tipo == "despesa" or tipo == "receita" or tipo == "transferencia") {
        int i = 0;
        for (auto const& it : minha_carteira->getTransacoes()) {
            if (it.second->getSubtipo() == tipo) {
                std::cout << std::endl; 
                it.second->imprimirInfo();
                ++i;
            }   
        }
        if (i == 0) {
            std::cout << std::endl;
            Utils::printColor(Foreground::f_yellow, "Nenhuma " + tipo + " encontrada");
        }
    }
    else if (tipo == "todas") {
        int i = 0;
        for (auto const& it : minha_carteira->getTransacoes()) {
            std::cout << std::endl; 
            it.second->imprimirInfo();
            ++i;
        }
        if (i == 0) {
            std::cout << std::endl;
            Utils::printColor(Foreground::f_yellow, "Nenhuma transação encontrada");
        }
    }
}
