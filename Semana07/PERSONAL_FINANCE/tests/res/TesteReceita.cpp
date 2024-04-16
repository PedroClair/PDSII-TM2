#include "TransacaoExcp.hpp"
#include "doctest.h"
#include "Receita.hpp"

#define BIG_NUMBER 1000000000000000000

TEST_CASE("Criar receita com valor negativo") {
   CHECK_THROWS_AS(Receita("w1", -1, "10/10/2010", "c1"), ctrexcp::ValorInvalido);
}

TEST_CASE("Criar receita com valor maior do que o PIB mundial") {
   CHECK_THROWS_AS(Receita("w1", BIG_NUMBER, "10/10/2010", "c1"), ctrexcp::ValorInvalido);
}

TEST_CASE("Criar receita com data invalida") {
   CHECK_THROWS_AS(Receita("w1", 100, "31/11/2010", "c1"), trsexcp::DataInvalida);
}

TEST_CASE("Modificar carteira") {
    Receita r1 = Receita("w1", 10, "10/10/2010", "c1");
    r1.alterarCarteira("w2");
    CHECK(r1.getCarteira() == "w2");
}

TEST_CASE("OUTPUT - imprimir informacoes da receita") {
    Receita r1 = Receita("Carteira", 10, "10/10/2010", "c1");
    r1.imprimirInfo();
}
