#include "CartaoDeCreditoExcp.hpp"
#include "CarteiraExcp.hpp"
#include "doctest.h"
#include "CarteiraBancaria.hpp"

// Variaveis do tipo despesa com o nome "aux_id" sao usadas para saber qual o ID das ultimas
// transacoes

TEST_CASE("Criar carteira com saldo inicial negativo") {
    CHECK_THROWS_AS(CarteiraBancaria("c1", -1), ctrexcp::ValorInvalido);
}

TEST_CASE("Adicionar cartao que ja existe") {
    CarteiraBancaria minha_carteira = CarteiraBancaria("c1", 10);
    minha_carteira.adicionarCartao("card1", "12345678901234", "001", "10", 10);
    CHECK_THROWS_AS(minha_carteira.adicionarCartao("card1", "1234567890123", "111", "11", 213), cdcexcp::CartaoJaExiste);
}

TEST_CASE("Remover cartao que nao existe") {
    CarteiraBancaria minha_carteira = CarteiraBancaria("c1", 10);
    minha_carteira.adicionarCartao("card1", "12345678901234", "001", "10", 10);
    CHECK_THROWS_AS(minha_carteira.removerCartao("card12"), cdcexcp::CartaoNaoEncontrado);
}

TEST_CASE("Pegar cartoes de credito") {
    CarteiraBancaria minha_carteira = CarteiraBancaria("c1", 10);
    minha_carteira.adicionarCartao("card1", "12345678901234", "001", "10", 10);
    minha_carteira.adicionarCartao("card2", "1234567890123", "002", "10", 10);
    CHECK(minha_carteira.getCartaoDeCredito("card1")->getCVV() == "001" );
}

TEST_CASE("Pegar cartao que nao existe") {
    CarteiraBancaria minha_carteira = CarteiraBancaria("c1", 10);
    minha_carteira.adicionarCartao("card1", "12345678901234", "001", "10", 10);
    minha_carteira.adicionarCartao("card2", "1234567890123", "002", "10", 10);
    CHECK_THROWS_AS(minha_carteira.getCartaoDeCredito("card100"), cdcexcp::CartaoNaoEncontrado);
}

TEST_CASE("Remover cartao") {
    CarteiraBancaria minha_carteira = CarteiraBancaria("c1", 10);
    minha_carteira.adicionarCartao("card1", "12345678901234", "001", "10", 10);
    minha_carteira.adicionarCartao("card2", "12345678901234", "001", "10", 10);
    minha_carteira.removerCartao("card1");
    CHECK(minha_carteira.getCartoes().size() == 1);
}

TEST_CASE("Adicionar despesa do cartao de credito") {
    CarteiraBancaria minha_carteira = CarteiraBancaria("c1", 0);
    minha_carteira.adicionarCartao("card1", "12345678901234", "001", "10", 100);
    minha_carteira.adicionarDespesaCartao("card1", 20, "10/10/2010", "c1");
    minha_carteira.adicionarDespesaCartao("card1", 10, "11/10/2010", "c1");
    CHECK(minha_carteira.getCartaoDeCredito("card1")->getListaDespesas().size() == 2);
}

TEST_CASE("Remover despesa do cartao de credito") {
    CarteiraBancaria minha_carteira = CarteiraBancaria("c1", 0);
    minha_carteira.adicionarCartao("card1", "12345678901234", "001", "10", 100);
    minha_carteira.adicionarDespesaCartao("card1", 20, "10/10/2010", "c1");
    minha_carteira.adicionarDespesaCartao("card1", 10, "11/10/2010", "c1");
    auto aux_id = Despesa("w1", 1, "10/10/2010", "c1");
    int ultimo_id = aux_id.getID();
    minha_carteira.removerDespesaCartao("card1", ultimo_id - 1);
    CHECK(minha_carteira.getCartaoDeCredito("card1")->getTotalDespesas() == 20);    
}

