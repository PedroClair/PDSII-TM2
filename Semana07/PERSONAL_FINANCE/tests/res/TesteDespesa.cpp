#include "doctest.h"
#include "Despesa.hpp"

#define BIG_NUMBER 1000000000000000000

TEST_CASE("Criar despesa com valor negativo") {
    CHECK_THROWS_AS(Despesa("w1", -1, "10/10/2010", "c1"), ctrexcp::ValorInvalido);
}

TEST_CASE("Criar despesa com valor maior que o PIB mundial") {
    CHECK_THROWS_AS(Despesa("w1", BIG_NUMBER, "10/10/2010", "c1"), ctrexcp::ValorInvalido);
}

TEST_CASE("Criar despesa com uma data invalida") {
    CHECK_THROWS_AS(Despesa("w1", 10, "31/11/2010", "c1"), trsexcp::DataInvalida);
}

TEST_CASE("Alterar carteira") {
    Despesa d1 = Despesa("w1", 10, "10/10/2010", "c1");
    d1.alterarCarteira("w2");
    CHECK(d1.getCarteira() == "w2");
}
