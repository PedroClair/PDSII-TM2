#include "doctest.h"
#include "CartaoDeCredito.hpp"

#define BIG_NUMBER 1000000000000000000

// Variaveis do tipo despesa com o nome "aux_id" sao usadas para saber qual o ID das ultimas
// transacoes

TEST_CASE("Limite disponível após remover despesa") {
    CartaoDeCredito card1("b1", "12345678901234", "001", "10", 100);
    card1.adicionarDespesa(10, "10/11/1999", "padaria");
    card1.adicionarDespesa(20, "10/11/1999", "padaria");
    auto aux_id = Despesa("w1", 1, "10/10/2010", "c1");
    int ultimo_id = aux_id.getID();
    card1.removerDespesa(ultimo_id - 1);
    CHECK(card1.getLimite() - card1.getTotalDespesas() == 90);
}

TEST_CASE("Criar cartão com limite negativo") {
    CHECK_THROWS_AS(CartaoDeCredito card1("c1", "12345678901234", "001", "10", -10), ctrexcp::ValorInvalido);
}

TEST_CASE("Criar cartão com limite maior que o PIB mundial") {
    CHECK_THROWS_AS(CartaoDeCredito card1("c1", "12345678901234", "001", "10", BIG_NUMBER), ctrexcp::ValorInvalido);
}

TEST_CASE("Criar cartão com numero invalido (< 13 ou > 16 caracteres)") {
    CHECK_THROWS_AS(CartaoDeCredito card1("c1", "12345678901234567", "001", "10", 10), cdcexcp::NumeroInvalido);
}

TEST_CASE("Criar cartão com dia de fechamento invalido)") {
    CHECK_THROWS_AS(CartaoDeCredito card1("c1", "12345678901234", "001", "32", 10), cdcexcp::FechamentoInvalido);
}

TEST_CASE("Criar cartão com CVV invalido)") {
    CHECK_THROWS_AS(CartaoDeCredito card1("c1", "12345678901234", "02", "30", 10), cdcexcp::CVVInvalido);
}

TEST_CASE("Pegar nome do cartao") {
    CartaoDeCredito card1("b1", "12345678901234", "001", "10", 100);
    CHECK(card1.getNome() == "b1");
}

TEST_CASE("Pegar numero do cartao") {
    CartaoDeCredito card1("b1", "12345678901234", "001", "10", 100);
    CHECK(card1.getNumero() == "12345678901234");
}

TEST_CASE("Pegar CVV do cartao") {
    CartaoDeCredito card1("b1", "12345678901234", "001", "10", 100);
    CHECK(card1.getCVV() == "001");
}

TEST_CASE("Pegar fechamento do cartao") {
    CartaoDeCredito card1("b1", "12345678901234", "001", "10", 100);
    CHECK(card1.getFechamento() == "10");
}

TEST_CASE("Alterar limite") {
    CartaoDeCredito card1("c1", "12345678901234", "001", "12", 1);
    card1.alterarLimiteCartao(1000);
    CHECK(card1.getLimite() == 1000);
}

TEST_CASE("Alterar limite para valor negativo") {
    CartaoDeCredito card1("c1", "12345678901234", "001", "12", 1);
    CHECK_THROWS_AS(card1.alterarLimiteCartao(-1), ctrexcp::ValorInvalido);
}

TEST_CASE("Remover despesa não registrada") {
    CartaoDeCredito card1("c1", "12345678901234", "001", "10", 100);
    CHECK_THROWS_AS(card1.removerDespesa(99), trsexcp::TransacaoNaoEncontrada);
}

TEST_CASE("Somatorio despesas") {
    CartaoDeCredito card1("b1", "12345678901234", "001", "10", 100);
    card1.adicionarDespesa(10, "10/11/1999", "padaria");
    card1.adicionarDespesa(15, "10/11/1999", "padaria");
    card1.adicionarDespesa(1.5, "10/11/1999", "padaria");
    CHECK(card1.getTotalDespesas() == 26.5);
}

TEST_CASE("Adicionar despesa com valor superior ao limite do cartão") {
    CartaoDeCredito card1("b1", "12345678901234", "001", "10", 10);
    CHECK_THROWS_AS(card1.adicionarDespesa(11, "10/11/1999", "padaria"), cdcexcp::LimiteExcedido);
}

TEST_CASE("Adicionar despesa com valor negativo") {
    CartaoDeCredito card1("b1", "12345678901234", "001", "10", 10);
    CHECK_THROWS_AS(card1.adicionarDespesa(-5, "01/12/2001", "padaria"), ctrexcp::ValorInvalido);
}

TEST_CASE("Pegar lista de despesas") {
    CartaoDeCredito card1("b1", "12345678901234", "001", "10", 100);
    card1.adicionarDespesa(13, "10/11/1999", "padaria");
    card1.adicionarDespesa(15, "10/11/1999", "padaria");
    card1.adicionarDespesa(1.512, "10/11/1999", "padaria");
    auto lista = card1.getListaDespesas();
    CHECK(lista.size() == 3);
}

TEST_CASE("OUTPUT - impressao das info do cartao + lista de despesas") {
    CartaoDeCredito card1("b1", "12345678901234", "001", "10", 100);
    card1.adicionarDespesa(5, "10/11/1999", "padaria");
    card1.adicionarDespesa(15, "10/11/1999", "padaria");
    card1.listarDespesas();
    
    SUBCASE("Limite zerado") {
        card1.adicionarDespesa(80, "10/10/2010", "c1");
        card1.listarDespesas();
    }
}