TEST_CASE("Exceder o limite do cartao de credito") {
    CarteiraBancaria minha_carteira = CarteiraBancaria("c1", 0);
    minha_carteira.adicionarCartao("card1", "12345678901234", "001", "10", 100);
    minha_carteira.adicionarDespesaCartao("card1", 20, "10/10/2010", "c1");
    minha_carteira.adicionarDespesaCartao("card1", 50, "11/10/2010", "c1");
    CHECK_THROWS_AS(minha_carteira.adicionarDespesaCartao("card1", 31, "11/10/2010", "c1"), cdcexcp::LimiteExcedido);
}

TEST_CASE("Pagar fatura do cartao de credito com saldo insuficiente") {
    CarteiraBancaria minha_carteira = CarteiraBancaria("c1", 10);
    minha_carteira.adicionarCartao("card1", "12345678901234", "001", "10", 100);
    minha_carteira.adicionarDespesaCartao("card1", 20, "10/10/2010", "c1");
    minha_carteira.adicionarDespesaCartao("card1", 30, "11/10/2010", "c1");
    CHECK_THROWS_AS(minha_carteira.pagarFatura("card1"), ctrexcp::SaldoInsuficiente);
}

TEST_CASE("Pagar fatura do cartao de credito - debitar saldo") {
    CarteiraBancaria minha_carteira = CarteiraBancaria("c1", 500);
    minha_carteira.adicionarCartao("card1", "12345678901234", "001", "10", 200);
    minha_carteira.adicionarDespesaCartao("card1", 10, "10/10/2010", "c1");
    minha_carteira.adicionarDespesaCartao("card1", 90, "11/10/2010", "c1");
    minha_carteira.pagarFatura("card1");
    CHECK(minha_carteira.getSaldoAtual() == 400);
}

TEST_CASE("Pagar fatura do cartao de credito - liberar limite do cartao") {
    CarteiraBancaria minha_carteira = CarteiraBancaria("c1", 500);
    minha_carteira.adicionarCartao("card1", "12345678901234", "001", "10", 200);
    minha_carteira.adicionarDespesaCartao("card1", 10, "10/10/2010", "c1");
    minha_carteira.adicionarDespesaCartao("card1", 90, "11/10/2010", "c1");
    minha_carteira.pagarFatura("card1");
    CHECK(minha_carteira.getCartaoDeCredito("card1")->getLimite() == 200);
}

TEST_CASE("Pagar fatura do cartao de credito - liberar lista de despesas do cartao") {
    CarteiraBancaria minha_carteira = CarteiraBancaria("c1", 500);
    minha_carteira.adicionarCartao("card1", "12345678901234", "001", "10", 200);
    minha_carteira.adicionarDespesaCartao("card1", 10, "10/10/2010", "c1");
    minha_carteira.adicionarDespesaCartao("card1", 90, "11/10/2010", "c1");
    minha_carteira.pagarFatura("card1");
    CHECK(minha_carteira.getCartaoDeCredito("card1")->getListaDespesas().size() == 0);;
}

TEST_CASE("Pagar fatura do cartao de credito - mover lista de despesas para a carteira") {
    CarteiraBancaria minha_carteira = CarteiraBancaria("c1", 500);
    minha_carteira.adicionarCartao("card1", "12345678901234", "001", "10", 200);
    minha_carteira.adicionarDespesa(1, "10/10/2010", "c1");
    minha_carteira.adicionarDespesaCartao("card1", 10, "10/10/2010", "c1");
    minha_carteira.adicionarDespesaCartao("card1", 90, "11/10/2010", "c1");
    minha_carteira.pagarFatura("card1");
    CHECK(minha_carteira.getTransacoes().size() == 3);
}

TEST_CASE("OUTPUT - informacoes da CarteiraBancaria") {
    CarteiraBancaria minha_carteira = CarteiraBancaria("c1", 100);
    minha_carteira.adicionarCartao("card1", "12345678901234", "001", "10", 200);
    minha_carteira.adicionarDespesa(1, "10/10/2010", "c1");
    minha_carteira.adicionarDespesaCartao("card1", 10, "10/10/2010", "c1");
    minha_carteira.adicionarDespesaCartao("card1", 90, "11/10/2010", "c1");
    minha_carteira.imprimirInfo();

    SUBCASE("Saldo menor ou igual a zero") {
        minha_carteira.adicionarDespesa(99, "10/10/2010", "c1");
        minha_carteira.imprimirInfo();
    }
}
