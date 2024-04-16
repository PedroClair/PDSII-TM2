#include "GerenciaCarteira.hpp"
#include "Utils.hpp"
#include "Barricada.hpp"

#include <iostream>
#include <string>


void printMenu();
void printMensagem();

int main(int argc, char const *argv[]) {

    const std::string separador = "===========================================";
    const int corSeparador = Foreground::f_yellow;

    GerenciaCarteira gc;

    unsigned input,
             id_transacao;
    
    double saldo_inicial,
           valor_transacao,
           limite_cartao;
    
    std::string nome,
                conta,
                data,
                categoria,
                cartao,
                destino,
                origem,
                CVV,
                fechamento,
                numero_cartao,
                tipo;

    Utils::limparConsole();

    Utils::printColor(corSeparador, separador);
    printMenu();
    Utils::printColor(corSeparador, separador);

    while (1) {

        std::cin >> input;

        Barricada::validarOpcaoMenu(input);

        switch (input) {
            case 0: // Listar opcoes
                Utils::printColor(corSeparador, separador);
                printMenu();
                Utils::printColor(corSeparador, separador);

                continue;

            case 1: // Adicionar carteira
                Utils::printColor(corSeparador, separador);
                Utils::printColor(Efeitos::inverse, "-------------- NOVA CARTEIRA --------------");

                Utils::printColorNoLine(Efeitos::bold_bright, "NOME CARTEIRA: ");
                std::cin >> nome;

                Utils::printColorNoLine(Efeitos::bold_bright, "SALDO INICIAL: ");
                std::cin >> saldo_inicial;
                Barricada::validarValor(saldo_inicial);

                try {
                    gc.adicionarCarteira(nome, saldo_inicial);
                    Utils::printColor(Foreground::f_green, "CARTEIRA ADICIONADA ✔️");
                }
                catch (ctrexcp::ValorInvalido &e) {
                    Utils::printColor(Foreground::f_red, e.what());
                    Utils::printColorNoLine(Foreground::f_red, "SALDO: "); 
                    std::cout << e.getValor() << std::endl;
                }
                catch (ctrexcp::ContaJaExiste &e) {
                    Utils::printColor(Foreground::f_red, e.what());
                    Utils::printColorNoLine(Foreground::f_red, "CONTA: "); 
                    std::cout << e.getNome() << std::endl;
                }

                Utils::printColor(corSeparador, separador);
                std::cout << std::endl;
                printMensagem();

                continue;

            case 2: // Adicionar carteira bancária
                Utils::printColor(corSeparador, separador);
                Utils::printColor(Efeitos::inverse, "--------------- NOVA CONTA ----------------");

                Utils::printColorNoLine(Efeitos::bold_bright, "NOME CARTEIRA: ");
                std::cin >> nome;

                Utils::printColorNoLine(Efeitos::bold_bright, "SALDO INICIAL: ");
                std::cin >> saldo_inicial;
                Barricada::validarValor(saldo_inicial);

                try {
                    gc.adicionarCarteira(saldo_inicial, nome);
                    Utils::printColor(Foreground::f_green, "CARTEIRA BANCÁRIA ADICIONADA ✔️");
                }
                catch (ctrexcp::ValorInvalido& e) {
                    Utils::printColor(Foreground::f_red, e.what());
                    Utils::printColorNoLine(Foreground::f_red, "SALDO: "); 
                    std::cout << e.getValor() << std::endl;
                }
                catch (ctrexcp::ContaJaExiste &e) {
                    Utils::printColor(Foreground::f_red, e.what());
                    Utils::printColorNoLine(Foreground::f_red, "CONTA: "); 
                    std::cout << e.getNome() << std::endl;
                }

                Utils::printColor(corSeparador, separador);
                std::cout << std::endl;
                printMensagem();

                continue;

            case 3: // Adicionar receita
                Utils::printColor(corSeparador, separador);
                Utils::printColor(Efeitos::inverse, "----------- ADICIONAR RECEITA -------------");

                Utils::printColorNoLine(Efeitos::bold_bright, "CONTA: ");
                std::cin >> conta;

                Utils::printColorNoLine(Efeitos::bold_bright, "VALOR: ");
                std::cin >> valor_transacao;
                Barricada::validarValor(valor_transacao);

                Utils::selecionarData(data);
                Barricada::validarData(data);

                Utils::printColorNoLine(Efeitos::bold_bright, "CATEGORIA: ");
                std::cin >> categoria;

                try {
                    gc.adicionarReceita(conta, valor_transacao, data, categoria);
                    Utils::printColor(Foreground::f_green, "RECEITA ADICIONADA ✔️");
                }
                catch (ctrexcp::ContaNaoEncontrada& e) {
                    Utils::printColor(Foreground::f_red, e.what());
                    Utils::printColorNoLine(Foreground::f_red, "CONTA: ");
                    std::cout << e.getNome() << std::endl;
                }
                catch (ctrexcp::ValorInvalido& e) {
                    Utils::printColor(Foreground::f_red, e.what());
                    Utils::printColorNoLine(Foreground::f_red, "SALDO: "); 
                    std::cout << e.getValor() << std::endl;
                }
                catch (trsexcp::DataInvalida &e) {
                    Utils::printColor(Foreground::f_red, e.what());
                    Utils::printColor(Foreground::f_red, "DATA: ");
                    std::cout << e.getData() << std::endl;
                }

                Utils::printColor(corSeparador, separador);
                std::cout << std::endl;
                printMensagem();

                continue;

            case 4: // Adicionar despesa
                Utils::printColor(corSeparador, separador);
                Utils::printColor(Efeitos::inverse, "------------ ADICIONAR DESPESA ------------");

                Utils::printColorNoLine(Efeitos::bold_bright, "CONTA: ");
                std::cin >> conta;

                Utils::printColorNoLine(Efeitos::bold_bright, "VALOR: ");
                std::cin >> valor_transacao;
                Barricada::validarValor(valor_transacao);

                Utils::selecionarData(data);
                Barricada::validarData(data);

                Utils::printColorNoLine(Efeitos::bold_bright, "CATEGORIA: ");
                std::cin >> categoria;

                try {
                    gc.adicionarDespesa(conta, valor_transacao, data, categoria);
                    Utils::printColor(Foreground::f_green, "DESPESA ADICIONADA ✔️");
                }
                catch (ctrexcp::ContaNaoEncontrada& e) {
                    Utils::printColor(Foreground::f_red, e.what());
                    Utils::printColorNoLine(Foreground::f_red, "CONTA: ");
                    std::cout << e.getNome() << std::endl;
                }
                catch (ctrexcp::ValorInvalido& e) {
                    Utils::printColor(Foreground::f_red, e.what());
                    Utils::printColorNoLine(Foreground::f_red, "SALDO: "); 
                    std::cout << e.getValor() << std::endl;
                }
                catch (ctrexcp::SaldoInsuficiente &e) {
                    Utils::printColor(Foreground::f_red, e.what());
                    Utils::printColorNoLine(Foreground::f_red, "DIFERENÇA: ");
                    std::cout << e.getSaldo() - e.getDespesa() << std::endl;
                } 
                catch (trsexcp::DataInvalida &e) {
                    Utils::printColor(Foreground::f_red, e.what());
                    Utils::printColorNoLine(Foreground::f_red, "DATA: ");
                    std::cout << e.getData() << std::endl;
                }

                Utils::printColor(corSeparador, separador);
                std::cout << std::endl;
                printMensagem();

                continue;

            case 5: // Adicionar despesa cartao de credito
                Utils::printColor(corSeparador, separador);
                Utils::printColor(Efeitos::inverse, "--- ADICIONAR DESPESA CARTAO DE CREDITO ---");

                Utils::printColorNoLine(Efeitos::bold_bright, "CONTA: ");
                std::cin >> conta;
                Utils::printColorNoLine(Efeitos::bold_bright, "CARTÃO: ");
                std::cin >> cartao;

                Utils::selecionarData(data);
                Barricada::validarData(data);

                Utils::printColorNoLine(Efeitos::bold_bright, "CATEGORIA: ");
                std::cin >> categoria;
                Utils::printColorNoLine(Efeitos::bold_bright, "VALOR: ");
                std::cin >> valor_transacao;
                Barricada::validarValor(valor_transacao);

                try {
                    gc.adicionarDespesaCartao(conta, cartao, valor_transacao, data, categoria);
                    Utils::printColor(Foreground::f_green, "DESPESA CARTÃO DE CRÉDITO ADICIONADA ✔️");
                }
                catch (ctrexcp::ContaNaoEncontrada& e) {
                    Utils::printColor(Foreground::f_red, e.what());
                    Utils::printColorNoLine(Foreground::f_red, "CONTA: ");
                    std::cout << e.getNome() << std::endl;
                }
                catch (cdcexcp::CartaoNaoEncontrado& e) {
                    Utils::printColor(Foreground::f_red, e.what());
                    Utils::printColorNoLine(Foreground::f_red, "CARTÃO: ");
                    std::cout << e.getNomeCartao() << std::endl;  
                }
                catch (cdcexcp::LimiteExcedido& e) {
                    Utils::printColor(Foreground::f_red, e.what());
                    Utils::printColorNoLine(Foreground::f_red, "LIMITE RESTANTE DO CARTÃO: "); 
                    std::cout << "R$ " << e.getLimiteCartao() - e.getSomaDespesasAtuais << std::endl;
                }
                catch (trsexcp::DataInvalida &e) {
                    Utils::printColor(Foreground::f_red, e.what());
                    Utils::printColor(Foreground::f_red, "DATA: ");
                    std::cout << e.getData() << std::endl;
                }

                Utils::printColor(corSeparador, separador);
                std::cout << std::endl;
                printMensagem();

                continue;

            case 6: // Adicionar transferencia
                Utils::printColor(corSeparador, separador);
                Utils::printColor(Efeitos::inverse, "--------- ADICIONAR TRANSFERENCIA ---------");

                Utils::printColorNoLine(Efeitos::bold_bright, "VALOR: ");
                std::cin >> valor_transacao;

                Barricada::validarValor(valor_transacao);
                Utils::selecionarData(data);
                Barricada::validarData(data);

                Utils::printColorNoLine(Efeitos::bold_bright, "CATEGORIA: ");
                std::cin >> categoria;

                Utils::printColorNoLine(Efeitos::bold_bright, "ORIGEM: ");
                std::cin >> origem;
                Utils::printColorNoLine(Efeitos::bold_bright, "DESTINO: ");
                std::cin >> destino;
                Barricada::validarOrigemDestino(origem, destino);

                try {
                    gc.adicionarTransferencia(valor_transacao, data, categoria, origem, destino);
                    Utils::printColor(Foreground::f_green, "TRANSFERÊNCIA ADICIONADA ✔️");
                }
                catch (trsexcp::OrigemDestinoIguais& e) {
                    Utils::printColor(Foreground::f_red, e.what());
                    Utils::printColorNoLine(Foreground::f_red, "CONTA ORIGEM IGUAL AO DESTINO: ");
                    std::cout << e.getOrigemDestino() << std::endl;
                }
                catch (ctrexcp::SaldoInsuficiente& e) {
                    Utils::printColor(Foreground::f_red, e.what());
                    Utils::printColorNoLine(Foreground::f_red, "SALDO NA CONTA: ");
                    std::cout << "R$ " << e.getSaldo() << std::endl;
                    Utils::printColorNoLine(Foreground::f_red, "VALOR QUE DEVE SER DEBITADO: ");
                    std::cout << "R$ " << e.getDespesa() << std::endl;
                }
                catch (ctrexcp::ContaNaoEncontrada& e) {
                    Utils::printColor(Foreground::f_red, e.what());
                    Utils::printColorNoLine(Foreground::f_red, "CONTA: ");
                    std::cout << e.getNome() << std::endl;
                } 
                catch (trsexcp::DataInvalida &e) {
                    Utils::printColor(Foreground::f_red, e.what());
                    Utils::printColorNoLine(Foreground::f_red, "DATA: ");
                    std::cout << e.getData() << std::endl;
                }

                Utils::printColor(corSeparador, separador);
                std::cout << std::endl;
                printMensagem();

                continue;

            case 7: // Adicionar cartao de credito
                Utils::printColor(corSeparador, separador);
                Utils::printColor(Efeitos::inverse, "------- ADICIONAR CARTAO DE CREDITO -------");

                Utils::printColorNoLine(Efeitos::bold_bright, "CONTA: ");
                std::cin >> conta;

                Utils::printColorNoLine(Efeitos::bold_bright, "NOME CARTÃO: ");
                std::cin >> nome;
                
                Utils::printColorNoLine(Efeitos::bold_bright, "NÚMERO CARTÃO: ");
                std::cin >> numero_cartao;
                Barricada::validarNumeroCartao(numero_cartao);

                Utils::printColorNoLine(Efeitos::bold_bright, "CVV CARTÃO: ");
                std::cin >> CVV;
                Barricada::validarCvvCartao(CVV);

                Utils::printColorNoLine(Efeitos::bold_bright, "FECHAMENTO CARTÃO: ");
                std::cin >> fechamento;
                Barricada::validarFechamentoCartao(fechamento);

                Utils::printColorNoLine(Efeitos::bold_bright, "LIMITE CARTÃO: ");
                std::cin >> limite_cartao;
                Barricada::validarValor(limite_cartao);

                try {
                    gc.adicionarCartao(conta, nome, numero_cartao, CVV, fechamento, limite_cartao);
                    Utils::printColor(Foreground::f_green, "CARTÃO DE CRÉDITO CRIADO ✔️");
                }
                catch (ctrexcp::ContaNaoEncontrada& e) {
                    Utils::printColor(Foreground::f_red, e.what());
                    Utils::printColorNoLine(Foreground::f_red, "CONTA: ");
                    std::cout << e.getNome() << std::endl;
                }
                catch (cdcexcp::CartaoJaExiste& e) {
                    Utils::printColor(Foreground::f_red, e.what());
                    Utils::printColorNoLine(Foreground::f_red, "CARTAO: ");
                    std::cout << e.getNome() << std::endl;
                }
                catch (ctrexcp::ValorInvalido &e) {
                    Utils::printColor(Foreground::f_red, e.what());
                    Utils::printColorNoLine(Foreground::f_red, "SALDO: "); 
                    std::cout << e.getValor() << std::endl;
                }
                catch (cdcexcp::NumeroInvalido& e) {
                    Utils::printColor(Foreground::f_red, e.what());
                    Utils::printColorNoLine(Foreground::f_red, "NÚMERO: "); 
                    std::cout << e.getNumero() << std::endl;
                }
                catch (cdcexcp::CVVInvalido& e) {
                    Utils::printColor(Foreground::f_red, e.what());
                    Utils::printColorNoLine(Foreground::f_red, "CVV: "); 
                    std::cout << e.getCVV() << std::endl;          
                }
                catch (cdcexcp::FechamentoInvalido& e) {
                    Utils::printColor(Foreground::f_red, e.what());
                    Utils::printColorNoLine(Foreground::f_red, "FECHAMENTO: "); 
                    std::cout << e.getFechamento() << std::endl;
                              
                }
                catch (ctrexcp::ContaNaoPermiteCartao &e) {
                    Utils::printColor(Foreground::f_red, e.what());
                    Utils::printColorNoLine(Foreground::f_red, "CONTA: ");
                    std::cout << e.getNomeConta() << std::endl;
                    Utils::printColorNoLine(Foreground::f_red, "TIPO: ");
                    std::cout << e.getSubtipoConta() << std::endl;
                }

                Utils::printColor(corSeparador, separador);
                std::cout << std::endl;
                printMensagem();

                continue;

            case 8: // Remover carteira
                Utils::printColor(corSeparador, separador);
                Utils::printColor(Efeitos::inverse, "------------ REMOVER CARTEIRA -------------");

                Utils::printColorNoLine(Efeitos::bold_bright, "NOME: ");
                std::cin >> nome;

                try {
                    gc.removerCarteira(nome);
                    Utils::printColor(Foreground::f_green, "CARTEIRA REMOVIDA ✔️");
                }
                catch (ctrexcp::ContaNaoEncontrada& e) {
                    Utils::printColor(Foreground::f_red, e.what());
                    Utils::printColorNoLine(Foreground::f_red, "CONTA: ");
                    std::cout << e.getNome() << std::endl;
                }
                Utils::printColor(corSeparador, separador);
                std::cout << std::endl;
                printMensagem();

                continue;

            case 9: // Remover carteira bancária
                Utils::printColor(corSeparador, separador);
                Utils::printColor(Efeitos::inverse, "-------------- REMOVER CARTEIRA -----------");

                Utils::printColorNoLine(Efeitos::bold_bright, "CARTEIRA BANCÁRIA: ");
                std::cin >> nome;

                try {
                    gc.removerCarteira(nome);
                    Utils::printColor(Foreground::f_green, "CARTEIRA BANCÁRIA REMOVIDA ✔️");
                }
                catch (ctrexcp::ContaNaoEncontrada& e) {
                    Utils::printColor(Foreground::f_red, e.what());
                    Utils::printColorNoLine(Foreground::f_red, "CONTA: ");
                    std::cout << e.getNome() << std::endl;
                }

                Utils::printColor(corSeparador, separador);
                std::cout << std::endl;
                printMensagem();

                continue;

            case 10: // Remover receita
                Utils::printColor(corSeparador, separador);
                Utils::printColor(Efeitos::inverse, "------------- REMOVER RECEITA -------------");

                Utils::printColorNoLine(Efeitos::bold_bright, "CARTEIRA: ");
                std::cin >> conta;

                Utils::printColorNoLine(Efeitos::bold_bright, "ID DA TRANSAÇÃO: ");
                std::cin >> id_transacao;
                Barricada::validarID(id_transacao);

                try {
                    gc.removerReceita(conta, id_transacao);
                    Utils::printColor(Foreground::f_green, "RECEITA REMOVIDA ✔️");
                }
                catch (ctrexcp::ContaNaoEncontrada& e) {
                    Utils::printColor(Foreground::f_red, e.what());
                    Utils::printColorNoLine(Foreground::f_red, "CARTEIRA: ");
                    std::cout << e.getNome() << std::endl;
                }
                catch (trsexcp::TransacaoNaoEncontrada& e) {
                    Utils::printColor(Foreground::f_red, e.what());
                    Utils::printColorNoLine(Foreground::f_red, "ID DA TRANSAÇÃO: ");
                    std::cout << e.getID() << std::endl;
                }
                catch (trsexcp::TipoTransacaoInvalido& e) {
                    Utils::printColor(Foreground::f_red, e.what());
                    Utils::printColorNoLine(Foreground::f_red, "TIPO DA TRANSAÇÃO: ");
                    std::cout << e.getTipo() << std::endl;
                }

                Utils::printColor(corSeparador, separador);
                std::cout << std::endl;
                printMensagem();

                continue;

            case 11: // Remover despesa
                Utils::printColor(corSeparador, separador);
                Utils::printColor(Efeitos::inverse, "------------- REMOVER DESPESA -------------");
                
                Utils::printColorNoLine(Efeitos::bold_bright, "CONTA: ");
                std::cin >> conta;

                Utils::printColorNoLine(Efeitos::bold_bright, "ID: ");
                std::cin >> id_transacao;
                Barricada::validarID(id_transacao);

                try {
                    gc.removerDespesa(conta, id_transacao);
                    Utils::printColor(Foreground::f_green, "DESPESA REMOVIDA ✔️");
                }
                catch (ctrexcp::ContaNaoEncontrada& e) {
                    Utils::printColor(Foreground::f_red, e.what());
                    Utils::printColorNoLine(Foreground::f_red, "CARTEIRA: ");
                    std::cout << e.getNome() << std::endl;
                }
                catch (trsexcp::TransacaoNaoEncontrada& e) {
                    Utils::printColor(Foreground::f_red, e.what());
                    Utils::printColorNoLine(Foreground::f_red, "ID TRANSAÇÃO: ");
                    std::cout << e.getID() << std::endl;
                }
                catch (trsexcp::TipoTransacaoInvalido& e) {
                    Utils::printColor(Foreground::f_red, e.what());
                    Utils::printColorNoLine(Foreground::f_red, "TIPO DA TRANSAÇÃO: ");
                    std::cout << e.getTipo() << std::endl;
                }

                Utils::printColor(corSeparador, separador);
                std::cout << std::endl;
                printMensagem();

                continue;

            case 12: // Remover despesa cartao de credito
                Utils::printColor(corSeparador, separador);
                Utils::printColor(Efeitos::inverse, "---- REMOVER DESPESA CARTAO DE CREDITO ----");

                Utils::printColorNoLine(Efeitos::bold_bright, "CONTA: ");
                std::cin >> conta;
                
                Utils::printColorNoLine(Efeitos::bold_bright, "NOME CARTAO: ");
                std::cin >> cartao;

                Utils::printColorNoLine(Efeitos::bold_bright, "ID DA TRANSAÇÃO: ");
                std::cin >> id_transacao;
                Barricada::validarID(id_transacao);

                try {
                    gc.removerDespesaCartao(conta, cartao, id_transacao);
                    Utils::printColor(Foreground::f_green, "DESPESA CARTAO REMOVIDA ✔️");
                }
                catch (ctrexcp::ContaNaoEncontrada& e) {
                    Utils::printColor(Foreground::f_red, e.what());
                    Utils::printColorNoLine(Foreground::f_red, "CARTEIRA: ");
                    std::cout << e.getNome() << std::endl;
                }
                catch (cdcexcp::CartaoNaoEncontrado &e) {
                    Utils::printColor(Foreground::f_red, e.what());
                    Utils::printColorNoLine(Foreground::f_red, "CARTÃO: ");
                    std::cout << e.getNomeCartao() << std::endl;
                }
                catch (trsexcp::TransacaoNaoEncontrada& e) {
                    Utils::printColor(Foreground::f_red, e.what());
                    Utils::printColorNoLine(Foreground::f_red, "ID DA TRANSAÇÃO: ");
                    std::cout << e.getID() << std::endl;
                }

                Utils::printColor(corSeparador, separador);
                std::cout << std::endl;
                printMensagem();

                continue;

            case 13: // Remover transferencia
                Utils::printColor(corSeparador, separador);
                Utils::printColor(Efeitos::inverse, "---------- REMOVER TRANSFERENCIA ----------");

                Utils::printColorNoLine(Efeitos::bold_bright, "CONTA: ");
                std::cin >> conta;

                Utils::printColorNoLine(Efeitos::bold_bright, "ID DA TRANSAÇÃO: ");
                std::cin >> id_transacao;
                Barricada::validarID(id_transacao);

                try {
                    gc.removerTransferencia(conta, id_transacao);
                    Utils::printColor(Foreground::f_green, "TRANSFERENCIA REMOVIDA ✔️");
                }
                catch (trsexcp::TransacaoNaoEncontrada &e) {
                    Utils::printColor(Foreground::f_red, e.what());
                    Utils::printColorNoLine(Foreground::f_red, "ID DA TRANSFERÊNCIA: ");
                    std::cout << e.getID() << std::endl;
                }
                catch (ctrexcp::SaldoInsuficiente &e) {
                    Utils::printColor(Foreground::f_red, e.what());
                    Utils::printColorNoLine(Foreground::f_red, "SALDO NA CONTA: ");
                    std::cout << "R$ " << e.getSaldo() << std::endl;
                    Utils::printColorNoLine(Foreground::f_red, "VALOR QUE DEVE SER DEBITADO: ");
                    std::cout << "R$ " << e.getDespesa() << std::endl;
                }
                catch (trsexcp::TipoTransacaoInvalido &e) {
                    Utils::printColor(Foreground::f_red, e.what());
                    Utils::printColorNoLine(Foreground::f_red, "TIPO DA TRANSAÇÃO: ");
                    std::cout << e.getTipo() << std::endl;
                }
                catch (ctrexcp::ContaNaoEncontrada &e) {
                    Utils::printColor(Foreground::f_red, e.what());
                    Utils::printColorNoLine(Foreground::f_red, "CONTA: ");
                    std::cout << e.getNome() << std::endl;
                }

                Utils::printColor(corSeparador, separador);
                std::cout << std::endl;
                printMensagem();

                continue;

            case 14: // Remover cartao de credito
                Utils::printColor(corSeparador, separador);
                Utils::printColor(Efeitos::inverse, "-------- REMOVER CARTAO DE CREDITO --------");

                Utils::printColorNoLine(Efeitos::bold_bright, "CONTA: ");
                std::cin >> conta;

                Utils::printColorNoLine(Efeitos::bold_bright, "NOME DO CARTÃO: ");
                std::cin >> nome;

                try {
                    gc.removerCartao(conta, nome);
                    Utils::printColor(Foreground::f_green, "CARTAO DE CREDITO REMOVIDO ✔️");
                }
                catch (ctrexcp::ContaNaoEncontrada &e) {
                    Utils::printColor(Foreground::f_red, e.what());
                    Utils::printColorNoLine(Foreground::f_red, "CONTA: ");
                    std::cout << e.getNome() << std::endl;
                }
                catch (cdcexcp::CartaoNaoEncontrado &e) {
                    Utils::printColor(Foreground::f_red, e.what());
                    Utils::printColorNoLine(Foreground::f_red, "CARTÃO: ");
                    std::cout << e.getNomeCartao() << std::endl;
                }
                catch (ctrexcp::ContaNaoPermiteCartao &e) {
                    Utils::printColor(Foreground::f_red, e.what());
                    Utils::printColorNoLine(Foreground::f_red, "TIPO DA CONTA: ");
                    std::cout << e.getSubtipoConta() << std::endl;
                }

                Utils::printColor(corSeparador, separador);
                std::cout << std::endl;
                printMensagem();

                continue;

            case 15: // Pagar fatura do cartão
                Utils::printColor(corSeparador, separador);
                Utils::printColor(Efeitos::inverse, "-------------- PAGAR FATURA ---------------");

                Utils::printColorNoLine(Efeitos::bold_bright, "CONTA BANCÁRIA: ");
                std::cin >> conta;

                Utils::printColorNoLine(Efeitos::bold_bright, "CARTÃO: ");
                std::cin >> nome;

                try {
                    gc.pagarFaturaCartao(conta, nome);
                    Utils::printColor(Foreground::f_green, "FATURA DO CARTAO DE CREDITO PAGA ✔️");
                }
                catch (ctrexcp::ContaNaoEncontrada &e) {
                    Utils::printColor(Foreground::f_red, e.what());
                    Utils::printColorNoLine(Foreground::f_red, "CONTA: ");
                    std::cout << e.getNome() << std::endl;
                }
                catch (cdcexcp::CartaoNaoEncontrado &e) {
                    Utils::printColor(Foreground::f_red, e.what());
                    Utils::printColorNoLine(Foreground::f_red, "CARTÃO: ");
                    std::cout << e.getNomeCartao() << std::endl;
                }
                catch (ctrexcp::SaldoInsuficiente &e) {
                    Utils::printColor(Foreground::f_red, e.what());
                    Utils::printColorNoLine(Foreground::f_red, "SALDO NA CONTA: ");
                    std::cout << "R$ " << e.getSaldo() << std::endl;
                    Utils::printColorNoLine(Foreground::f_red, "VALOR QUE DEVE SER DEBITADO: ");
                    std::cout << "R$ " << e.getDespesa() << std::endl;
                }
                catch (ctrexcp::ContaNaoPermiteCartao &e) {
                    // Remover catch quando for possivel pagar fatura com uma carteira comum
                    Utils::printColor(Foreground::f_red, 
                            "NAO É POSSÍVEL PAGAR FATURA COM CONTA DO TIPO CARTEIRA COMUM");
                    Utils::printColorNoLine(Foreground::f_red, "TIPO DA CONTA: ");
                    std::cout << e.getSubtipoConta() << std::endl;
                }
               
                Utils::printColor(corSeparador, separador);
                std::cout << std::endl;
                printMensagem();

                continue;

            case 16: // Listar carteiras
                Utils::printColor(corSeparador, separador);
                Utils::printColor(Efeitos::inverse, "------------ LISTAR CARTEIRAS -------------");

                try {
                    gc.imprimirCarteiras();
                }
                catch (gcexcp::PerfilVazio &e) {
                    Utils::printColor(Foreground::f_red, e.what());
                }

                Utils::printColor(corSeparador, separador);
                std::cout << std::endl;
                printMensagem();

                continue;

            case 17: // Listar transacoes
                Utils::printColor(corSeparador, separador);
                Utils::printColor(Efeitos::inverse, "------------ LISTAR TRANSACOES ------------");

                Utils::printColorNoLine(Efeitos::bold_bright, "CARTEIRA: ");
                std::cin >> conta;

                Utils::printColorNoLine(Efeitos::bold_bright, "[d] despesa\n[r] receita\n[t] transferencia\n[a] todas\nTIPO: ");
                std::cin >> tipo;
                Barricada::validarTipo(tipo);

                try {
                    gc.listarTransacao(conta, tipo);
                }
                catch (ctrexcp::ContaNaoEncontrada &e) {
                    Utils::printColor(Foreground::f_red, e.what());
                    Utils::printColorNoLine(Foreground::f_red, "CONTA: ");
                    std::cout << e.getNome() << std::endl;
                }
                catch (trsexcp::TipoTransacaoInvalido &e) {
                    Utils::printColor(Foreground::f_red, e.what());
                    Utils::printColorNoLine(Foreground::f_red, "TIPO: ");
                    std::cout << e.getTipo() << std::endl;
                }

                Utils::printColor(corSeparador, separador);
                std::cout << std::endl;
                printMensagem();

                continue;

            case 18: // Listar despesas cartão de crédito
                Utils::printColor(corSeparador, separador);
                Utils::printColor(Efeitos::inverse, "---- LISTAR DESPESAS CARTÃO DE CRÉDITO ----");

                Utils::printColorNoLine(Efeitos::bold_bright, "CONTA BANCÁRIA: ");
                std::cin >> conta;

                Utils::printColorNoLine(Efeitos::bold_bright, "CARTÃO: ");
                std::cin >> nome;

                try {
                    gc.listarDespesasCartao(conta, nome);
                }
                catch (ctrexcp::ContaNaoEncontrada &e) {
                    Utils::printColor(Foreground::f_red, e.what());
                    Utils::printColorNoLine(Foreground::f_red, "CONTA: ");
                    std::cout << e.getNome() << std::endl;
                }
                catch (cdcexcp::CartaoNaoEncontrado &e) {
                    Utils::printColor(Foreground::f_red, e.what());
                    Utils::printColorNoLine(Foreground::f_red, "CARTÃO: ");
                    std::cout << e.getNomeCartao() << std::endl;
                }
                catch (ctrexcp::ContaNaoPermiteCartao &e) {
                    Utils::printColor(Foreground::f_red, e.what());
                    Utils::printColorNoLine(Foreground::f_red, "TIPO DA CONTA: ");
                    std::cout << e.getSubtipoConta() << std::endl;
                }
               
                Utils::printColor(corSeparador, separador);
                std::cout << std::endl;
                printMensagem();

                continue;

            case 19: // Sair
                break;
        }
        break;
    }

    return 0;
}

void printMenu() {
    Utils::printColor(Efeitos::inverse, "------------------- MENU ------------------");
    std::cout << "0 - Imprimir menu\n"
              << "1 - Adicionar carteira\n"
              << "2 - Adicionar carteira bancária\n"
              << "3 - Adicionar receita\n"
              << "4 - Adicionar despesa\n"
              << "5 - Adicionar despesa cartão de crédito\n"
              << "6 - Adicionar transferência\n"
              << "7 - Adicionar cartão de crédito\n"
              << "8 - Remover carteira\n"
              << "9 - Remover carteira bancária\n"
              << "10 - Remover receita\n"
              << "11 - Remover despesa\n"
              << "12 - Remover despesa cartão de crédito\n"
              << "13 - Remover transferência\n"
              << "14 - Remover cartão de crédito\n"
              << "15 - Pagar fatura de um cartão de crédito\n"
              << "16 - Listar carteiras\n"
              << "17 - Listar transações\n"
              << "18 - Listar despesas cartão de crédito\n"
              << "19 - Sair\n";
}

void printMensagem() {
    Utils::printColor(Efeitos::underline, "Retornar ao menu ou sair!");
    std::cout << "0 - Imprimir menu\n"
              << "19 - Sair\n";
}
